#include <iostream>
#include <string>
#include "Leap.h"
#include "./RPSG.h"

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

void motherGame(){
	std::cout << "Hello. This is mother.\n";
}

void doraGame(){
	std::cout << "Time to help Dora the Explorer with a little project.\n";

}

void rockPaperScissors(){
	RPSG rpsg;

	std::cout << "Time to battle the dragon, are you ready? Press Enter to continue.\n";
	std::cin.get();

	rpsg.first_game();
}

class SampleListener : public Listener {
    public:
    virtual void onConnect(const Controller&);
    virtual void onFrame(const Controller&);
};

void SampleListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Controller& controller) {


    Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();
	//int fingerCount = fingers.extended().count();
	//std::cout << fingerCount << std::endl;
}

void choices (int number){

	Controller controller;
	SampleListener listener;

	std::cout << "Point a number for the mission you want to take. \n";
	std::cout << "1. Delivery of groceries to Mother. \n";
	std::cout << "2. Complete a quest with Dora the Explorer. \n";
	std::cout << "3. Battle the dragon in an epic battle of Rock, Paper, Scissors. \n";
	std::cout << "4. Exit the game. \n";
	std::cout << "Choose. Choose now: ";
	std::cout << std::endl; //Extra Space for clarity.

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();
	int fingerCount = fingers.extended().count();

	if (number == 1){
		clearScreen();
		motherGame();
	}
	else if (number == 2){
		clearScreen();
		doraGame();
	}
	else if (number == 3){
		clearScreen();
		rockPaperScissors();
	}
	else if (number == 4){
		std::cout << "Fine. Goodbye. \n";
		exit(1);
	}
	else{
		clearScreen();
		std::cout << "You have choosen something invalid. Pick a different number.\n";
		frame = controller.frame();
    	finger = frame.finger(frame.id());
    	fingers = frame.fingers();
		fingerCount = fingers.extended().count();
		std::cout << fingerCount << std::endl;
	}
	choices(fingerCount);
}

int main(int argc, char** argv) {

	srand(time(NULL));
	
	SampleListener listener;
	Controller controller;

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();

    controller.addListener(listener);
	int fingerCount = 0;

	// Code for the game menu
	choices(fingerCount);

    // Remove the sample listener when done
    controller.removeListener(listener); 

	return 0;

}
