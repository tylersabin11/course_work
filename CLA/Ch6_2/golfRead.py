#Tyler Sabin
#November 2, 2023
#Section 006

def main():
    myfile = open('golf.txt','r')
    
    bestScore = 1000
    bestPlayer = ''

    name = myfile.readline()
    while name != '':
        score = myfile.readline()
        golfScore = int(score)
        if golfScore < bestScore:
            bestScore = golfScore
            bestPlayer = name
        name = name.rstrip('\n')
        print(f'Name: {name}')
        print(f'Golf Score: {golfScore}')
        name = myfile.readline()
        
    bestPlayer = bestPlayer.rstrip('\n')
    
    myfile.close()


    
    print(f'Winner is: {bestPlayer}, with {bestScore}')

main()  