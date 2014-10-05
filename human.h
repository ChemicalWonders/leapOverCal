#ifndef __HUMAN_H__
#define __HUMAN_H__


#include <iostream>
#include <string>
//#include "monster.h"

using namespace std;

class human{
	private:
		int hp; // Health Points
		int mp; // Mana Points
		int gold_amount; // amount of gold that the character has on hand.
		float luck; // Amount of luck that the person has. Will change from room to room based on algorithm.
		double game_points; // Game Score Points
		double bonus; // Bonus points calculated at the end, can lose points based on Algorithm.
		string nameOfCharacter;	// Name of the person

	public:
		// Constructor
		human();

		// Custom Constructor
		human(double hpmax, double mpmax, int gold_amount_value, float luck_value, double game_points_value);

		//Determines the amount of luck that the person has. Will change from room to room.
		void determine_luck();

		//Print out luck value.
		void print_luck();

		//Determine the amount of game points.
		void determine_gamepoints(double & gamePoints);

		//Print out game points.
		void print_gamepoints();

		//Determines the amount of points at the end of the game; bonus points.
		//void determine_bonuspoints(double & bonus);

		//Used in the beginning to name your character.
		void nameCharacter();
};

human::human()
: hp(100), mp(100), gold_amount(1000), luck(100.0), game_points(0), bonus(0), nameOfCharacter("Ash")
{}

human::human(double hpmax, double mpmax, int gold_amount_value, float luck_value, double game_points_value)
: hp(hpmax), mp(mpmax), gold_amount(gold_amount_value), luck(luck_value), game_points(game_points_value), bonus(0), nameOfCharacter("Ash")
{}

void human::determine_luck(){
	float luckValue = rand() % 100 + 1;
	luckValue = luckValue / 5;
	luck = luckValue;
}

void human::print_luck(){
	cout << "You're luck value is: " << luck << endl;
}

void human::determine_gamepoints(double & gamePoints){
	//gamePoints = gamePoints + monster.level() * 0.5;
}

void human::print_gamepoints(){
	cout << "You currently have " << game_points << " points.\n";
}

/*void human::determine_bonuspoints(double & bonus){
	bonus = (monster.kill_streak() * monster.hit_accuracy()) * 5;
}
*/
void human::nameCharacter(){
	string name;

	cout << "Name your character (Use your keyboard for this!): ";
	cin >> name;

	nameOfCharacter = name; //Renames the character.
}

#endif
