#Tyler Sabin
#Section 006
#Septemeber 26th 2023
#This program will calculate the person's BMI based off of their weight and height

#Get the input for height and weight
weight = int(input("Enter your weight in pounds: "))
height = int(input("Enter your height in inches: "))

#Calc the BMI
BMI = ( weight * 703 ) / (height ** 2 )

#Iterate through the if's to see where the person's BMI is
if BMI > 25:
    print(f'Your Body Mass Indicator is {BMI:.2f}')
    print("You are overweight.")
elif BMI >= 18.5 and BMI <= 25:
    print(f'Your Body Mass Indicator is {BMI:.2f}')
    print("Your weight is optimal.")
else:
    print(f'Your Body Mass Indicator is {BMI:.2f}')