#CLA 5 Exercise 2
#Tyler Sabin
#Septemeber 12 2023

salesTax = .07
tip = .18

meal = float(input("Enter the charge for food: "))

#Calc amount for the tip & tax
totalTax = meal * salesTax
totalTip = meal * tip

#Calc total for the meal
mealTotal = meal + totalTax + totalTip

print(f'Tip: ${totalTip:.2f}')
print(f'Tax: ${totalTax:.2f}')
print(f'Total: ${mealTotal:.2f}')