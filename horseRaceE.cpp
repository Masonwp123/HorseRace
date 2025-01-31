#include <iostream>
#include <random>
#include <cstdio>

#define MAX_HORSES 100
#define TRACK_LENGTH 15

void advance(int horseNum, int* horses) {
	std::random_device rd;
	std::uniform_real_distribution<> dist(0.0,2.0);
	
	int& horsePos = horses[horseNum];
	horsePos += std::round(dist(rd));
	horsePos = std::min(horsePos, TRACK_LENGTH - 1);
}

void printLane(int horseNum, int* horses) {
	int horsePos = horses[horseNum];
	for (int i = 0; i < TRACK_LENGTH; ++i) {
		if (horsePos == i) {
			std::cout << horseNum;
			continue;
		}
		std::cout << '.';
	}
	std::cout << std::endl;
}

bool isWinner(int horseNum, int* horses) {
	int horsePos = horses[horseNum];
	return horsePos >= TRACK_LENGTH - 1;
}

int getBet(int money, int& horse) {
	std::cout << "You have " << money << " money!" << std::endl;
	bool choosingHorse = true;
	while (choosingHorse) {
		std::cout << std::endl << "Which horse do you want to bet on? (0-" << MAX_HORSES - 1 << ")" << std::endl;
		std::cin.clear();
		std::cin >> horse;
		if (horse < 0 || horse >= MAX_HORSES) {
			std::cout << std::endl << "That is not a valid horse!" << std::endl;
			continue;
		}
		choosingHorse = false;
	}
	int bet = 0;
	bool betting = true;
	while (betting) {
		std::cout << std::endl << "How much do you want to bet? (You have " << money << " Money)" << std::endl;
		std::cin.clear();
		std::cin >> bet;
		if (bet > money) {
			std::cout << "You are too poor to bet that much!" << std::endl;
			continue;
		}
		if (bet < 0) {
			std::cout << "Your bet cannot be negative!" << std::endl;
			continue;
		}
		if (bet == 0) {
			std::cout << "You cannot bet nothing!" << std::endl;
			continue;
		}
		betting = false;
	}
	std::cout << std::endl << "You are betting " << bet << " Money on horse " << horse << "." << std::endl;
	std::cout << std::endl << "Press ENTER to continue..." << std::endl;
	std::cin.get();
	return bet;
}

int main() {
	
	int money = 100;
	int horseRace = 0;
	bool isRacing = true;

	while (isRacing) {

		if (money <= 0) {
			isRacing = false;
			std::cout << "You Ran out of money!" << std::endl;
			std::cout << "Press ENTER to end." << std::endl;
			std::cin.get();
			continue;
		}

		horseRace++;
		std::cout << "Welcome to horse race #" << horseRace << "!" << std::endl;
		
		int betHorse = -1;
		int bet = getBet(money, betHorse);

		//set all horses to 0 and print their initial lanes
  	int horses[MAX_HORSES];
		for (int i = 0; i < MAX_HORSES; ++i) {
			horses[i] = 0;
			printLane(i, horses);
		}
	
		bool horsesRacing = true;
		int winningHorse = -1;
		while (horsesRacing) {
			std::cout << "Press ENTER to continue..." << std::endl;
			std::cin.get();
			for (int i = 0; i < MAX_HORSES; ++i) {
				advance(i, horses);
				printLane(i, horses);
				if (horsesRacing && isWinner(i, horses)) {
					horsesRacing = false;
					winningHorse = i;
				}
			}
		}
		std::cout << std::endl << "Horse " << winningHorse << " Won!" << std::endl;
		if (betHorse == winningHorse) {
			money += bet;
			std::cout << std::endl << "You won " << bet * 2 << " Money!" << std::endl << std::endl;
			continue;
		}
		money -= bet;
		std::cout << std::endl << "You lost!" << std::endl << std::endl;
	}

	//if no horses won, the program shouldn't have ended
	return 1;
}
