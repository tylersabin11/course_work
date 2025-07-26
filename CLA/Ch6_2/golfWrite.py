#Tyler Sabin
#November 2, 2023
#Section 006

def main():
    myfile = open('golf.txt','w')
    
    numPlayer = int(input("Enter the number of players in the tournament: "))

    for i in range(1,numPlayer+1):
        name = input("Enter the name of the player: ")
        score = int(input("Enter the golf score: "))
        myfile.write(name + '\n')
        myfile.write(str(score) + '\n')

    myfile.close()

main()