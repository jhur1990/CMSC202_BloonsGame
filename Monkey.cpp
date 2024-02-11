/**********************************************
 ** File: Monkey.cpp
 ** Project: CMSC 202 Project 4, Spring 2023
 ** Author: Joshua Hur
 ** Date: 04/20/23
 ** Section: 42
 ** E-mail: jhur1@umbc.edu
 **
 ** This is one of the programs file for Project 4.
 ** This file provides a player with an initial characteristics of monkey
 ************************************************************************/

#include "Monkey.h"

// Monkey
// Default constructor
Monkey::Monkey() : m_damage(0), m_type(""), m_location(0) {}

// Monkey(string type, int damage, int location)
// Overloaded constructor
Monkey::Monkey(string type, int damage, int location) : m_damage(damage), m_type(type), m_location(location) {}

// ~Monkey
// Virtual destructor
Monkey::~Monkey() {}

// GetDamage
// Returns damage of monkey
int Monkey::GetDamage() {
    return m_damage;
}

// GetType
// Returns types of monkey
string Monkey::GetType() {
    return m_type;
}

// GetLocation
// Returns location of monkey on track
int Monkey::GetLocation() {
    return m_location;
}

// SetDamage
// Sets damage of monkey
void Monkey:: SetDamage(int damage) {
    m_damage = damage;
}

// SetType
// Sets type of monkey (dart, bomb, or boomerang)
void Monkey::SetType(string type) {
    m_type = type;
}

// SetLocation
// Sets location of monkey on track
void Monkey::SetLocation(int location) {
    m_location = location;
}

// Overloaded <<
// Prints the details of a monkey
ostream& operator << (ostream& os, Monkey& monkey) {
    os << "Monkey Type: " << monkey.GetType() << "Damage: " << monkey.GetDamage() << "Location: " << monkey.GetLocation() << endl;
    
    return os;
}
