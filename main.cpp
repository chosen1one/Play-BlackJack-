#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum CardSuit {
	SUIT_KREST,
	SUIT_SHARSHY,
	SUIT_KARGA,
	SUIT_TUYE,
	MAX_SUITS
};

enum CardRank {
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_VALET,
	RANK_DAMA,
	RANK_KAROL,
	RANK_TUZ,
	MAX_RANKS	
};


struct Card {
	CardSuit suit; 
	CardRank rank;
};

void printCard(const Card &card) {
	switch(card.rank) {
		case RANK_2:		cout << "2"; break;
		case RANK_3:		cout << "3"; break;
		case RANK_4:		cout << "4"; break;
		case RANK_5:		cout << "5"; break;
		case RANK_6:		cout << "6"; break;
		case RANK_7:		cout << "7"; break;	
		case RANK_8:		cout << "8"; break;	
		case RANK_9:		cout << "9"; break;	
		case RANK_10:		cout << "10"; break;	
		case RANK_VALET:	cout << "V"; break;	
		case RANK_DAMA:		cout << "D"; break;	
		case RANK_KAROL:	cout << "K"; break;	
		case RANK_TUZ:		cout << "T"; break;	
	}
	switch(card.suit) {
		case SUIT_KREST:	cout << "KR"; break;
		case SUIT_SHARSHY:	cout << "SH"; break;
		case SUIT_KARGA:	cout << "KA"; break;
		case SUIT_TUYE:		cout << "T"; break;
	}
}

void CardInit(Card *deck, int card = 0) {
	for (int rank = 0; rank < MAX_RANKS; rank++)
		for (int suit = 0; suit < MAX_SUITS; suit++)
			deck[card].suit = static_cast<CardSuit>(suit),
			deck[card].rank = static_cast<CardRank>(rank),
			card++;
}

printDeck(const Card *deck, int sz) {
	for (int i = 0; i < 52; i++) { 
		printCard(deck[i]);
		cout << (((i + 1) % 4 == 0) ? "\n" : "\t");
	}
	cout << '\n';
}

void ShuffleDeck(Card *deck) {
	for (int i = 0; i < 52; i++) {
		int swapi = rand() % 52;
		swap(deck[i], deck[swapi]);
	}
}

int getCardValue(const Card *card) {
	switch(card->rank) {
		case RANK_2:		return 2;
		case RANK_3:		return 3;
		case RANK_4:		return 4;
		case RANK_5:		return 5;
		case RANK_6:		return 6;
		case RANK_7:		return 7;
		case RANK_8:		return 8;
		case RANK_9:		return 9;
		case RANK_10:		return 10;
		case RANK_VALET:	return 10;	
		case RANK_DAMA:		return 10;
		case RANK_KAROL:	return 10;
		case RANK_TUZ:		return 11;
	}
}

char getPlayerChoice() {
	
	cout << "(h) to hit or (s) to stand : ";
	
	char choice;
	do {
		cin >> choice;
	} while(choice != 's' && choice != 'h');
	
	return choice;
}

bool playBlackJack(const Card *deck, Card *CurrentCard) {
	
	int PlayerSum = 0, DealerSum = 0;
	
	DealerSum += getCardValue(CurrentCard++);
	PlayerSum += getCardValue(CurrentCard++);
	PlayerSum += getCardValue(CurrentCard++);
	
	while (true) {
		cout << "You have : " << PlayerSum << "\n";
		
		if (PlayerSum > 21) return false;
		
		char choice = getPlayerChoice();
		if (choice == 's') break;
		
		PlayerSum += getCardValue(CurrentCard++);	 
	}
	
	while (DealerSum < 17) {
		DealerSum += getCardValue(CurrentCard++);
		cout << "Dealer has now : " << DealerSum << "\n";
	} 
	
	if (DealerSum > 21) return true;
	
	return PlayerSum > DealerSum; 
}

int main () {
	
	srand(time(0));
	
	Card deck[52];
	CardInit(deck);
	ShuffleDeck(deck);
	
	cout << ((playBlackJack(deck, deck)) ? "Player" : "Dealer") << "  won!"; 
	
	return 0;
}
