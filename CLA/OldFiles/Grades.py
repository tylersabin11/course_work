#Tyler Sabin
#Section 006
#Septemeber 21st 2023
#This program will take an integer input and decide whether the input is valid, pass, fail, or good

#Get the input grade from the user
grade = int(input("Enter a score (0 to 100):"))

#Variables for pass & good grade
goodGrade = 73
passGrade = 60

#Check to see if the value is less than 0, or more than 100
if grade < 0 or grade > 100:
    print(f'{grade} is an invalid number.')
    print("The number should be between 0 and 100 inclusive.")
#The number is valid, now it will check to see if it is within the good, pass, or fail category
else:
    if grade >= goodGrade:
          print(f'{grade} is Good.')
    elif grade >= passGrade:
          print(f'{grade} is Pass.')
    else:
          print(f'{grade} is Fail')
