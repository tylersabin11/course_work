#Tyler Sabin
#Section 006
#November 9, 2023
try:
    file = open('steps.txt','r')
except IOError:
        print("File had issues opening, or reading the file")

def main():
    try:
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
    except ValueError:
        print("Issue occurred with the file's numeric contents")
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