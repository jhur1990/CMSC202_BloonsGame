/**********************************************
 ** File: Dart.cpp
 ** Project: CMSC 202 Project 4, Spring 2023
 ** Author: Joshua Hur
 ** Date: 04/20/23
 ** Section: 42
 ** E-mail: jhur1@umbc.edu
 **
 ** This is one of the programs file for Project 4.
 ** This file provides a player with an detailed characteristic of a Dart monkey
 ************************************************************************/

#include "Dart.h"

// Dart
// Default constructor
Dart::Dart() : Monkey("Dart", 1, 0) {}

// Dart(string type, int damage, int location)
// Creates a new Dart monkey
Dart::Dart(string type, int damage, int location) : Monkey(type, damage, location) {}

// ~Dart
// Virtual destructor
Dart::~Dart() {}

// Attack
// Hits first bloon in the same location as dart and returns total bloon health or damage for money
int Dart::Attack(vector<Bloon*> bloons) {
    int newHealth = 0; // Bloon's new health after pops
    
    for (Bloon* bloon : bloons) {
        if (bloon->GetHealth() > 0) {
            
            // Checks if damage is more than bloon's health or not
            if (GetDamage() >= bloon->GetHealth()) {
                bloon->SetHealth(0);
                newHealth = 0;
                
            } else {
                bloon->SetHealth(bloon->GetHealth() - GetDamage());
                newHealth = bloon->GetHealth();
            }
        }
        break;
    }
    return newHealth;
}
