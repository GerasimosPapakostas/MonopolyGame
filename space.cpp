#include <iostream>
#include <string>
#include "space.h"

using namespace std;


//Empty Constructor
Space::Space(int id, string name, SpaceType type, string actionText) {
	this->id = id;
	this->name = name;
	this->type = type;
	this->actionText = actionText;
	this->owner = NULL;
}

//************* Setters ****************

void Space::setOwner(Player *owner) { // 0,1,-1 !!!!!!!!!!!!!!!!!!!!!!!
	this->owner = owner;
}

//**************** Getters ******************

int Space::getId() {
	return this->id;
}

string Space::getName() {
	return this->name;
}

string Space::getActionText() {
	return this->actionText;
}

bool Space::typeIs(SpaceType type) {
	return this->type == type;
}

bool Space::ownerIs(Player* owner) {
	return this->owner == owner;
}



Property::Property(int id, string name, SpaceType type, string actionText, int buyCost, int upgradeCost, PropertyCategory category) : Space(id, name, type, actionText) {
	this->buyCost = buyCost;
	this->upgradeCost = upgradeCost;
	this->category = category;
	this->numberOfHouses = 0;
}

//************* Setters ****************

void Property::setRent(int numberOfHouses, int inputRent) {
	this->rent[numberOfHouses] = inputRent;
}

//**************** Getters ******************

int Property::getBuyingCost() {
	return this->buyCost;
}

int Property::getUpgradeCost() {
	return this->upgradeCost;
}

int Property::getNumberOfHouses() {
	return this->numberOfHouses;
}

PropertyCategory Property::getCategory() {
	return this->category;
}

int Property::getRent() {
	return this->rent[numberOfHouses];
}

void Property::addHouse() {
	++this->numberOfHouses;
}



RailRoad::RailRoad(int id, string name, SpaceType type, string actionText, int buyCost) : Space(id, name, type, actionText) {
	this->buyCost = buyCost;
}

//************* Setters ****************

void RailRoad::setRent(int numberOfRailRoads, int inputRent) {
	this->rent[numberOfRailRoads] = inputRent;
}

//**************** Getters ******************

int RailRoad::getBuyingCost() {
	return this->buyCost;
}

int RailRoad::getRent() {
	return this->rent[owner->getNumberOfRailRoadsOwned()];
}



Utility::Utility(int id, string name, SpaceType type, string actionText, int buyCost, Dice* dice) : Space(id, name, type, actionText) {
	this->buyCost = buyCost;
	this->dice = dice;
}

//************* Setters ****************

void Utility::setRentMultiplier(int numberOfUtilities, int inputRentMultiplier) {
	this->rentMultiplier[numberOfUtilities] = inputRentMultiplier;
}

//**************** Getters ******************

int Utility::getBuyingCost() {
	return this->buyCost;
}

int Utility::getRent() {
	return (this->dice->getFirstDice() + this->dice->getSecondDice()) * this->rentMultiplier[owner->getNumberOfUtilitiesOwned()];
}



Tax::Tax(int id, string name, SpaceType type, string actionText, int tax) : Space(id, name, type, actionText) {
	this->tax = tax;
}

//**************** Getter ******************

int Tax::getTax() {
	return this->tax;
}
