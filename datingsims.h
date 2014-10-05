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
		int fingerCount;
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
	/*

	Controller controller;
	SampleListener listener;

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();
	int fingerCount = fingers.extended().count();
	*/
	int fingerCount;
	cout << "What star restraunt would you like to take her?\n";
	cout << "Enter 1-5 to choose 1-5 stars\n";
	cout << "Press ENTER when you have decided.\n";
	cin >> fingerCount;
	cin.get();


	if (fingerCount == 1){
		rashida_happiness -= 10;
		restraunt = "McDonalds";
		//cout << "You take Rashida to McDonalds.. -10 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else if (fingerCount == 2)
	{
		restraunt = "Olive Garden";		
		rashida_happiness -= 5;
		//cout << "You take Rashida to Olive Garden.. -5 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else if (fingerCount == 3){
		restraunt = "Bud Namu Korean BBQ";
		//cout << "You take Rashida to Bud Namu Korean BBQ.\n";
	}
	else if (fingerCount == 4)
	{
		restraunt = "Lawry's Steak House";
		rashida_happiness += 10;
		//cout << "You take Rashida to Lawry's Steak House. +10 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else if (fingerCount == 5){
		restraunt = "Alain Ducasse at the Dorchester";
		rashida_happiness += 15;
		//cout << "Ballin! You take Rashida to 5* Alain Ducasse at the Dorchester in London. +15 points. Her happiness is now " << rashida_happiness << ".\n";
	}

	return;
}

