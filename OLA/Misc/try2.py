import re

def is_valid_email(email):
    # Function to check if an email is valid based on common constraints
    # Customize these conditions based on your specific requirements
    pattern = re.compile(r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$')
    return pattern.match(email) is not None

def main():
    inFileName = input("Please enter the input filename: ")
    print(f'You entered {inFileName}')
    outFileName = input("Please enter the output filename: ")
    print(f'You entered {outFileName}')

    try:
        with open(inFileName, 'r') as emailFile, open(outFileName, 'w') as outEmail:
            count = 0

            for emailLine in emailFile:
                emailLine = emailLine.strip()

                if is_valid_email(emailLine):
                    outEmail.write(emailLine + '\n')
                    count += 1

            print(f'Found {count} valid email addresses and saved to {outFileName}')

    except FileNotFoundError:
        print(f"Error: File '{inFileName}' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
