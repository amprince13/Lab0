// Lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab0.h"
#include <iostream> 
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int usage() {
	cout << "Lab0 program: This is a card program in order to run this program input a card file on the command line \n" 
		<< "An example is Lab0.exe card_file.txt would make Lab0 run using card_file.txt as its input file" << endl;
	
	return -1;
}
 
int parseFile(vector<Card> &deck, char * inputFile) {
	ifstream ifs;
	ifs.open(inputFile);
	if (ifs.is_open()) {
		string card_in;
		while (ifs >> card_in) {
			//std::cout << card_in << std::endl;
			int i;	// value
			char c; // suit
			if (card_in.length() == 3) {
				i = ((card_in[0]-48) * 10) + (card_in[1]-48);
				if (i == 10) {
					c = card_in[2];
				}
				else {
					c = 'i';
				}
			}
			else if (card_in[0] == 'j' || card_in[0] == 'J') {
				i = 11;
				c = card_in[1];
			}
			else if (card_in[0] == 'q' || card_in[0] == 'Q') {
				i = 12;
				c = card_in[1];
			}
			else if (card_in[0] == 'k' || card_in[0] == 'K') {
				i = 13;
				c = card_in[1];
			}
			else if (card_in[0] == 'a' || card_in[0] == 'A') {
				i = 14;
				c = card_in[1];
			}
			else {
				i = card_in[0] - 48;
				c = card_in[1];
			}
			Card A = { switch_to_enum(i), switch_to_suit(c)};
			//cout << i << c << endl;
			if (A.card_rank != -1 && A.card_suit != -1) {
				deck.push_back(A);
				//cout << A.card_rank << A.card_suit << endl;
			}
		}
		if (deck.size() == 0) {
			cout << "No cards in file" << endl;
			return NODECK;
		}
	}
	else {
		cout << "This file could not be found" << endl;
		return FAIL;
	}
	return SUCCESS;
}
 
suit switch_to_suit(char c) {
	switch (c) {
	case 'c': case 'C':
		return C;
	case 's' : case 'S':
		return S;
	case 'd' : case 'D' :
		return D;
	case 'h' : case 'H' :
		return H;
	default: {
		return I;
	}
	}
}
card_rank switch_to_enum(int i) {
	switch (i) {
	case 2:  i = 2;
		return TWO;
		break;
	case 3:  i = 3;
		return THREE;
		break;
	case 4:  i = 4;
		return FOUR;
		break;
	case 5:  i = 5;
		return FIVE;
		break;
	case 6:  i = 6;
		return SIX;
		break;
	case 7:  i = 7;
		return SEVEN;
		break;
	case 8:  i = 8;
		return EIGHT;
		break;
	case 9:  i = 9;
		return NINE;
		break;
	case 10:  i = 10;
		return TEN;
		break;
	case 11:  i = 11;
		return JACK;
		break;
	case 12:  i = 12;
		return QUEEN;
		break;
	case 13:  i = 13;
		return KING;
		break;
	case 14:  i = 14;
		return ACE;
		break;
	default: {
		return INVALID;
		break;
	}

	}
}
	
string card_rank_to_string(card_rank rank) {
	switch (rank) {
	case 2: 
		return "Two ";
		break;
	case 3:
		return "Three ";
		break;
	case 4: 
		return "Four ";
		break;
	case 5: 
		return "Five ";
		break;
	case 6:
		return "Six ";
		break;
	case 7:
		return "Seven ";
		break;
	case 8:
		return "Eight ";
		break;
	case 9:
		return "Nine ";
		break;
	case 10:
		return "Ten ";
		break;
	case 11:
		return "Jack ";
		break;
	case 12:
		return "Queen ";
		break;
	case 13:
		return "King ";
		break;
	case 14:
		return "Ace ";
		break;
	default: {
		return "Invalid card rank ";
		break;
	}
	}

}

string suit_to_string(suit s){
	switch (s) {
	case 1:
		return "Hearts";
		break;
	case 2:
		return "Clubs";
		break;
	case 3:
		return "Spades";
		break;
	case 4:
		return "Diamonds";
		break;
	default: {
		return "Invalid";
		break;
	}
	}
}

int print_deck(const vector<Card> &deck) {
	// Print function
	for(size_t i = 0; i != deck.size(); ++i) {
		print_card(deck[i]);
	}
	if (deck.size() == 0) {
		cout << "There was no cards inputted to create a deck" << endl;
		return NODECK;
	}
	return SUCCESS;
}

int print_card(Card c) {
	string card_out;
	cout << card_rank_to_string(c.card_rank) << "of " << suit_to_string(c.card_suit) << endl;
	//cout << c.card_rank << " " << c.card_suit << endl;
	return 0;
}


int main(int argc, char *argv [] )
{
	if (argc != 2) {
		cout << "Wrong number of command line arguments inputted please input one" << endl;
		usage();
		return FAIL;

	}
	else {
		vector<Card> deck;
		if (parseFile(deck, argv[1]) == 0) {
			print_deck(deck);
		}
		else {
			usage();
			return FAIL;
		}

		return SUCCESS;
	}
}

