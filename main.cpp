#include <iostream>
#include "Leap.h"
#include "LeapMath.h"

using namespace Leap;

void motherGame(){
	std::cout << "Hello. This is mother.";
}

void doraGame(){
	std::cout << "Time to help Dora the Explorer with a little project";

}

void rockPaperScissors(){
	std::cout << "Time to battle the dragon, are you ready?";
}

void choices (int number){
	if (number == 1){
		motherGame();
	}
	else if (number == 2){
		doraGame();
	}
	else if (number == 3){
		rockPaperScissors();
	}
	else if (number == 4){
		std::cout << "Fine. Goodbye. \n";
		return;
	}
	else{
		std::cout << "You have choosen something invalid. Pick a different number.";
		std::cin >> number;
		std::cout << std::endl;
		choices(number);
	}
}

int main(){

	int fingerCount = 0;

	while (fingerCount != 4){

		std::cout << "Point a number for the mission you want to take. \n";
		std::cout << "1. Delivery of groceries to Mother. \n";
		std::cout << "2. Complete a quest with Dora the Explorer. \n";
		std::cout << "3. Battle the dragon in an epic battle of Rock, Paper, Scissors. \n";
		std::cout << "4. Exit the game. \n";

		std::cout << "Choose. Choose now: ";

		std::cin >> fingerCount;
		std::cout << std::endl;
		choices(fingerCount);
		std::cout << std::endl;
	}

	return 0;

}