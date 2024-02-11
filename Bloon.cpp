/**********************************************
 ** File: Bloon.cpp
 ** Project: CMSC 202 Project 4, Spring 2023
 ** Author: Joshua Hur
 ** Date: 04/20/23
 ** Section: 42
 ** E-mail: jhur1@umbc.edu
 **
 ** This is one of the programs file for Project 4.
 ** This file provides a player with an inital characteristic of a bloon
 ************************************************************************/

#include "Bloon.h"

// Bloon
// Default constructor
Bloon::Bloon() : m_health(0), m_location(0) {}

// Bloon
// Overloaded constructor
Bloon::Bloon(int health, int location) : m_health(health), m_location(location) {}

// ~Bloon
// Virtual deconstructor
Bloon::~Bloon() {}

// GetHealth
// Returns health of bloon
int Bloon::GetHealth() {
    return m_health;
}

// SetHealth
// Sets health of bloon
void Bloon::SetHealth(int health) {
    m_health = health;
}

// GetLocation
// Returns location of bloon
int Bloon::GetLocation() {
    return m_location;
}

// SetLocation
// Sets location of bloon
void Bloon::SetLocation(int location) {
    m_location = location;
}

// Overloaded <<
// Prints the details of a bloon
ostream& operator << (ostream& os, Bloon& bloon) {
    os << "Bloon Color: " << bloon.GetColor() << "Health: " << bloon.GetHealth() << "Location: " << bloon.GetLocation() << endl;
    
    return os;
}
