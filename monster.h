#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <iostream>
#include <string>

using namespace std;

class monster{
	private:
		int HP; //Monster HP levels
		int ATK; //Monster ATK power
		int LV; //Monster level
		string name; //Monster name

	public:
		//Constructor
		monster();

		//Completed contstructor
		monster(int, int, int, string);

		//Returns the level of the monster;
		int level();

		//Returns the amount of damage dealt to the person
		int monster_hits();

		int returnHP();

		//Add or Subtract Damage from HP of monster
		void damage(int );

		//Names the monster
		void nameMonster(string);

		//Returns the monster's name
		string monsterName();

};

monster::monster()
: HP(100), ATK(10), LV(1), name("Aaron")
{}

monster::monster(int hplevel, int atklevel, int levelvalue, string nameValue)
: HP(hplevel), ATK(atklevel), LV(levelvalue), name(nameValue)
{}

int monster::level(){
	return LV;
}

int monster::returnHP(){
	return HP;
}

int monster::monster_hits(){
	int damage = 0;
	damage = -LV*ATK + 5;

	return damage;
}

void monster::damage(int damageValue){
	HP = HP + damageValue;
	cout << "You dealt " << damageValue << " to " << name << ".\n";
}

void monster::nameMonster(string nameV){
	name = nameV;
}

string monster::monsterName(){
	return name;
}

#endif