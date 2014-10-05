#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <iostream>
#include <string>

using namespace std;

class monster{
	private:
		int HP; //Monster HP levels
		int ATK; //Monster ATK power
		int level; //Monster level
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

		//Names the monster
		void nameMonster(string );

		//Returns the monster's name
		string monsterName();

};

monster::monster()
: HP(100), ATK(10), level(1), name("Aaron")
{}

monster::monster(int hplevel, int atklevel, int levelvalue, string nameValue)
: HP(hplevel), ATK(atklevel), level(levelvalue), nameValue(name)
{}

int monster::level(){
	return monster.level;
}

int monster::monster_hits(){
	int damage = 0;
	damage = level*ATK + 5;

	return damage;
}

void monster::nameMonster(string nameV){
	name = nameV;
}

string monster::monsterName(){
	return monster.name;
}

#endif