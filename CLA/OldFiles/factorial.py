#Tyler Sabin
#October 10, 2023
#Section 006
#CLA4_5
#This program will take an int input and print the num's factorial with a for & while loop

num = int(input("Enter a non-negative integer: "))
total = 1
total2 = 1

for i in range(1,num+1):
    total *= i
    
print(f'The factorial value using for loop is equal {total}')

while num > 0:
    total2 *= num
    num -= 1
    
print(f'Factorial value using while loop is equal {total2}')