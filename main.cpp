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
    Finger::Type fingerType = finger.type();

    std::cout << fingerType << std::endl;



	//int fingercounter = fingers.count();
}

int64_t lastFrameID = 0;

void processFrame( Frame frame )
{
    if( frame.id() == lastFrameID ) return;
    //...
    lastFrameID = frame.id();
}

int64_t lastProcessedFrameID = 0;

void nextFrame( Controller controller )
{
    int64_t currentID = controller.frame().id();
    for( int history = 0; history < currentID - lastProcessedFrameID; history++)
    {
        processFrame( controller.frame(history) );
    }
    lastProcessedFrameID = currentID;
}

void processNextFrame( Leap::Frame frame )
{
    if( frame.isValid() )
    {
        //...
    }
}

int main(int argc, char** argv) {

	srand(time(NULL));
	
	SampleListener listener;
	Controller controller;

	controller.addListener(listener);
	Frame current = controller.frame();
	FingerList allfingers = current.fingers();

	RPSG::first_game();

	// Code for the game menu

	/*for (int f = 0; f < current.fingers().count(); f++) {
        std::cout << current.fingers()[f] << std::endl;
        //fingerCount = controller.fingers().count();
        //std::cout << fingerCount;
    }
	while (fingerCount != 4){

		std::cout << "Point a number for the mission you want to take. \n";
		std::cout << "1. Delivery of groceries to Mother. \n";
		std::cout << "2. Complete a quest with Dora the Explorer. \n";
		std::cout << "3. Battle the dragon in an epic battle of Rock, Paper, Scissors. \n";
		std::cout << "4. Exit the game. \n";

		std::cout << "Choose. Choose now: ";

		std::cout << std::endl; //Extra Space for clarity.

		choices(fingerCounter);
		std::cout << std::endl;
	}*/

    // Remove the sample listener when done
    controller.removeListener(listener);

	return 0;

}
