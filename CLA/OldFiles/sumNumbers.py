#Tyler Sabin
#October 3, 2023
#Section 006

num = int(input("Enter a positive number (negative to quit): "))
total = 0

while num > 0:
    total += num
    num = int(input("Enter a positive number (negative to quit): "))

print(f'Total = {total:.2f}')