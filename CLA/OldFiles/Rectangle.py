#Tyler Sabin
#Section 006
#September 19 2023

#Get the input for rec1
len1 = float(input("Enter length of rectangle1: "))
width1 = float(input("Enter width of rectangle1: "))
rec1 = len1 * width1

#Get the input for rec2
len2 = float(input("Enter length of rectangle2: "))
width2 = float(input("Enter width of rectangle2: "))
rec2 = len2 * width2

#Print the areas
print(f'Area of rectangle1 is {rec1:.2f}')
print(f'Area of rectangle2 is {rec2:.2f}')

if rec1 > rec2:
    print("Area of rectangle1 is greater than area of rectangle2.")
else:
    print("Area of rectangle1 could either be less than or equal to area of rectangle2.")