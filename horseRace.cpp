#include <iostream>
#include <random>
#include <cstdio>

#define MAX_HORSES 5
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

int main() {
	std::cout << "Welome to the horse race!" << std::endl;

	//set all horses to 0 and print their initial lanes
  int horses[MAX_HORSES];
	for (int i = 0; i < MAX_HORSES; ++i) {
		horses[i] = 0;
		printLane(i, horses);
	}

	bool horsesRacing = true;
	while (horsesRacing) {
		std::cout << "Press ENTER to continue..." << std::endl;
		std::cin.get();
		for (int i = 0; i < MAX_HORSES; ++i) {
			advance(i, horses);
			printLane(i, horses);
			if (isWinner(i, horses)) {
				horsesRacing = false;
			}
		}
	}
	for (int i = 0; i < MAX_HORSES; ++i) {
		if (isWinner(i, horses)) {
			std::cout << std::endl << "Horse " << i << " Won!" << std::endl;
			std::cout << "Press ENTER to end" << std::endl;
			std::cin.get();
			return 0;
		}
	}

	//if no horses won, the program shouldn't have ended
	return 1;
}
