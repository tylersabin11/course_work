#Tyler Sabin
#Section 006
#October 5, 2023

for i in range(9):
    for k in range(i):
        print('z',end='')
    for j in range(9-i):
        print(' ',end='')
    print()
for i in range(9):
    for k in range(9-i):
        print('z',end='')
    for j in range(i):
        print(' ',end='')
    print()

for i in range(9):
    for k in range(9-i):
        print(' ',end='')
    for j in range(i):
        print('z',end='')
    print()
for i in range(9):
    for k in range(i):
        print(' ',end='')
    for j in range(9-i):
        print('z',end='')
    print()