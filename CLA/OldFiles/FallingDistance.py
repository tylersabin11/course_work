#Tyler Sabin
#October 12, 2023
#Section 006

def falling_distance(secs):
    g = 9.8
    distance = (1/2) * (g * (secs ** 2))
    return distance
print('Time','Falling Distance',sep='\t')
print('----------------------------')

def main():
    for num in range(1,11):
        total = falling_distance(num)
        print(f'{num:<10}{total:>5.2f}')

main()