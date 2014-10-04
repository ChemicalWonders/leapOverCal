#include <iostream>
#include <string>
#include "Leap.h"
#include "./RPSG.h"

using namespace Leap;

void motherGame(){
	std::cout << "Hello. This is mother.";
}

void doraGame(){
	std::cout << "Time to help Dora the Explorer with a little project";

}

void rockPaperScissors(){
	RPSG rpsg;

	std::cout << "Time to battle the dragon, are you ready? Press Enter to continue.";
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
	//mint fingerCount = fingers.extended().count();
	//std::cout << fingerCount << std::endl;
}

void choices (int number){

	SampleListener listener;
	Controller controller;

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
		Frame frame = controller.frame();
    	Finger finger = frame.finger(frame.id());
    	FingerList fingers = frame.fingers();

    	controller.addListener(listener);
		int fingerCount = fingers.extended().count();

		choices(fingerCount);
	}
}


int main(int argc, char** argv) {

	srand(time(NULL));
	
	SampleListener listener;
	Controller controller;

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();

    controller.addListener(listener);
	int fingerCount = fingers.extended().count();

	// Code for the game menu

	while (fingerCount != 4){

		std::cout << "Point a number for the mission you want to take. \n";
		std::cout << "1. Delivery of groceries to Mother. \n";
		std::cout << "2. Complete a quest with Dora the Explorer. \n";
		std::cout << "3. Battle the dragon in an epic battle of Rock, Paper, Scissors. \n";
		std::cout << "4. Exit the game. \n";

		std::cout << "Choose. Choose now: ";

		std::cout << std::endl; //Extra Space for clarity.

		
		choices(fingerCount);
		std::cout << std::endl;
	}

    // Remove the sample listener when done
    controller.removeListener(listener);

	return 0;

}
