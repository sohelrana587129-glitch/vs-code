
import random
def guess_game():
    print("welcome to the guess the number game!")
    number = random.randint(1, 100)
    attampts = 0
    while True:
        try:
            guess = int(input("Guess a number between 1 to 100: "))
        except ValueError:
            print("please enter a value number: ")
            continue
        attampts += 1

        if guess < number:
            print("too Low! try again.")
        elif guess > number:
            print("too high! try again.")
        else:
            print(f"Corruct! the number waas {number}.")
            print(f"you guess it in {attampts} attampts.")
            break

guess_game()