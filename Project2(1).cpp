/*
 * File:    Project2.cpp
 * Purpose: The Project 2 driver file.
 * Author:  Mayson Cunningham
 * This is the driver file for our game of Nim.
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Nim.h"
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    srand(time(0)); // seed random function
    bool gameovernot = false; // bool to terminate game if F or f
    /*
    generate a random integer between PILE_MIN and
    PILE_MAX to denote the initial pile size.
    */
    const int INIT_SIZE = rand() % (PILE_MAX - PILE_MIN + 1) + PILE_MIN;
    Nim game(INIT_SIZE); // create game of Nim with size INITSIZE
    /*
     Second, your program should generate 0 or 1 randomly to decide which player (the
    computer or the user) takes the first turn
    */
    bool playerturn;
    playerturn = rand() % 2;
    /*
    Third, before the computer takes its first turn, your program should again generate
    0 or 1 randomly to decide whether the computer plays the whole game in “smart”
    move or “non-smart” move mode
    */
    bool computersmartmove;
    computersmartmove = rand() % 2;
    //display game board
    cout << "*****************************************************" << endl;
    cout << "*                  The game of Nim                  *" << endl;
    cout << "*   Players alternate taking at least one but at    *" << endl;
    cout << "*   most half of the marbles in the pile.           *" << endl;
    cout << "*   The player who takes the last marble loses.     *" << endl;
    cout << "*   This game was written by Mayson Cunningham.     *" << endl;
    cout << "*   Good luck beating the computer!                 *" << endl;
    cout << "*****************************************************" << endl;

    /*
    * We must display WHO will take the first turn.
    *
    * Then, we must display if the computer will play SMART, OR NOT SMART.
    *
    */

    if (playerturn == 1)
    {
        cout << "You will take the first turn!" << endl << endl;
    }
    else
    {
        cout << "The computer will take the first turn!" << endl << endl;
    }
    if (computersmartmove == 1)
    {
        cout << "The computer is going to play smart!" << endl << endl;
    }
    else
    {
        cout << "The computer is NOT going to play smart!" << endl << endl;
    }

    // initialize variables to tell who won
    bool computerwins;
    bool personwins;
    // "FALSE UNTIL PROVEN TRUE"
    computerwins = false;
    personwins = false;

    cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
    game.print(); // call print() to print out/display the ORIGINAL marble size
    cout << endl << endl;

    /*
    FIRST OF ALL, We must get the first play out of the way. Then, we will move into our loop for while marble count is > 0.
    */
    if (playerturn) // if playerturn == 1 == true, the human plays FIRST.
    {
        cout << "Your turn." << endl;
        gameovernot = game.player_move();
        if (gameovernot == false)
        {
            cout << "You forfeited the game. Sorry! You lost." << endl; //forfeit message
            return 0;
        }
        cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
        game.print(); // call print() to print out/display the ORIGINAL marble size
        cout << endl;
    }
    else // if playerturn == 0 == false, the computer plays FIRST
    {
        cout << "The computer plays..." << endl;
        game.computer_move(computersmartmove); //call computer_move ; will play accordingly (smart or not smart).
        cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
        game.print(); // call print() to print out/display the ORIGINAL marble size
        cout << endl;
    }

    if (playerturn == 0)
    {
        while (game.get_marble_count() > 1) // while the marble count > 1 keep playing game under normal conditions
        {
            cout << "Your turn." << endl;
            gameovernot = game.player_move();
            if (gameovernot == false)
            {
                cout << "You forfeited the game. Sorry! You lost." << endl; // forfeit message
                return 0;
            }
            cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
            game.print(); // call print() to print out/display the ORIGINAL marble size
            cout << endl;

            if (game.get_marble_count() == 1) // the count is one after PERSON takes the 2nd to last marble , then PERSON DID NOT TAKE THE LAST MARBLE ; PERSON WINS. Also break out of while loop.
            {
                personwins = true;
                break;
            }
            cout << "The computer plays..." << endl;
            game.computer_move(computersmartmove); //call computer_move ; will play accordingly (smart or not smart).
            cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
            game.print(); // call print() to print out/display the ORIGINAL marble size
            cout << endl;

            if (game.get_marble_count() == 1) // the count is one after COMPUTER takes the 2nd to last marble , then COMPUTER DID NOT TAKE THE LAST MARBLE ; COMPUTER WINS. Also break out of while loop.
            {
                computerwins = true;
                break;
            }
        }

        if (personwins == true && computerwins == false)
        {
            cout << "The computer must take the last marble. Congratulations! You won!" << endl;
            return 0;
        }
        if (computerwins = true && personwins == false) // person loses / computer wins
        {
            cout << "You must take the last marble. Sorry! You lost." << endl;
            return 0;
        }
        if (computerwins == true && personwins == true)
        {
            cout << "The computer must take the last marble. Congratulations! You won!" << endl;
        }
    }
    else // playerturn == 1 ; player went first, so computer must go second here
    {
        while (game.get_marble_count() > 1) // while the marble count > 1 keep playing game under normal conditions
        {
            cout << "The computer plays..." << endl;
            game.computer_move(computersmartmove); //call computer_move ; will play accordingly (smart or not smart)
            cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
            game.print(); // call print() to print out/display the ORIGINAL marble size
            cout << endl;

            if (game.get_marble_count() == 1) // the count is one after COMPUTER takes the 2nd to last marble , then COMPUTER DID NOT TAKE THE LAST MARBLE ; COMPUTER WINS. Also break out of while loop.
            {
                computerwins = true;
                break;
            }
            cout << "Your turn." << endl;
            gameovernot = game.player_move();
            if (gameovernot == false)
            {
                cout << "You forfeited the game. Sorry! You lost." << endl; // forfeit message
                return 0;
            }
            cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
            game.print(); // call print() to print out/display the ORIGINAL marble size
            cout << endl;

            if (game.get_marble_count() == 1) // the count is one after PERSON takes the 2nd to last marble , then PERSON DID NOT TAKE THE LAST MARBLE ; PERSON WINS. Also break out of while loop.
            {
                personwins = true;
                break;
            }
        }

        if (personwins == true && computerwins == false)
        {
            cout << "The computer must take the last marble. Congratulations! You won!" << endl;
            return 0;
        }
        if (computerwins == true && personwins == false) // person loses / computer wins
        {
            cout << "You must take the last marble. Sorry! You lost." << endl;
            return 0;
        }
        if (computerwins == true && personwins == true)
        {
            cout << "The computer must take the last marble. Congratulations! You won!" << endl;
        }
    }
    return 0;
}