/*
Nim.cpp
Mayson Cunningham
Implementation file for Nim class (objects) defined in Nim.h (provided by instructor).
Nim.cpp defines objects of the Nim class for use in a game of Nim.
*/
#include <iostream>
#include "Nim.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// If it is computer's turn to play
 // It is either under smart mode or non-smart mode : will be passed to computer_move from random generator in main().
/*
* Represents a legal move when it is the computer's turn to play
* The computer's move is either a smart-move or
* non-smart-move, depending on the parameter named smart.
* (Note that the private data member, pileSize, will be modified)
*@param smart bool: representing the computer takes smart move (if true)
* or non-smart move (if false)
*
*@return: void function
*/
void Nim::computer_move(bool smart)
{
	bool powtwominusone = false; //define the bool we will use to determine if our current pilesize is or is not a power of two minus one.
	// it will default to false, unless we find otherwise.

	int targetmarb = 0; // variable to hold what the pile needs to become ; the first power of two minus one that is less than our current pilesize (when I use this variable).

	// in smart move mode:
	/*Under the “smart-move” mode, the computer needs to make the following legal
		move to win the game:
		take enough marbles to make the size of the remaining pile a power of
		two minus one (1, 3, 7, 15, 31 are some examples of the power of two minus one)
		if the current pile size is not one of those power of two minus 1. **
		*/
	if (smart == true) // if in smart mode
	{
		vector<int> powsoftwominusone; // our vector that holds all in range powers of two minus one
		int value; //  variable to hold elements to go into vector.
		for (int n = 1; ; n = n + 1) // create a loop to create vector elements.
		{
			value = pow(2, n) - 1; // use the pow() function in the cmath/standard lib to give me a power of two to the nth order minus one.
			if (value > marble_count) // cut off addition to the vector once we are greater than marble count.
			{
				break;
			}
			if (value >= 1) // add values >= 1 to vector powsoftwominusone
			{
				powsoftwominusone.push_back(value); // add elements to vector

				if (value == marble_count) // if one of the values we are adding to this vector is equal to our marble count
				{

					powtwominusone = true; // then we have a power of two minus one as a marble count.
				}
			}
		}
		//When the current pile size is already a 2’s power – 1, make a random
		//move taking at least one but at most half of the marbles.
		if (powtwominusone == true)
		{
			// Here, we select a RANDOM amount of marbles to remove via the rand() function. Note, srand() seeds the rand function, and it is called in main. 
			// It is seeded via the time.
			// rand() takes care of generating a random number.
			// the result of rand() % (marble_count / 2) is always a number between 0 and (marble_count / 2) - 1 .
			//we divide marble_count by 2 in order to limit the maximum number of marbles that can be removed to half the current pile.
			int toremove;
			toremove = rand() % (marble_count / 2) + 1;
			marble_count = marble_count - toremove; // the leftover of the difference is the leftover marble count.
			cout << "The computer removed " << toremove << " marbles from the pile." << endl; // display marbles removed message
			cout << endl;
		}
		else{  // if the current pile size is not one of those power of two minus 1; 
			  //take enough marbles to make the size of the remaining pile a power of two minus one.*
			  // Find the largest 'power of 2 minus 1' number less than marble_count **
		
			// Let's reverse our powersoftwominusone vector:
			// This will allow us to loop through in range values of powers of two minus one to compare to our current pilesize. Since we (well the computer) is trying to take the least amount of marbles to
			// make the new pile size a power of two minus one, we will continously compare the current pilesize to the decreasing in value powers of two minus one, and the first value that is smaller in value
			// than the current pilesize will become the new pilesize (what the computer is trying to get the current pilesize to). 
			// we will then take the difference of the current pilesize and the target power of two minus one , and this will be what is subtracted from the pool of marbles; what the computer will take.
			//* I only have to reverse/swap values up to the center of the vector, so we loop from the 0th element to the size/2 (middle) element. I swap the corresonding element's relative to their position from the center element.
			//* **** THE VECTOR POWSOFTWOMINUSONE IS REVERSED;;NOTE THIS FOR THE REST OF THE PROGRAM.
			//*/
			int size = powsoftwominusone.size();
			for (int i = 0; i < (size / 2); i = i + 1)
			{
				swap(powsoftwominusone[i], powsoftwominusone[size - i - 1]); // reverse vector
			}
			// NOW let's loop through our (reversed) powsoftwominusone vector and find the first power of two minus one that is less than our current pilesize.
			// We will store this value in a variable called targetmarb ; and then take the difference.
			// // This is what the computer will take, and the new pilesize will be passed to our function setmarblecount to take care of setting the new size.
			int q = 0; // Initialization outside the loop
			while (q < powsoftwominusone.size()) // Condition check at the beginning of each iteration
			{
				if (powsoftwominusone[q] < marble_count)
				{
					targetmarb = powsoftwominusone[q]; // Store the value once the condition is met
					break; // Exit the loop
				}
				q = q + 1; // Increment at the end of each iteration
			}
			int toremove;
			toremove = marble_count - targetmarb;
			marble_count = marble_count - toremove;
			cout << "The computer removed " << toremove << " marbles from the pile." << endl; // display message
			cout << endl;
			set_marble_count(marble_count); // pass this value to set_marble_count to update the marble count.
		}
	}
	// if the current pile size is already a 2’s power – 1 ; make a random move taking at least one but at most half of the marbles.*
	else{ //smart = false ; Non-smart move: random legal move
		// Here, we select a RANDOM amount of marbles to remove via the rand() function. Note, srand() seeds the rand function, and it is called in main. It is seeded with the time.
		// rand() takes care of generating a random number.
		// the result of rand() % (marble_count / 2) is always a number between 0 and (marble_count / 2) - 1 .
		//we divide marble_count by 2 in order to limit the maximum number of marbles that can be removed to half the current pile.
		int toremove;
		toremove = rand() % (marble_count / 2) + 1;
		marble_count = marble_count - toremove;
		cout << "The computer removed " << toremove << " marbles from the pile." << endl;
		cout << endl;
		set_marble_count(marble_count); // pass this value to set_marble_count to update the marble count.
	}
}

