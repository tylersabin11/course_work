#Tyler Sabin
#Section 006
#November 7, 2023

file = open('steps.txt','r')

def main():
    print(f'The average steps taken in January was {calc(file,31):.1f}')
    print(f'The average steps taken in February was {calc(file,28):.1f}')
    print(f'The average steps taken in March was {calc(file,31):.1f}')
    print(f'The average steps taken in April was {calc(file,30):.1f}')
    print(f'The average steps taken in May was {calc(file,31):.1f}')
    print(f'The average steps taken in June was {calc(file,30):.1f}')
    print(f'The average steps taken in July was {calc(file,31):.1f}')
    print(f'The average steps taken in August was {calc(file,31):.1f}')
    print(f'The average steps taken in September was {calc(file,30):.1f}')
    print(f'The average steps taken in October was {calc(file,31):.1f}')
    print(f'The average steps taken in November was {calc(file,30):.1f}')
    print(f'The average steps taken in December was {calc(file,31):.1f}')
    file.close()

def calc(file,days):
    sum = 0
    count = 0
    for i in range(days):
        line = file.readline()
        steps = int(line)
        sum += steps
        count += 1
    average = (sum / count)
    return average

main()