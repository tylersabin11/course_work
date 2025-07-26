#Tyler Sabin 
#Section 006
#Nov 28, 2023

def main():
    engSent = input("Enter a sentence: ")
    list = engSent.split(' ')
    pigLatin = ''
    for index in range(len(list)):
        tempList = list[index]
        pigLatin += tempList[1:] + tempList[0] + 'AY' + ' '

    print(pigLatin)
    
main()