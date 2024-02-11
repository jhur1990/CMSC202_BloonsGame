/**********************************************
 ** File: Basic.cpp
 ** Project: CMSC 202 Project 4, Spring 2023
 ** Author: Joshua Hur
 ** Date: 04/20/23
 ** Section: 42
 ** E-mail: jhur1@umbc.edu
 **
 ** This is one of the programs file for Project 4.
 ** This file provides a player with an detailed characteristic of a basic bloon
 ************************************************************************/

#include "Basic.h"

// Basic
// Default Constructor
Basic::Basic() : Bloon() {
    SetHealth(1);
    m_color = "red";
}

// Basic(int health, int location)
// Creates a new basic bloon with health
Basic::Basic(int health, int location) : Bloon(health, location) {
    if (health == 1) {
        m_color = "red";

    } else if (health == 2) {
        m_color = "blue";
        
    } else if (health == 3) {
        m_color = "green";
        
    } else if (health == 4) {
        m_color = "yellow";
        
    } else if (health == 5) {
        m_color = "pink";
        
    } else {
        m_color = "black";
    }
}

// ~Basic
// Virtual Destructor
Basic::~Basic() {}

// Pop
// Changes the color of the bloon based on how many health it has left and returns number of pops that occurred
int Basic::Pop(int damage) {
    int pops = 1; // Number of pops
    
    if (GetHealth() > 0) {
        if (damage >= GetHealth()) {
            pops = GetHealth();
            
        } else {
            pops = damage;
        }
                  
        if (GetHealth() >= 6) {
            m_color = "black";
            
        } else if (GetHealth() == 5) {
            m_color = "pink";
            
        } else if (GetHealth() == 4) {
            m_color = "yellow";
            
        } else if (GetHealth() == 3) {
            m_color = "green";
            
        } else if (GetHealth() == 2) {
            m_color = "blue";
            
        } else if (GetHealth() == 1){
            m_color = "red";
        }
    }
    return pops;
}

// GetColor
// Returns the current color of a bloon
string Basic::GetColor() {
    return m_color;
}
