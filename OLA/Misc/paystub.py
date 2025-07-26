def main():
    fileName = input("Enter file name: ")
    inFile = open(fileName,'r')
    paystub1 = inFile.readline()
    while paystub1 != '':
        paystub1 = int(paystub1)
        paystub2 = int(inFile.readline())
        paystub3 = int(inFile.readline())
        freq = int(inFile.readline())
        AMI = calc_AMI(paystub1,paystub2,paystub3,freq)
        rentLimit = calc_RentLimit(AMI)
        print(f'Rent limit is {rentLimit:.0f}')
        paystub1 = inFile.readline()



def calc_AMI(paystub1,paystub2,paystub3,freq):
    if freq == 1:
        avgPay = (paystub1 + paystub2 + paystub3) / 3
        AMI = (avgPay * 52) / 12
        return AMI
    elif freq == 2:
        avgPay = (paystub1 + paystub2 + paystub3) / 6
        AMI = (avgPay * 52) / 12
    elif freq == 3:
        avgPay = (paystub1 + paystub2 + paystub3) / 1.5
        return avgPay
    else:
        avgPay = (paystub1 + paystub2 + paystub3) / 3
        return avgPay
    

def calc_RentLimit(ami):
    rentLimit = ami / 2.5
    return rentLimit

main()