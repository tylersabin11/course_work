#Tyler Sabin
#CSCI 1170-006
#OLA-1
#This program will inform the user of the ending dollar amount
#based off of their initial payment, rate, times compounded,
#and length of investment

#def is used to define a function, main
def main():
    #Get the input for each of the requested items for the formula 
    principal = int(input("Enter the starting principal: "))
    interestRate = float(input("Enter the annual interest rate: "))
    interestCompound = int(input("How many times per year is the interest compunded? "))
    investmentLength = int(input("For how many years will the account ear interest? "))

    #Convert the the integer input into a decimal form to accurately represent the rate
    apr = (interestRate / 100)

    #Use the given formula to calculate the ending amount for the user
    endingAmount = (principal) * ((1 + (apr / interestCompound)) ** (interestCompound * investmentLength))

    #Output the requested information for the user to show for the ending amount
    print(f'At the end of 10 years, you will have $ {endingAmount:,.2f}')

#call the main function
main()