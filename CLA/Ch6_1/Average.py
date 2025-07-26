#Tyler Sabin
#October 31, 2023
#Section 006

def main():
    numFile = open('numbers.txt','r')

    #Read the lines within the file
    file_nums = numFile.readline()

    #Set variables for the total of the nums, and the number of lines
    total = 0
    numLines = 0

    #When the line is not blank, stay within the while loop to calculate the num of lines and total
    while file_nums != "":
        numLines += 1
        nums = int(file_nums)
        total += nums
        file_nums = numFile.readline()
    
    #Calculate the average and close the file
    averageNum = total / numLines
    numFile.close()

    #Print out the average from the stored memory
    print(f'{averageNum:.2f}')

#Call the main function
main()