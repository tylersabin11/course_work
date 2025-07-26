#Tyler Sabin
#Section 006
#October 26, 2023

def main():
    num = int(input("Enter an integer"))
    if is_prime(num) == False:
        print("not prime")
    else:
        print("prime")

def is_prime(int):
    for i in range(int-1,1,-1):
        if int % i == 0:
            return False

if __name__ == "__main__":
    main()