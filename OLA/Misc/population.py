#Tyler Sabin
#Section 006
#Dec 5, 2023

def main():
    file = open('pop_data.txt','r')
    population = file.readlines()
    file.close()

    index = 0
    while index < len(population):
        population[index] = int(population[index])
        index += 1

    print(f'The average annual change in population during the time period is {calc_avg(population):.2f}')
    print(f'The max change in population was {calc_max(population)}')
    print(f'The min change in population was {calc_min(population)}')


def calc_avg(list):
    total = 0
    count = 0
    for index in range(1,len(list)):
        change = (list[index] - list[index - 1])
        total += change
        count += 1
        change = 0
    return(total / count)

def calc_max(list):
    maxYear = 0
    maxChange = 0
    startYear = 1950
    for index in range(1,len(list)):
        change = (list[index] - list[index - 1])
        if change > maxChange:
            maxChange = change
            maxYear = startYear
        startYear += 1

    return(maxYear + 1)

def calc_min(list):
    minYear = 0
    minChange = 10000000
    startYear = 1950
    for index in range(1,len(list)):
        change = (list[index] - list[index - 1])
        if change < minChange:
            mminChange = change
            minYear = startYear
        startYear += 1

    return(minYear + 1)
            
main()