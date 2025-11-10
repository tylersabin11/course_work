from langchain_community.tools import WikipediaQueryRun, DuckDuckGoSearchRun
from langchain_community.utilities import WikipediaAPIWrapper
from langchain_community.tools import Tool
from datetime import datetime

#Function to save result to a .txt file
def save_to_txt(data: str, filename: str = "research_output.txt"):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    formatted_text = f"--- Research Output ---\nTimestamp: {timestamp}\n\n{data}\n\n"

    with open(filename, "a", encoding="utf-8") as f:
        f.write(formatted_text)
    
    return f"Data successfully saved to {filename}"

save_tool = Tool(
    name="save_text_to_file",
    func=save_to_txt,
    description="Saves structured research data to a text file"
)

#Access DuckDuckGo
search = DuckDuckGoSearchRun()
search_tool = Tool(
    name="search_web",
    func=search.run,
    #Can be more specific if we only want it used in a certain scenario
    description="Search the web for information"
)

#Can change 1 to any number of results
#Max chars set to 100 for limiting issues and runtime
api_wrapper = WikipediaAPIWrapper(top_k_results=1, doc_content_chars_max=100)
wiki_tool = WikipediaAPIWrapper(api_wrapper=api_wrapper)
