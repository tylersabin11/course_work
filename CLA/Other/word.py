#Tyler Sabin
#Section 006
#Nov. 16, 2023

def main():
    myStr = input("Enter a string: ")
    #myStr='CanYouSeeThis'
    new_str=myStr[0]
    for index in range(1,len(myStr)):
        if myStr[index].isupper():
            new_str+=' '+myStr[index].lower()
        else:
            new_str+=myStr[index]
    print(new_str)
main()   