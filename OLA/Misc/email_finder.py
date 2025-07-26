#Tyler Sabin
#Section 006
#Nov 30, 2023
#This program will iterate through a file to find valid emails


def main():
    inFileName = input("Please enter the input filename: ")
    print(f'You entered {inFileName}')
    outFileName = input("Please enter the output filename: ")
    print(f'You entered {outFileName}')

    emailFile = open(inFileName,'r')
    outEmail = open(outFileName,'w')
    validEmail = ''
    username = ''
    domainName = ''
    count = 0

    emailLine = emailFile.readline()
    while emailLine != '':
        #strip the \n
        emailLine = emailLine.rstrip('\n')
        #check to see if there is one and only '@'
        if '@' in emailLine and emailLine.count('@') == 1:
            #split at the '@' and assign variables for the domain and username
            splitEmail = emailLine.split('@')
            domainName = splitEmail[1]
            username = splitEmail[0]
            #check to see if the first character is a num or char, if not the email is not vaild
            if username[0].isalnum():
                validEmail += username[0]
                #iterate throught the username and check the conditions, if they meet the conditions, concatenate the character to the valid email
                for index in username[1:]:
                    if index.isalnum() or index == '.' or index == '-' or index == '_':
                        if index == '.':
                            validEmail += index
                        elif index != '.':
                            validEmail += index
                        else:
                            validEmail = ''
                            username = ''
                            break
                    else:
                        validEmail = ''
                        username = ''
                        break
            else:
                username = ''
                break

            #check to see if the username is not blank, if so, start the iteration for the domain name
            if username != '':
                validEmail += '@'
                if domainName[0].isalnum():
                    validEmail += domainName[0]
                    for index in domainName[1:]:
                        if index.isalnum() or index == '.':
                            if index == '.' and validEmail[-1] != '.':
                                validEmail += index
                            elif index.isalnum():
                                validEmail += index
                            else:
                                validEmail = ''
                                domainName = ''
                                break
                        else:
                            validEmail = ''
                            domainName = ''
                            break
                else:
                    validEmail = ''
                    domainName = ''
                    break
        else:
            validEmail = ''

        #if the last character is not a "." then it is valid and should be counted as a valid email and written to the out file
        if validEmail != '' and validEmail[-1] != '.':
            count += 1
            outEmail.write(validEmail + '\n')

        validEmail = ''
        domainName = ''
        username = ''
        emailLine = emailFile.readline()
    
    emailFile.close()
    outEmail.close()
    print(f'Found {count} valid email addresses')

main()