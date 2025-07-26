#Tyler Sabin
#Section 006
#Septemeber 26th 2023
#This program will take an int input and convert it to a Roman Numeral

#Get the input for the num
num = int(input("Enter an integer from 1 -10: "))

#check to see if the num is out of the valid range
if num < 0 or num > 10:
    print("Error: Invalid Number")
#if the num is valid, iterate through the if's to find the correct Roman numeral
else:
    if num == 1:
        print("I")
    elif num == 2:
        print("II")
    elif num == 3:
        print("III")
    elif num == 4:
        print("IV")
    elif num == 5:
        print("V")
    elif num == 6:
        print("VI")
    elif num == 7:
        print("VII")
    elif num == 8:
        print("VIII")
    elif num == 9:
        print("IX")
    else:
        print("X")