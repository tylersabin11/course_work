averageFile = open('Student.txt','r')
name = averageFile.readline()
while name != '':
    score1 = float(averageFile.readline())
    score2 = float(averageFile.readline())
    score3 = float(averageFile.readline())
    score4 = float(averageFile.readline())
    print(f'{name} scores: {score1:.2f} {score2:.2f} {score3:.2f} {score4:.2f}')
    name = averageFile.readline()