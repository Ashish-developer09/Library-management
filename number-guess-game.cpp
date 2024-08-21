#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    const int MAX_ATTEMPTS = 5;  // Maximum number of attempts
    int numberToGuess, userGuess;
    int attempts = 0;
    bool guessedCorrectly = false;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    numberToGuess = rand() % 100 + 1;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "You have " << MAX_ATTEMPTS << " attempts to guess it." << endl;

    while (attempts < MAX_ATTEMPTS) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess < 1 || userGuess > 100) {
            cout << "Please guess a number between 1 and 100." << endl;
            continue;
        }

        attempts++;

        if (userGuess == numberToGuess) {
            guessedCorrectly = true;
            break;
        } else if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }

    if (guessedCorrectly) {
        cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
    } else {
        cout << "Sorry, you've used all your attempts. The number was " << numberToGuess << "." << endl;
    }

    return 0;
}
