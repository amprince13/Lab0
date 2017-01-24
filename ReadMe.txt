Lab0 ReadMe File
Austin Prince

This is my Lab0 ReadMe File. Lab0 is a program that takes a card_file.txt containing 
valid card strings and creates a Card struct which it then pushes on a deck vector. 
The program contains several functions to accomplish this task as well as a print function
which prints all the cards that have been pushed to the deck from a valid card_file.txt.

I ran several trials on this program to assure that it was working correctly. The main errors
I expected to encounter while building this program were an empty file being inputted such that a 
deck was not constructed, a file containing invalid card strings, a file that could not be found or 
an incorrect number of command line arguments being given to the program.
I tested each of these cases as documented below.

In order to test that the program would correctly catch an invalid card_file being inputted into
the command line I tested the following case.
Input: Lab0.exe card_file
Output: This file could not be found (followed by the usage function output)
echo %errorlevel% -1

Empty file inputted
Input: Lab0.exe dummy_file.txt
Output: No cards in file (followed by usage function output)
echo %errorlevel% -1

Wrong number of command line arguments
Input: Lab0.exe card_file1 card_file2
Output: Wrong number of command line arguments inputted please input one (followed by usage function output)
echo %errorlevel% -1

Invalid cards were simply skipped if the entire deck was made up of invalid cards then the program outputs 
that the deck is empty.
echo %errorlevel% -1


