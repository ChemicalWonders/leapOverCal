#ifndef __HUMAN_H__
#define __HUMAN_H__


#include <iostream>
#include <string>
#include "monster.h"

using namespace std;

class human{
	private:
		int hp; // Health Points
		int hpMAX;
		int level; //What level you are
		int luck; // Amount of luck that the person has. Will change from room to room based on algorithm.
		double game_points; // Game Score Points
		string nameOfCharacter;	// Name of the person

	public:
		// Constructor
		human();

		// Custom Constructor
		human(int hpmax, int hpMAXV, int level_value, double game_points_value );

		int HumanHP();

		int HumanMaxHP();

		void HPvalue(int);

		void humanAddLV(int);

		//Determines the amount of luck that the person has. Will change from room to room.
		void determine_luck();

		//Print out luck value.
		void print_luck();

		int luckpls();

		//Determine the amount of game points.
		void determine_gamepoints(double & gamePoints, monster &);

		//Print out game points.
		void print_gamepoints();

		//Returns the amount of damage done to monster
		int damage_to_monster();

		//Used in the beginning to name your character.
		void nameCharacter();
};

human::human()
: hp(300), hpMAX(501), level(5), game_points(0), nameOfCharacter("Ash")
{
	determine_luck();
}

human::human(int hpmax, int hpMAXV, int level_value, double game_points_value)
: hp(hpmax), hpMAX(hpMAXV), level(level_value), game_points(game_points_value), nameOfCharacter("Ash")
{
	determine_luck();
}

int human::HumanHP(){
	return hp;
}
int human::HumanMaxHP(){
	return hpMAX;
}

void human::HPvalue(int value){
	if (value + hp > hpMAX){
		hp = hpMAX;
	}
	else{
		hp = hp + value;
	}
}

void human::humanAddLV(int lvl){
	level = level + lvl;
}

void human::determine_luck(){
	int luckValue = rand() % 5 + 1;
	luck = luckValue;

	//print_luck();
}

void human::print_luck(){
	cout << "You're luck value is: " << luck << endl;
}

void human::determine_gamepoints(double & gamePoints, monster & mon){
	gamePoints = gamePoints + mon.level() * 0.5;
}

void human::print_gamepoints(){
	cout << "You currently have " << game_points << " points.\n";
}

int human::damage_to_monster(){
	int damage = 0;
	damage = -(luck * level + rand() % luck);
	//cout << "Your damage amount was: " << damage << endl;
	game_points += -damage;
	//cout << "Your game_points amount is: " << game_points << endl;

	return damage;
}

void human::nameCharacter(){
	string name;

	cout << "Name your character (Use your keyboard for this!): ";
	cin >> name;

	nameOfCharacter = name; //Renames the character.
}

int human::luckpls(){
	return luck;
}

#endif
