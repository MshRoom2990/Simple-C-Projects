#include <iostream>
#include <string>

#ifdef _WIN32
    const std::string clearCommand = "cls";
#else
    const std::string clearCommand = "clear";
#endif

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    /*
    * Number Guessing Game. A fun little C++ project. To begin, we need
    * to define 4 variables: the number to be guessed (a random number
    * between 1 and 100), the user's guess, the number of attempts, and
    * an integer to store the number of times the user has guessed correctly.
    */
    int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
    int userGuess = 0;
    int attempts = 0;
    const int maxAttempts = 10;
    /*
    * Since this game can be played on Windows and Linux based systems.
    * Implement a checker to determine what OS the user is on, and clear
    * the console accordingly.
    */

    system(clearCommand.c_str());
    /*
    * A nice title for the game when it starts.
    */
   std::cout << "\n[ Welcome to the number guessing game!" << std::endl;
   std::cout << "I'm thinking of a number between 1 and 100." << std::endl;
   std::cout << "You have " << maxAttempts << " attempts to guess the number. ]\n" << std::endl;

   while (attempts < maxAttempts) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        /* Increment the attempts */
        attempts++;

        if (userGuess < numberToGuess) {
            std::cout << "\nToo low!, try again...\n" << std::endl;
        } else if (userGuess > numberToGuess) {
            std::cout << "\nToo high!, try again...\n" << std::endl;
        }  else if (attempts == maxAttempts) {
            std::cout << "\nSorry, you've used all your attempts. The number was " << numberToGuess << ".\n" << std::endl;
        } else {
            std::cout << "\nCongratulations! You guessed the number correctly!\nOnly took you " << attempts << " attempts.\n" << std::endl;
            break;
        }
   }
}