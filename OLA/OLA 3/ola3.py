#Tyler Sabin
#Section 006
#September 30, 2023
#This program will take an input of amount of students, names, and grades to calculate each student's Grade as a letter, and print out high/low grades of the class and the class average
#The purpose of this assignment is to have us students become comfortable working with while loops and more complex algorithms

#Get the input for the amount of students
studentCount = int(input("Enter the number of students in the class: "))
#Intialize the variables so we can store certain values (low/high names and scores, amount failed, and total grades combined so we can calculate the avg
highestGradeName = ""
highestGrade = 0
lowestGradeName = ""
lowestGrade = 100
failedGrade = 0
gradeSum = 0

#Intialize the count for our while loop
count = 1

#Our while loop will continue until our count is no longer less than, or equal to the number of students

while count <= studentCount:
    studentName = input("Enter student name: ")
    studentGrade = int(input("Enter student score (0-100): "))
    
    #This if statement will check to see if the grade entered is between the range given, if so, it will assign the correct grade in the print statement
    
    if studentGrade >= 90 and studentGrade <= 100:
        print(f'Grade for {studentName}: A')
        
        #This if statement will check to see if the grade entered is higher than the highest score stored
        
        if studentGrade > highestGrade:
            
            #If so, the students name will be be stored along with their grade in the assigned variables initialized at the beggining of our program
            
            highestGrade = studentGrade
            highestGradeName = studentName
            gradeSum += studentGrade
            count += 1
        else:
            
            #If the grade is not higher, it will check to see if it is lower than the lowest score and apply the same steps as above
            
            if studentGrade < lowestGrade:
                lowestGrade = studentGrade
                lowestGradeName = studentName
                gradeSum += studentGrade
                count += 1
            else:
                
                #If the grade is not higher, nor lower, it will add the grade to the grade sum, and add 1 to our count
                
                gradeSum += studentGrade
                count += 1
    else:
        
        #We will continue to iterate through the rest of the if's and else's until the proper section correlates with the student's grade
        
        if studentGrade >= 80 and studentGrade < 90:
            print(f'Grade for {studentName}: B')
            if studentGrade > highestGrade:
                highestGrade = studentGrade
                highestGradeName = studentName
                gradeSum += studentGrade
                count += 1
            else:
                if studentGrade < lowestGrade:
                    lowestGrade = studentGrade
                    lowestGradeName = studentName
                    gradeSum += studentGrade
                    count += 1
                else:
                    gradeSum += studentGrade
                    count += 1
        else:
            if studentGrade >= 70 and studentGrade < 80:
                print(f'Grade for {studentName}: C')
                if studentGrade > highestGrade:
                    highestGrade = studentGrade
                    highestGradeName = studentName
                    gradeSum += studentGrade
                    count += 1
                else:
                    if studentGrade < lowestGrade:
                        lowestGrade = studentGrade
                        lowestGradeName = studentName
                        gradeSum += studentGrade
                        count += 1
                    else:
                        gradeSum += studentGrade
                        count += 1
            else: 
                if studentGrade >= 60 and studentGrade < 70:
                    print(f'Grade for {studentName}: D')
                    if studentGrade > highestGrade:
                        highestGrade = studentGrade
                        highestGradeName = studentName
                        gradeSum += studentGrade
                        count += 1
                    else:
                        if studentGrade < lowestGrade:
                            lowestGrade = studentGrade
                            lowestGradeName = studentName
                            gradeSum += studentGrade
                            count += 1
                        else:
                            gradeSum += studentGrade
                            count += 1
                else:
                    
                    #Here, we now know that the student's grade must be an F, we will still check to see if the student has the highest or lowest grade because it is possible that all students have F's
                    
                    print(f'Grade for {studentName}: F')
                    if studentGrade > highestGrade:
                        highestGrade = studentGrade
                        highestGradeName = studentName
                        failedGrade += 1
                        gradeSum += studentGrade
                        count += 1
                    else:
                        if studentGrade < lowestGrade:
                            lowestGrade = studentGrade
                            lowestGradeName = studentName
                            failedGrade += 1
                            gradeSum += studentGrade
                            count += 1
                        else:
                            
                            #if the student does not have the highest grade or lowest grade, we must add one to our failed student counter
                            
                            failedGrade += 1
                            gradeSum += studentGrade
                            count += 1


#Calculate the average

classAvg = (gradeSum / studentCount)

#Print the stats out

print("\nClass Statistics:")
print(f'Class Average: {classAvg:.2f}')
print(f'Highest Score: {highestGradeName} ({highestGrade})')
print(f'Lowest Score: {lowestGradeName} ({lowestGrade})')
print(f'Number of Students Who Failed: {failedGrade}')