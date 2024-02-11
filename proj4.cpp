/**********************************************
 ** File: proj4.cpp
 ** Project: CMSC 202 Project 4, Spring 2023
 ** Author: Joshua Hur
 ** Date: 04/20/23
 ** Section: 42
 ** E-mail: jhur1@umbc.edu
 **
 ** This is the program file for Project 4.
 ** This program provides a player with a game environment called the UMBC Bloons game.
 ** Throughout the game, the player is going to defend the player's tower from bloons by hiring different types of  monkeys.
 ************************************************************************/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  srand (time(NULL));
  Game g;
  g.StartGame();
  return 0;
}
