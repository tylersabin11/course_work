filingStatus = int(input("Enter the filing status: "))
taxableIncome = int(input("Enter the taxable income: "))

#Tax rates for each pay grade
tax1 = .1
tax2 = .15
tax3 = .25
tax4 = .28
tax5 = .33
tax6 = .35

#Pay ranges for each bracket (Single filing)
sin1 = 8350
sin2low = 8350
sin2high = 33950
sin3low = 33950
sin3high = 85250
sin4low = 85250 
sin4high = 171550
sin5low = 171550
sin5high = 372950
sin6 = 372950

#Pay ranges for each bracket (Married filing)
joint1 = 15700
joint2low = 15700
joint2high = 67900
joint3low = 67900
joint3high = 137050
joint4low = 137050
joint4high = 211850
joint5low = 211850
joint5high = 372950
joint6 = 372950

#Check to see what the filing status is
if filingStatus == 0:
    #Check to see if the taxable income amount is above the single first range
    if taxableIncome > sin1:
        #If so, taxAm1 will represent the tax amount for the high-bound of the Single range (1st bracket) and multiply the tax rate to get the amount
        taxAm1 = sin1 * tax1 
        if taxableIncome > sin2high:
            #This calculation is done because the taxable income is higher then the high-bound of the second bracket. We will take the high-bound and subtract the low bound to find the amount to be taxed and multiply it by the tax rate
            taxAm2 = (sin2high - sin2low) * tax2
            if taxableIncome > sin3high:
                #The same process will occur all the way down when the taxable income is higher then the high-bound of each bracket
                taxAm3 = (sin3high - sin3low) * tax3
                if taxableIncome > sin4high:
                    taxAm4 = (sin4high - sin4low) * tax4
                    if taxableIncome > sin5high:
                        taxAm5 = (sin5high - sin5low) * tax5
                        if taxableIncome > sin6:
                            taxAm6 = (taxableIncome - sin6) * tax6
                            totalTaxes = tax6 + tax5 + tax4 + tax3 + tax2 + tax1
                            #This will output the total taxes
                            print(f'Tax is {totalTaxes:.2f}')
                    else: 
                        #(This process is for all lines below) Since we know that the taxable income is NOT above the high bound, we subtract the taxable income from the low bound of the given bracket to find the remainder. We then multiply this remainder by the tax rate to get the amount
                        taxAm5 = (taxableIncome - sin5low) * tax5
                        totalTaxes = tax5 + tax4 + tax3 + tax2 + tax1
                        #This will output the total taxes
                        print(f'Tax is {totalTaxes:.2f}')
                else:
                    taxAm4 = (taxableIncome - sin4low) * tax4
                    totalTaxes = taxAm4 + taxAm3 + taxAm2 + taxAm1
                    print(f'Tax is {totalTaxes:.2f}')
            else: 
                taxAm3 = (taxableIncome - sin3low) * tax3
                totalTaxes = taxAm3 + taxAm2 + taxAm1
                print(f'Tax is {totalTaxes:.2f}')
        else:
            taxAm2 = (taxableIncome - sin2low) * tax2
            totalTaxes = taxAm2 + taxAm1
            print(f'Tax is {totalTaxes:.2f}')
    else:
        taxAmount = taxableIncome * tax1
        print(f'Tax is {taxAmount:.2f}')

#Since the filing status was not 0, taxes will be calculated at a joint filing status
#The same process will be followed by the pseudocode written above
else:
    if taxableIncome > joint1:
        taxAm1 = joint1 * tax1 
        if taxableIncome > joint2high:
            taxAm2 = (joint2high - joint2low) * tax2
            if taxableIncome > joint3high:
                taxAm3 = (joint3high - joint3low) * tax3
                if taxableIncome > joint4high:
                    taxAm4 = (joint4high - joint4low) * tax4
                    if taxableIncome > joint5high:
                        taxAm5 = (joint5high - joint5low) * tax5
                        if taxableIncome > joint6:
                            taxAm6 = (taxableIncome - joint6) * tax6
                            totalTaxes = tax6 + tax5 + tax4 + tax3 + tax2 + tax1
                            print(f'Tax is {totalTaxes:.2f}')
                    else: 
                        taxAm5 = (taxableIncome - joint5low) * tax5
                        totalTaxes = tax5 + tax4 + tax3 + tax2 + tax1
                        print(f'Tax is {totalTaxes:.2f}')
                else:
                    taxAm4 = (taxableIncome - joint4low) * tax4
                    totalTaxes = taxAm4 + taxAm3 + taxAm2 + taxAm1
                    print(f'Tax is {totalTaxes:.2f}')
            else: 
                taxAm3 = (taxableIncome - joint3low) * tax3
                totalTaxes = taxAm3 + taxAm2 + taxAm1
                print(f'Tax is {totalTaxes:.2f}')
        else:
            taxAm2 = (taxableIncome - joint2low) * tax2
            totalTaxes = taxAm2 + taxAm1
            print(f'Tax is {totalTaxes:.2f}')
    else:
        taxAmount = taxableIncome * tax1
        print(f'Tax is {taxAmount:.2f}')