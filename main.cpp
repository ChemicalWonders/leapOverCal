#include <iostream>
#include <string>
#include "Leap.h"
#include "SampleListener.h"
#include "RPSG.h"

using namespace Leap;

const bool CLEAR_SCREEN = true;

//@brief Utilizes an escape character sequence to clear the screen.
void clearScreen() {
	cout << endl;

	if (CLEAR_SCREEN)
	{
		cout << "\033c" << endl;
    }

    cout << endl;
}

void drawTitle(){
	clearScreen();
    std::cout << "Welcome to Minigame mania, powered with Leap Motion!\n";
    std::cout << "Created by Kevin from UC Riverside completely in C++\n";
    std::cout << "Please wait for the leap motion to connect before starting the game. \nText will say 'connected'\n";
    std::cout << "To start the game, press ENTER\n";
    std::cin.get(); // Waits for Enter in order to start going
}

void drawMenu() {
    clearScreen();
    std::cout << "Point a number for the mission you want to take. \nPlease wait up to half a second for the leap motion to recognize your finger.\n";
	std::cout << "1. Delivery of groceries to Mother. \n";
	std::cout << "2. Complete a quest with Dora the Explorer. \n";
	std::cout << "3. Battle the dragon in an epic battle of Rock, Paper, Scissors. \n";
	std::cout << "4. Exit the game. \n";
	std::cout << "Choose. Choose now: ";
	std::cout << std::endl; //Extra Space for clarity.
    cout << endl;
}


void motherGame(){
	std::cout << "Hello? Are you done grocery shopping yet? I need to have my butter and cream to cook!\n";
	std::cin.get();
}

void doraGame(){
	std::cout << "Time to help Dora the Explorer with a little project.\n";
	std::cin.get();

}

void rockPaperScissors(){
	RPSG rpsg;

	std::cout << "Time to battle the dragon, are you ready? Press Enter to continue.\n";
	std::cin.get();

	rpsg.first_game();
	return;
}

void choices (){

	Controller controller;
	SampleListener listener;

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();
	int fingerCount = fingers.extended().count();
	
	drawMenu();

	while (!cin.get()){
		fingerCount = fingers.extended().count();
		std::cout << fingerCount << std::endl;
	}

	if (fingerCount == 1){
		clearScreen();
		motherGame();
	}
	else if (fingerCount == 2){
		clearScreen();
		doraGame();
	}
	else if (fingerCount == 3){
		clearScreen();
		rockPaperScissors();
		cin.ignore();
	}
	else if (fingerCount == 4){
		std::cout << "Fine. Goodbye. \n";
		exit(1);
	}
	else{
		std::cout << "You have choosen something invalid. Pick a different number.\n";
	}
	choices();
}

int main(int argc, char** argv) {

	srand(time(NULL));
	
	SampleListener listener;
	Controller controller;

    controller.addListener(listener);

	// Creates the title once.
	drawTitle(); 

	// Code for the game menu
	choices();

    // Remove the sample listener when done
    controller.removeListener(listener); 

	return 0;

}
