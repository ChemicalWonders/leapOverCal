#ifndef __DATINGSIMS_H___
#define __DATINGSIMS_H___

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Leap.h"
#include "SampleListener.h"

using namespace std;

const bool CLEAR_SCREEN_DS = true;

//@brief Utilizes an escape character sequence to clear the screen.
void clearScreenDatingSims() {
	cout << endl;

	if (CLEAR_SCREEN_DS)
	{
		cout << "\033c" << endl;
    }

    cout << endl;
}

//Rock Paper Scissors File for the Leap Motion Game

class DatingSims {

	private:
		int rashida_happiness;
		int human_looks;
		string restraunt;
	public:
		DatingSims();
		void roll_looks();
		void dinner_date();
		void dinner_continue();
		void check_happiness();
		void start_game();
		void end_game();
		void mission_accomplished();
		void returning_to_main_menu();
};

DatingSims::DatingSims()
: rashida_happiness(0), human_looks(0), restraunt("")
{}

void DatingSims::roll_looks() {
	int number = rand() % 10+1;
	human_looks = number;


	cout << "On the scale from 1-10, you are a " << human_looks << ".\n";
	if(human_looks > 6)
	{
		int happinessGrowth = human_looks*2;
		cout << "You are a nice looking guy! Rashida's happiness grew by " << happinessGrowth << "!\n";
		rashida_happiness += happinessGrowth;
	}


	else if(human_looks <= 6 && human_looks >= 4)
	{
		cout << "Because of your sub-par looks, Rashida's happiness has depleted to -10\n";
		rashida_happiness -= 10;
	}


	else 
	{
		cout << "You are hideous. Rashida storms away...\n";
		end_game();
	}
}//


void DatingSims::dinner_date(){
	//TODO with Leap Motion
	//Leap Motion Code

	//THIS IS BROKEN

	Controller controller;
	SampleListener listener;

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();
	int fingerCount = fingers.extended().count();

	cout << "What star restraunt would you like to take her?\n";
	cout << "Use ur hands to choose 1-5 stars\n";
	cout << "Press ENTER when you have decided. Please wait up to 1 second for the Leap Motion to detect your hands.\n";

	while (!cin.get()){
		fingerCount = fingers.extended().count();
		std::cout << fingerCount << std::endl;
	}
	if (fingerCount == 1){
		rashida_happiness -= 10;
		restraunt = "McDonalds";
		cout << "You take Rashida to McDonalds.. -10 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else if (fingerCount == 2)
	{
		restraunt = "Olive Garden";		
		rashida_happiness -= 5;
		cout << "You take Rashida to Olive Garden.. -5 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else if (fingerCount == 3){
		restraunt = "Bud Namu Korean BBQ";
		cout << "You take Rashida to Bud Namu Korean BBQ.\n";
	}
	else if (fingerCount == 4)
	{
		restraunt = "Lawry's Steak House";
		rashida_happiness += 10;
		cout << "You take Rashida to Lawry's Steak House. +10 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else if (fingerCount == 5){
		restraunt = "Alain Ducasse at the Dorchester";
		rashida_happiness += 15;
		cout << "Big Ballin! You take Rashida to 5* Alain Ducasse at the Dorchester in London. +15 points. Her happiness is now " << rashida_happiness <<
		".\n";
	}
	else{
		cout << "The Leap Motion did not identify your position. Please try again.\n";
		dinner_date();
	}

	return;
}

void DatingSims::dinner_continue(){
	if(rashida_happiness < 15)
	{
		cout << "The date is not going so well, you need to step up your game!\n";
	}
	else
	{
		cout << "The date is going well so far, keep it up player.\n";
	}
}

void DatingSims::check_happiness() {
	if(rashida_happiness <= 0)
	{
		end_game();
	}
	if(rashida_happiness >= 100)
	{
		mission_accomplished();
	}
}
void DatingSims::start_game(){
	cout << "You somehow got a blind dinner date with the beautiful Rashida Jones.\n";
	cout << "Your mission is to get her happiness over 100 and win her heart <3\n";
	cout << "First let's see if you were born with good looks or not..\n";
	roll_looks();
	dinner_date();
	dinner_continue();
	dinner_date();
	dinner_date();
	dinner_continue();
	dinner_date();
	dinner_date();
	check_happiness();
}

void DatingSims::end_game(){
	cout << "Rashida is very disappointed in you. It's time to find someone else to date.\n";
	returning_to_main_menu();
}

void DatingSims::mission_accomplished() {

	cout << "Rashida is very excited! You're thinking about asking her out, and she says 'YES!' \n";
	returning_to_main_menu();

}

void DatingSims::returning_to_main_menu(){
	char yn = '0';
	cout << "Would you like to play? (y/n): ";
	cin >> yn;

	if(yn != 'n'){
		start_game();
	}
	return;
}

#endif