#Tyler Sabin
#Section 006
#October 24, 2023

import random as rd
num1=1
num2=100
def main():
    num = random_int()
    guess = int(input("Enter a number between 1 and 100, or 0 to quit: "))
    while guess != 0:
        if guess > num:
            print("Too high, try again")
        elif guess < num:
            print("Too low, try again")
        else:
            print("Congratulations! You guessed the right number!")
        guess = int(input("Enter a number between 1 and 100, or 0 to quit: "))
        
        
def random_int():
    number = rd.randint(num1,num2)
    return number


main()
