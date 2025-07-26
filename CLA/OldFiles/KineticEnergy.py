#Tyler Sabin
#October 12, 2023
#Section 006

def kinetic_energy(mass,velocity):
    ke = (1/2) * (mass * (velocity ** 2))
    return ke

def main():
    m = int(input("Enter the mass of the object in kilograms: "))
    v = int(input("Enter the object velocity in meters per second: "))
    joules = kinetic_energy(m,v)
    print(f'Kinetic Energy is: {joules:.2f} joules')

main()