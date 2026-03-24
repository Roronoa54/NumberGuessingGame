// NumberGuessingGame.cpp

#include <iostream> // std::cout, std::cin
#include <cstdlib>	// std::rand(), std::srand()
#include <ctime> 	// std::time()
#include <string>

void GuessNumber(int &randomNumber, int guessNumber);
void GameDifficulty();
void GameMenu();

void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}

int main()
{
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
		//
		GuessNumber(randomNumber, 0);
		do
		{
			std::cout << "\nDo you want to play again, if you enter 'no' the game will end? (y/n): ";
			std::cin >> playAgain;
			//std::cin.clear(); Only needed if we are reading a number and the user enters a letter. In this case we are reading a char, so we don't need to clear the input buffer.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Telling the buffer to ignore everything it possibly can until it finds a newline character "\n". Basically the enter key.

		} while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');
	}
	return 0;

	// OPTIONAL
	// Use constants instead of magic numbers. So instead of writing 100, write const int MAX_NUMBER = 100; and use MAX_NUMBER in the code.

	// Add a Leaderboard if you can. For now only stores the last 3 highest scores. (so lowest attempt at top)

	// BAD HABITS TO AVOID
	// Don't ignore std::cin. Always validate user input.

	return 0;
}

void GameMenu()
{
	int menuChoice;
	std::cout << "Welcome to the Number Guessing Game!" << std::endl;
	std::cout << "1. Start Game" << std::endl;
	std::cout << "2. View Leaderboard" << std::endl;
	std::cout << "3. Exit" << std::endl;

	std::cin >> menuChoice;
	std::cin.clear();
	std::cin.ignore();
}
void GuessNumber(int &randomNumber, int guessNumber)
{
	clearScreen();
	std::cout << "Your random number has been generated. Please enter a guess: ";
	
	int attemptCounter = 0;
		
	while (guessNumber != randomNumber)
	{
		std::cin >> guessNumber;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid input, please enter a number: ";
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		attemptCounter++;
		if (guessNumber < randomNumber)
		{
			std::cout << "Too low! Try again: ";
		}
		else if (guessNumber > randomNumber)
		{
			std::cout << "Too high! Try again: ";
		}
	}

	std::cout << "Congratulations! You guessed the number in " << attemptCounter << " tries!" << std::endl;
	std::cout << "The random number was: " << randomNumber << std::endl;
}


