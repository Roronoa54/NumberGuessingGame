// NumberGuessingGame.cpp

#include <iostream> // std::cout, std::cin
#include <cstdlib>	// std::rand(), std::srand()
#include <ctime> 	// std::time()
#include <string>

void GuessNumber(int &randomNumber, int guessNumber);
void GameDifficulty();

void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}

int main()
{

	// PLAYER INPUT
	// Ask the player to guess the number (Done)
	// Read it with std::cin (Done)

	// ATTEMPT COUNTER
	// Track how many guesses the player has made.
	// Display it when they win.

	// EXTRAS
	// Add difficulty levels -> Easy (10 guesses), Medium (7 guesses), Hard (5 gueses).
	// Input validation -> Ensure the player enters a number between 1 and 100 or types a letter.

	// WHERE TO START
	// 1. Generate random number and print it to the console for testing.
	// 2. Add the while loop and input.
	// 3. Add the hint system.
	// 4. Add the attempt counter.
	// 5. Add play again.
	// 6. Add difficulty levels.

	char playAgain = 'y';

	while (playAgain == 'y' || playAgain == 'Y')
	{
		srand(time(0)); // Seed the random number generator
		int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100. +1 is added to shift the range from 0-99 to 1-100
		GuessNumber(randomNumber, 0);
		std::cout << "\nDo you want to play again, if you enter 'no' the game will end? (y/n): ";
		std::cin >> playAgain;
	}
	return 0;

	// OPTIONAL
	// Use constants instead of magic numbers. So instead of writing 100, write const int MAX_NUMBER = 100; and use MAX_NUMBER in the code.

	// Add a Leaderboard if you can. For now only stores the last 3 highest scores. (so lowest attempt at top)

	// BAD HABITS TO AVOID
	// Don't ignore std::cin. Always validate user input.

	return 0;
}

void GuessNumber(int &randomNumber, int guessNumber)
{
	clearScreen();
	std::cout << "Your random number has been generated. Please enter a guess: ";
	std::cin >> guessNumber;

	while (guessNumber != randomNumber)
	{
		if (guessNumber < randomNumber)
		{
			std::cout << "Too low! Try again: ";
		}
		else
		{
			std::cout << "Too high! Try again: ";
		}
		std::cin >> guessNumber;
	}
	std::cout << "Congratulations! You guessed the number!" << std::endl;
	std::cout << "The random number was: " << randomNumber << std::endl;
}
