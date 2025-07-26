#Tyler Sabin
#CSCI 1170 Section 006
#Due date: 11/14/2023
#OLA 5, Nov. 10, 2023
#This program takes an input file name from the user, validates it, and will calc the average and output a .csv file 
#With the names, averages, total number of students, and number of pass/fail

def main():
    try:
        fileName = input("Please enter the scores filename: ")
        print(f'You entered {fileName}')
        avgFile = open(fileName,'r')
        print(f'Opened scores file {fileName}')
    except IOError:
        print('File failed to open.')

    tempFileCSV = 'averages.csv'
    tempFile = open(tempFileCSV,'w')

    passNum = 0
    failNum = 0
    totalNum = 0

    #This while loop will itterate through the file until it reaches ' '
    #It will read each name, and scores for each name, then convert the score to a float
    #The name & average will be written to the Temp file
    
    name = avgFile.readline()
    while name != '':
        score1 = float(avgFile.readline())
        score2 = float(avgFile.readline())
        score3 = float(avgFile.readline())
        score4 = float(avgFile.readline())
        average = (score1 + score2 + score3 + score4) / 4
        name = name.rstrip('\n')
        print(f'{name} scores: {score1:.2f} {score2:.2f} {score3:.2f} {score4:.2f} average: {average:.2f}')
        average = str(average)
        tempFile.write(f'{name} , {average}' + '\n')
        average = float(average)
        if average > 60:
            passNum += 1
        else:
            failNum += 1
        totalNum += 1
        name = avgFile.readline()
    
    avgFile.close()

    passNum = str(passNum)
    failNum = str(failNum)
    totalNum = str(totalNum)

    tempFile.write(f'Total number: {totalNum}' + '\n')
    tempFile.write(f'Passed: {passNum}' + '\n')
    tempFile.write(f'Failed: {failNum}' + '\n')

    tempFile.close()

main()