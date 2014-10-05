#ifndef __RPSG_H___
#define __RPSG_H___

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Leap.h"
#include "SampleListener.h"

using namespace std;

const bool CLEAR_SCREEN_RPSG = true;

//@brief Utilizes an escape character sequence to clear the screen.
void clearScreenRPSG() {
	cout << endl;

	if (CLEAR_SCREEN_RPSG)
	{
		cout << "\033c" << endl;
    }

    cout << endl;
}

//Rock Paper Scissors File for the Leap Motion Game

class RPSG {

	private:
		int CPU_number;
		int human_number;
	public:
		RPSG();
		RPSG(int, int);
		void rollCPU_number();
	 	void determine_human_number();
		void win_or_loss();
		void first_game();
		void returning_to_main_menu();
};

RPSG::RPSG()
: CPU_number(0), human_number(0)
{}

RPSG::RPSG(int cpu, int human)
: CPU_number(cpu), human_number(human)
{}

void RPSG::rollCPU_number(){
	int number = rand() % 3 + 1;
	CPU_number = number;
}

void RPSG::determine_human_number(){
	//TODO with Leap Motion
	//Leap Motion Code

	Controller controller;
	SampleListener listener;

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();
	int fingerCount = fingers.extended().count();

	clearScreenRPSG();

	cout << "Extend your fingers in Rock, Paper, Scissors format.\n";
	cout << "0 fingers for Rock, 5 fingers for Paper, and 2 fingers for scissors!\n";
	cout << "Press ENTER when you have decided. Please wait up to 1 second for the Leap Motion to detect your hands.\n";

	while (!cin.get()){
		fingerCount = fingers.extended().count();
		//std::cout << fingerCount << std::endl;
	}

	if (fingerCount == 0){
		human_number = 1;
		cout << human_number;
	}
	else if (fingerCount == 5)
	{
		human_number = 2;
		cout << human_number;

	}
	else if (fingerCount == 2){
		human_number = 3;
		cout << human_number;
	}
	else{
		cout << "The Leap Motion did not identify your position. Please try again.\n";
		determine_human_number();
	}
	return;

	//Entering in numbers code. Remove the comments on this portion if you want to play with the numbers instead.
	/*
	int number = 0;
	cout << "pick a number\n";
	cin >> number;
	human_number = number;
	*/
}

void RPSG::win_or_loss(){

	// Number 1 is Rock, Number 2 is Paper, Number 3 is Scissors.
	if (CPU_number == 1){
		if (human_number == 1){
			cout << "It's a tie." << endl;
			returning_to_main_menu();
		}
		else if (human_number == 2){
			cout << "You lost. :(" << endl;
			returning_to_main_menu();
		}
		else if (human_number == 3){
			cout << "You won!" << endl;
			returning_to_main_menu();
		}
	}
	else if (CPU_number == 2){
		if (human_number == 2){
			cout << "It's a tie." << endl;
			returning_to_main_menu();
		}
		else if (human_number == 3){
			cout << "You lost. :(" << endl;
			returning_to_main_menu();
		}
		else if (human_number == 1){
			cout << "You won!" << endl;
			returning_to_main_menu();
		}
	}
	else if (CPU_number == 3){
		if (human_number == 3){
			cout << "It's a tie." << endl;
			returning_to_main_menu();
		}
		else if (human_number == 1){
			cout << "You lost. :(" << endl;
			returning_to_main_menu();
		}
		else if (human_number == 2){
			cout << "You won!" << endl;
			returning_to_main_menu();
		}
	}

}

void RPSG::first_game(){
	rollCPU_number();
	determine_human_number();
	win_or_loss();
}

void RPSG::returning_to_main_menu(){
	char yn = '0';
	cout << "Would you like to play? (y/n): ";
	cin >> yn;

	if(yn != 'n'){
		first_game();
	}
	return;
}


#endif