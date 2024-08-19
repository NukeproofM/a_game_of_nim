In our game of Nim, two players - the user and program alternately take marbles from a pile. In each turn, a
player must make a legal move taking at least one but at most half of the marbles
from the pile and then let the other player take a turn. The player who takes the
last marble loses the game.
Upon random selection: a pile size is generated, smart/non-smart mode for the computer is selected 
(more on this a couple lines down), and a player is chosen to go first.
At anytime the user can input "F" or "f" to terminate the game.
The program/computer can play under "smart" or "non-smart" mode; that is
under the “smart-move” mode, the computer needs to make the following
legal move to win the game: 1-> take enough marbles to make the size of the remaining pile a
power of two minus one (1, 3, 7, . . .) IF the current pile size is not one of those power
of two minus 1. 2-> When the current pile size is already a 2’s power – 1, make a
random move taking at least one but at most half of the marbles.
When the computer is under “non-smart-move” mode,
the computer makes a random legal move: taking at least one but at most
half of the marbles

Happy Nim-ing !
