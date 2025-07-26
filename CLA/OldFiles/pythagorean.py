#Tyler Sabin
#October 10, 2023
#Section 006
#CLA4_5
#This program will print all triples up to a hypo. of 30. It will also ensure that there are no duplicates

hyp = 2
hypMax = 30
side1 = 1
side2 = 1
hyp2 = 1

print('Hyp','Side 1','Side 2',sep='\t')

for hyp in range(2,hypMax):
    for side1 in range(1,hypMax):
        for side2 in range(1,hypMax):
            if ((side1 ** 2) + (side2 ** 2)) == (hyp ** 2) and side1 < side2:
                    print(hyp,side1,side2,sep='\t')