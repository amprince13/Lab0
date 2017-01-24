#pragma once

#ifndef LAB0
#define LAB0
#include <vector>
#include <iostream>
 
void usage(char * Lab0, char * input_file) {
	std::cout << "This is my program its cool" << std::endl;
}
enum card_rank { TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 14, INVALID =-1};
enum suit { H=1, C=2, S=3, D=4, I=-1};
enum file_success { SUCCESS = 0, FAIL = -1, ARGCERROR = 2 , NODECK = 3};
struct Card {
	card_rank card_rank;
	suit card_suit;
};

int parseFile(std::vector<Card> &deck);
suit switch_to_suit(char c);
card_rank switch_to_enum(int i);
int print_card(Card c);
int usage();
#endif