/**********************************************
 ** File: Bomb.cpp
 ** Project: CMSC 202 Project 4, Spring 2023
 ** Author: Joshua Hur
 ** Date: 04/20/23
 ** Section: 42
 ** E-mail: jhur1@umbc.edu
 **
 ** This is one of the programs file for Project 4.
 ** This file provides a player with an detailed characteristic of a Bomb monkey
 ************************************************************************/

#include "Bomb.h"

// Bomb
// Default constructor
Bomb::Bomb() : Monkey("Bomb", 3, 0) {}

// Bomb(string type, int damage, int location)
// Creates a Bomb monkey
Bomb::Bomb(string type, int damage, int location) : Monkey(type, damage, location) {}

// ~Bomb
// Virtual destructor
Bomb::~Bomb() {}

// Attack
// Hits all the bloons in the same location and returns total bloon health or damage for money
int Bomb::Attack(vector<Bloon*> bloons) {
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
    }
    return newHealth;
}

