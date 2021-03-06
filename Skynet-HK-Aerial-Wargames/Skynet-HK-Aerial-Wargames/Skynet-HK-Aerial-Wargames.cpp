// skynetAI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	bool keepPlaying = true; // A booleean that keeps the game looping until stated otherwise by the player

	while (keepPlaying == true) { // The while loop that works with the boolean above to keep the game looping

								  //generate the enemy location
		cout << "Generate random enemy in 8x8 grid..." << endl;
		srand(time(0));

		int searchGridHighNumber = 64; //sets the highest number the drone can search through
		int searchGridLowNumber = 1; //sets the lowest number the drone ca search through
		int guess = 0; // the guesses for the human player
		int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber; //generates the enemy location somewhere between the two numbers

		int answer; // answer for the player input on whether they want to play again or not

		cout << "Let the Skynet Wargames begin!\n\n";

		int binaryPredictionCounter = 0; //sets the counter for how many pings it takes the binary search AI to find the enemy to 0
		int linearPredictionCounter = 0; //sets the counter for the linear search AI
		int randomPredicitonCounter = 0; //sets the counter for the random search AI
		int humanPredicitionCounter = 0; //sets the counter for the human inputs
		bool binaryTargetFound = false; //sets the boolean for finding the enemy to false so the while loop works
		bool linerTargetFound = false; //sets the boolean for finding the enemy to false so the while loop works
		bool randomTargetFound = false; //sets the boolean for finding the enemy to false so the while loop works
		bool humanTargetFound = false; //sets the boolean for finding the enemy to false so the while loop works

		while (binaryTargetFound == false) { //the while loop states that as long as the enemy isn't found it will keep reiterating until it does
			int targetLocationPredicition = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber; //based on the high and low points, the program gets a number to check
			binaryPredictionCounter++; //adds 1 to the prediction counter so that we know how many pings it took

			if (targetLocationPredicition > enemyLocation) { //states what will happen if the prediction was higher than the enemy's location
				searchGridHighNumber = targetLocationPredicition - 1; //this chops off all the numbers higher than the prediciton so that they aren't checked again
			}
			else if (targetLocationPredicition < enemyLocation) { //states what will happen if the prediction was lower than the enemy's location
				searchGridLowNumber = targetLocationPredicition + 1; //this chops off all the numbers lower than the prediction so that they aren't checked again

			}
			else if (targetLocationPredicition = enemyLocation) { //states what will happen if the prediction was correct on the enemy's location
				binaryTargetFound = true; //sets the targetFound to true so that the while loop will end
			}
		}

		while (humanTargetFound == false) { // States that this will keep going until the player finds the enemy
			cout << "Enter a guess: ";
			cin >> guess;
			++humanPredicitionCounter; // Counts to see how long it takes for the player to guess where the enemy is

			if (guess > enemyLocation) { // conditional that says your guess is too high
				cout << "Too high!\n\n";
			}
			else if (guess < enemyLocation) { // conditional that says your guess is too low
				cout << "Too low!\n\n";
			}
			else if (guess = enemyLocation) { // Conditional that says you found the enemy and ends the loop
				cout << "You guessed correctly!\n\n";
				humanTargetFound = true;
			}
		}

		while (randomTargetFound == false) { // States that this will keep going until randomTargetFound finds the enemy
			int targetLocationPredicition = rand() % (64 - 1 + 1) + 1; // Generates a random number between 1 and 64
			randomPredicitonCounter++; // Counts to see how long it takes for the random AI to guess where the enemy is

			if (targetLocationPredicition > enemyLocation) { // Does nothing since the information is kept secret and displayed at the end
				randomTargetFound = false;
			}
			else if (targetLocationPredicition < enemyLocation) { // Does nothing since the information is kept secret and displayed at the end
				randomTargetFound = false;
			}
			else if (targetLocationPredicition = enemyLocation) { // Sets the randomTargetFound to true since it finally found its target
				randomTargetFound = true;
			}
		}
		while (linerTargetFound == false) { // States that this will keep going until linearTragetFound finds the enemy
			linearPredictionCounter++; // Adds one to the counter each run through, which will also be what we use to test since it is linear
			if (linearPredictionCounter != enemyLocation) { // States that if the iteration number doesn't equal the enemyLocation that it needs to keep going
				linerTargetFound = false;
			}
			else if (linearPredictionCounter = enemyLocation) { // States that if the iteration number is equal to enemyLocation that it can stop
				linerTargetFound = true;
			}
		}

		cout << "The number of guesses the binary AI took was: " << binaryPredictionCounter << endl;
		cout << "The number of guesses the linear search AI took was: " << linearPredictionCounter << endl;
		cout << "The number of guesses the random AI took was: " << randomPredicitonCounter << endl;
		cout << "The number of guesses it took you was: " << humanPredicitionCounter << endl;

		cout << "Play again? 1 for yes, 2 for no. ";
		cin >> answer;

		if (answer == 1) { // Takes the player answer and makes it so the game runs again
			keepPlaying = true;
		}

		else { // Takes the player answer and ends the game
			keepPlaying = false;
		}
	}
	system("pause");
	return 0;
}

