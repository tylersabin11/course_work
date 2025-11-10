#Import packages
#Main logic to be store in main.py

from dotenv import load_dotenv
from pydantic import BaseModel
from langchain_openai import ChatOpenAI
from langchain_core.prompts import ChatPropmtTemplate
from langchain_core.output_parsers import PydanticOutputParser
from langchain.agents import create_tool_calling_agent, AgentExecutor
from tools import search_tool, wiki_tool, save_tool

load_dotenv()

class ResearchResponse(BaseModel):
    topic: str
    summary: str
    sources: list[str]
    tools_used: list[str]

#GPT model
llm = ChatOpenAI(model="gpt-5")

#Create Parser
parser = PydanticOutputParser(pydantic_object=ResearchResponse)

#Prompt template
prompt = ChatPropmtTemplate.from_messages(
    [
        (
            #Information to the LLM to tell the model what it is doing
            "system",
            """
            You are a research assistant that will help generate a research paper.
            Answer the user query and use neccessary tools. 
            Wrap the output in this format and provide no other text\n{format_instructions}
            """,
        ),
        ("placeholder", "{chat_history}"),
        #Comes from user
        ("human", "{query}"),
        ("placeholder", "{agent_scratchpad}"),
    ]
#Partially fill in the prompt with the format instructions
).partial(format_instructions=parser.get_format_instructions())

#add in DuckDuckGo and Wiki search tool, also pass in the save_tool so we receive the data in a .txt file
tools = [search_tool, wiki_tool, save_tool]
#Create the agent
agent = create_tool_calling_agent(
    llm=llm,
    prompt=prompt,
    tools=tools
)

#Verbose is for the reasoning of the agent
agent_executor = AgentExecutor(agent=agent, tools=[], verbose=True)
query = input("What can I help you research?")
raw_response = agent_executor.invoke({"query": query})

#Error catcher
try:
    #Structure the response to get the correct output
    #We can also select from the Class on which piece we want to print
    structured_response = parser.parse(raw_response.get("output")[0]["text"])
    print(structured_response)
except Exception as e:
    print("Error parsing response", e, "Raw Response - ", raw_response)
