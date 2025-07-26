#Tyler Sabin
#Section 006
#October 5, 2023

nums = int(input("Enter numbers: "))
maxValue = 0
occurence = 0

while nums != 0:
    if nums > maxValue:
        maxValue = nums
        nums = int(input("Enter numbers: "))
        occurence = 0
        occurence =+ 1
    elif nums == maxValue:
        occurence += 1
        nums = int(input("Enter numbers: "))
    else:
        nums = int(input("Enter numbers: "))
print(f'The largest number is {maxValue}')
print(f'The occurrence count of the largest number is {occurence}')