// Default constructor
Nim::Nim()
{
	marble_count = 0; // default marble count
}

// Alternate constructor
Nim::Nim(int ini_size)
{
	marble_count = ini_size; // default marble count where user sets 
}

// Set the current size of the pile.
void Nim::set_marble_count(int size)
{
	marble_count = size; // set marble count to the size integer passed
}

// Get how many marbles are on the pile.
int Nim::get_marble_count() const
{
	return marble_count; // return the current marble count.
}

// Display the current marbles on the pile
void Nim::print() const
{
	// loop through all the marbles (imagine it as such) and print a marble for each marble there. 
	for (int i = 0; i < marble_count; i = i + 1)
	{
		cout << MARBLE;
	}
	cout << endl;
}

// If it is player's (the user's) turn to play
// Returns `true` if the player makes a move, removing
// marbles from the pile.
// Returns `false` if the player forfeits.
/*
* Represents a legal move when it is the user's turn to play the game
* (it should repeatedly ask the user to enter how many marbles to take
* until the user makes a legal move, or enters “F” or “f” to forfeit.)
* (Note that the private data member, pileSize, will be modified)
*@return: bool function
*/
bool Nim::player_move()
{
	int input; // define variable we will use to take input
	cout << "How many marbles do you want to remove (1-" << marble_count / 2 << ") ? " << endl; // ask user input
	cin >> input; // take input
	if (cin.fail()) // not a valid input if we're here
	{
		cin.clear(); // clear the fail flag set by cin.fail()
		string check; // create dummy var for reading failed inptus
		cin >> check; // assign the failed input into dummy string
		if (check == "F" || check == "f") // check if F / f
		{
			return false; // return false if forfeit. in main() we handle output message
		}
		else
		{
			cout << "Not an integer! Please enter an integer value between 1 and " << marble_count / 2 << "." << endl; // if bad input not "F/f";take input again
			cout << "How many marbles do you want to remove (1-" << marble_count / 2 << ") ? " << endl; // display message
			cin >> input; // take input
		}
		cin.ignore(256, '\n'); // clear out all the "bad" input leftover (ex. a float instead of int for input var)
	}
	else // cin did not fail
	{
		cin.ignore(256, '\n'); // ignore leftover garbage (ex. a char after a space after the integer)

		// Now that we have a good integer WE MUST CHECK THAT IT IS IN RANGE
		if (input >= 1 && input <= marble_count / 2) // check in range
		{
			// If here, a "legal move" is concur being made (taking at least one but not more than half of the marbles)
			cout << "You removed " << input << " marbles from the pile." << endl << endl; // display how many marbles were removed.
			marble_count = marble_count - input; // create new marble count.
			set_marble_count(marble_count); // pass this value to set_marble_count to update the marble count.
			return true; // return true as legal move occured
		}
		else // input is out of range
		{
			cout << "That number of marbles is not between 1 and " << marble_count / 2 << "! Try again." << endl; // display output message
			cout << "How many marbles do you want to remove (1-" << marble_count / 2 << ") ? " << endl; // input message
			cin >> input; // take input
		}
	}
}