void DatingSims::dinner_continue(){
	
	Controller controller;
	SampleListener listener;

	Frame frame = controller.frame();
    Finger finger = frame.finger(frame.id());
    FingerList fingers = frame.fingers();
	fingerCount = fingers.extended().count();
	
	cout << "You have brought her to " << restraunt << "\n";
	//put in gesture commands
	if(rashida_happiness < 15)
	{
		cout << "The date is not going so well, you need to step up your game!\n";
	}
	else
	{
		cout << "The date is going well so far, keep it up player.\n";
	}

	cout << "For the following questions during the date signal 1 for the first option or 2 for the second option\n";
	cout << "Are you 1) a pizza kind of guy or 2) a chicken and rice kind of guy?\n";
	while (!cin.get()){
		fingerCount = fingers.extended().count();
		//std::cout << fingerCount << std::endl;
	}
	if (fingerCount == 1){
		rashida_happiness += 20;
		cout << "Pizza!! Awesome, that's Rashida's favorite food! +20 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else //if (fingerCount == 2)
	{	
		rashida_happiness -= 5;	
		cout << "Chicken and rice? Boring... -5 points. Her happiness is now " << rashida_happiness << ".\n";
	}	/*
	else{
		cout << "The Leap Motion did not identify your position. Please try again.\n";
		cout << "Remember to either signal 1 or 2\n.";
		dinner_date();
	}*/
	cout << "A waiter is being rude to Rashida... do you 1) yell out the waiter and ask to see the manager or 2) play dead?\n";
	while (!cin.get()){
		fingerCount = fingers.extended().count();
		//td::cout << fingerCount << std::endl;
	}
	if (fingerCount == 1){
		rashida_happiness -= 5;
		cout << "Rashida looks at you like you're crazy... The poor waiter! -5 points. Her happines is now " << rashida_happiness << ".\n";
	}
	else //if (fingerCount == 2)
	{		
		rashida_happiness += 20;
		cout << "Rashida loves your sense of humor! She plays dead with you. +20 points. Her happiness is now " << rashida_happiness << ".\n";
	}	
	/*else{
		cout << "The Leap Motion did not identify your position. Please try again.\n";
		cout << "Remember to either signal 1 or 2\n.";
		dinner_date();
	}*/
	cout << "You were just served your meal! But you see a huge booger hanging out of Rashida's left nostril.. \n";
	cout << "Do you want to 1) tell her and save her from embarassment or 2) pretend like it isn't there\n";
	while (!cin.get()){
		fingerCount = fingers.extended().count();
		//std::cout << fingerCount << std::endl;
	}
	if (fingerCount == 1){
		rashida_happiness += 20;
		cout << "Rashida looks so embarassed... But she still smiles a bit and likes that you told her.\n";
		cout << "+20 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else //if (fingerCount == 2)
	{
		rashida_happiness -= 5;
		cout << "A stranger comes by and informs Rashida. She is mad you did not tell her that it was there\n"; 
		cout << "-5 points. Her happiness is now " << rashida_happiness << ".\n";
	}	
	/*else{
		cout << "The Leap Motion did not identify your position. Please try again.\n";
		cout << "Remember to either signal 1 or 2\n.";
	}*/
	cout << "The dinner is almost to end, your last chance to impress!\n";
	cout << "The dinner is getting kind of dull and you want to liven it up.\n";
	cout << "Do you want to 1) tell her a joke about engineers/mathematicians/physicians or 2) Talk about the League of Legends Quarterfinals last night?\n";	
	while (!cin.get()){
		fingerCount = fingers.extended().count();
		//std::cout << fingerCount << std::endl;
	}
	if (fingerCount == 1){
		rashida_happiness += 20;
		cout << "Hahaha, Rashida laughs a lot! She loves smart guys. +20 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else //if (fingerCount == 2)
	{
		rashida_happiness -= 5;
		cout << "She doesn't seem very interested. She's more interested by the fly buzzing around the room. -5 points. Her happiness is now " << rashida_happiness << ".\n";
	}	
	/*else{
		cout << "The Leap Motion did not identify your position. Please try again.\n";
		cout << "Remember to either signal 1 or 2\n.";
		dinner_date();
	}*/
	cout << "You guys have finally finished eating... And the check has arrived.\n";
	cout << "Do you want to 1) pay for the meal like a gentleman or 2) let her pay because she's a rich and famous actor, and you are on low income.\n";
	while (!cin.get()){
		fingerCount = fingers.extended().count();
		//std::cout << fingerCount << std::endl;
	}
	if (fingerCount == 1){
		rashida_happiness += 20;
		cout << "Good job! Rashida looks genuinely happy. +20 points. Her happiness is now " << rashida_happiness << ".\n";
	}
	else //if (fingerCount == 2)
	{
		rashida_happiness -= 5;
		cout << "Rashida looks a little dissapointed. You should have paid for her. -5 points. Her happiness is now " << rashida_happiness << ".\n";
	}/*	
	else{
		cout << "The Leap Motion did not identify your position. Please try again.\n";
		cout << "Remember to either signal 1 or 2\n.";
		dinner_date();
	}*/
	cout << "Your dinner date with Rashida Jones is over! Let's review how you did over the night and how she feels about you.\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	cout << ".....\n";
	check_happiness();
}

void DatingSims::check_happiness() {
	if(rashida_happiness >= 60)
	{
		mission_accomplished();
	}
	else
	{
		end_game();
	}
}
void DatingSims::start_game(){
	clearScreenDatingSims();
	cout << "You somehow got a blind dinner date with the beautiful Rashida Jones.\n";
	cout << "Your mission is to get her happiness over 60 and win her heart <3\n";
	cout << "First let's see if you were born with good looks or not..\n";
	roll_looks();
	dinner_date();
	dinner_continue();
}

void DatingSims::end_game(){
	cout << "Sorry, you are not worth of Rashida. You lost your once in a life chance.\n";
	cout << "You go home crying to your mother wishing you could have done something differently.\n";
	returning_to_main_menu();
}

void DatingSims::mission_accomplished() {
	cout << "Rashida is very excited! You're thinking about asking her out, and she says 'YES!'\n";
	cout << "Wait for the next game to come out, 'Taking Rashida to the Movies', we are excited for the release!\n";
	cout << "Also be looking out for 'Proposing to Rashida in Paris' coming out in 2018.\n";
	returning_to_main_menu();
}

void DatingSims::returning_to_main_menu(){
	char yn = '0';
	cout << "Would you like to give it another shot? (y/n): ";
	cin >> yn;

	if(yn != 'n'){
		start_game();
	}
	return;
}

#endif