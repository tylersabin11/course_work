#Tyler Sabin
#October 28, 2023
#Section 006
#This program will allow a user to play multiple R/P/S with a computer until the user no longer wishes to play

import random as rn

def main():
    print(intro(), "\n\n")
    keep_play=True
    while keep_play:
        play_game()
        keep_play=keep_going()
    print('Bye')

#Give a brief intro of the game
def intro():
    return 'You will play Rock, Paper, Scissors with the Computer'

#Generate a random number for the cpu's choice
def get_comp_choice():
    choiceCMP = rn.randint(1,3)
    return choiceCMP

#ask the user to input a choice, will require to enter another choice until the requirements are met
def get_user_choice():
    choiceUser = (input("rock, paper, or scissors? "))
    while choiceUser != "rock" and choiceUser != "paper" and choiceUser != "scissors":
        print("Invalid input")
        choiceUser = input("rock, paper, or scissors?")
    return choiceUser

#Accept a string input and convert it to an int
def choice_to_num(choice):
    if choice == "rock":
        return 1
    elif choice == "paper":
        return 2
    else:
        return 3

#Accept an int input and convert it to a string
def num_to_choice(num):
    if num == 1:
        return 'rock'
    elif num == 2:
        return 'paper'
    else:
        return 'scissors'

#Display the choices using the num_to_choice function
def display_choices(choices_int):
    choicesInt = num_to_choice(choices_int)
    return choicesInt

#Determine who won the game User/CPU
def who_won(computer,user):
    if computer == 1 and user == 2 or computer == 2 and user == 3 or user == 1 and computer == 3:
        return 'You won'
    elif computer == 1 and user == 3 or computer == 3 and user == 2 or user == 1 and computer == 2:
        return 'I won'
    else:
        return 'It\'s a tie'

#Call all functions to have the game properly function in logical order
def play_game():
    userChoiceStr = get_user_choice()
    userInt = choice_to_num(userChoiceStr)
    computerChoiceInt = get_comp_choice()
    print('I chose', display_choices(computerChoiceInt))
    print('You chose', display_choices(userInt))
    print(who_won(computerChoiceInt, userInt), "\n\n")

#Determine if the user would like to continue playing or not
def keep_going():
    answer = input("Do you want to play another game? y/n ")
    if answer == 'n':
        return False
    return True
    
main()