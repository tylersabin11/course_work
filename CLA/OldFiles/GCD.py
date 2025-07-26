#Tyler Sabin
#October 19, 2023
#Section 006
#the prog

def main():
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter Second number: "))
    GCD = gcd(num1,num2)
    print(f'GCD for {num1} and {num2} is: {GCD}')

def gcd(num_1,num_2):
    gcd = 1
    numMax = 0
    if num_1 < num_2:
        numMax = num_2
    elif num_1 > num_2:
        numMax = num_1
    else:
        numLow = num_1
    for i in range(1,numMax+1):
        if num_1 % i == 0 and num_2 % i == 0:
            if i > gcd:
                gcd = i
    return gcd

main()