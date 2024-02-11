
#include "Game.h"

// Game
// Initializes the game variables of round, money, the player's life to defaults
Game::Game() : m_curRound(START_ROUND), m_curMoney(START_MONEY), m_curLife(START_LIFE) {}

// ~Game
// Deallocates any dynamically allocated memories in Game
Game::~Game() {
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        delete m_bloons[i];
    }
    
    for (unsigned int i = 0; i < m_monkeys.size(); i++) {
        delete m_monkeys[i];
    }
}

// PrintMap
// Prints the map that needed for the gameplay
void Game::PrintMap() {
    for (int i = 0; i < PATH_LENGTH; i++) {
        bool hasMonkey = false; // Checks if there's a monkey in the current map
        bool hasBloon = false; // Checks if there's a bloon in the current map

        cout << "**Location " << i + 1 << "**" << endl;
        cout << "--Monkeys--" <<endl;
        
        // Displays all the monkeys that are available
        for (unsigned int j = 0; j < m_monkeys.size(); j++) {
            if (m_monkeys[j] -> GetLocation() == i) {
                hasMonkey = true;
                cout << j + 1 << ". " << m_monkeys[j] -> GetType() << ": Location: " << i + 1 << " Damage: " << m_monkeys[j] -> GetDamage() << endl;
            }
        }
        
        // Shows "None" when there is no monkey available
        if (!hasMonkey) {
            cout << "None" << endl;
        }
        
        cout << "<<Bloons>>" << endl;
        
        // Displays all the populated bloons
        for (unsigned int j = 0; j < m_bloons.size(); j++) {
            if (m_bloons[j] -> GetLocation() == i) {
                hasBloon = true;
                cout << "Bloon: " << m_bloons[j] -> GetColor() << " Health: " << m_bloons[j] -> GetHealth() << endl;
            }
        }
        
        // Shows "None when there is no bloon available
        if(!hasBloon) {
            cout << "None" << endl;
        }
        
        cout << endl;
    }
}

// ImproveMonkey
// Improves damage of a selected monkey
void Game::ImproveMonkey() {
    int index; // Specific index of a monkey
    
    // Checks there is any monkey available to improve
    if (m_monkeys.size() == 0) {
        cout << "No monkey is available to improve" << endl;
        
    } else {
        cout << "Select the index of the monkey you would like to improve (1-" << m_monkeys.size() << ")" << endl;
        
        // Displays all the monkeys
        for (unsigned int i = 0; i < m_monkeys.size(); i++) {
            cout << i + 1 << ". " << m_monkeys[i] -> GetType() << ": Location: " << m_monkeys[i] -> GetLocation() + 1 << " Damage: " << m_monkeys[i] -> GetDamage() << endl;
        }
        
        cin >> index;
        
        // Checks the player's choose right monkey
        // If so, improves a selected monkey's damage
        if(index >= 1 && index <= (int) m_monkeys.size()) {
            m_monkeys[index - 1] -> SetDamage(m_monkeys[index - 1] -> GetDamage() + IMPROVE_VALUE);
            m_curMoney -= COST_IMPROVE;
            cout << m_monkeys[index - 1] -> GetType() << " in position " << index << " improved!" << endl;
            
        } else {
            cout << "Invalid index. No monkey was improved." << endl;
        }
    }
}

// BuyMonkey
// Hires a monkey that can pop bloons and places it on the map
void Game::BuyMonkey() {
    int choice; // Diffrent kinds of a monkey
    
    cout << "Which monkey would you like to buy?" << endl;
    cout << "1. Dart Monkey (Cost:" << COST_DART << ")" << endl;
    cout << "2. Boomerang Monkey (Cost:" << COST_BOOMERANG << ")" << endl;
    cout << "3. Bomb Monkey (Cost:" << COST_BOMB << ")" << endl;
    
    cin >> choice;
    
    // Checks there's enough money to buy different kinds of a monkey
    // If so, place it on the map by calling PlaceMonkey
    switch(choice) {
        case 1:
            if (m_curMoney >= COST_DART) {
                m_curMoney -= COST_DART;
                PlaceMonkey(choice);
            } else {
                cout << "Not enough money to buy a Dart Monkey." << endl;
            }
            break;
            
        case 2:
            if (m_curMoney >= COST_BOOMERANG) {
                m_curMoney -= COST_BOOMERANG;
                PlaceMonkey(choice);
            } else {
                cout << "Not enough money to buy a Boomerang Monkey." << endl;
            }
            break;
            
        case 3:
            if (m_curMoney >= COST_BOMB) {
                m_curMoney -= COST_BOMB;
                PlaceMonkey(choice);
            } else {
                cout << "Not enough money to buy a Bomb Monkey." << endl;
            }
            break;
            
        default:
            cout << "Invalid choice. No Monkey was purchased." << endl;
    }
}

// PlaceMonkey
// Places a monkey on the map
void Game::PlaceMonkey(int choice) {
    int location; // Location on the map
    
    cout << "Where would you like to place the new monkey (1-" << PATH_LENGTH << ")" << endl;
    cin >> location;
    
    // Creates a monkey and places it on the map
    if (location >= 1 && location <= PATH_LENGTH) {
        Monkey* newMonkey;
        
        // Creates Dart monkey
        if (choice == 1) {
            newMonkey = new Dart("Dart", DAMAGE_DART, location - 1);
        
        // Creates Boomerang monkey
        } else if (choice == 2) {
            newMonkey = new Boomerang("Boomerang", DAMAGE_BOOM, location - 1);
        
        // Creates Bomb monkey
        } else if (choice == 3) {
            newMonkey = new Bomb("Bomb", DAMAGE_BOMB, location - 1);
        }
        
        m_monkeys.push_back(newMonkey);
        cout << "New Monkey placed at location " << location << "." << endl;
        
    } else {
        cout << "Invalid location. No monkey was placed." << endl;
    }
}

// StartGame
// Displays a welcoming message and keeps calling MainMenu
void Game::StartGame() {
    cout << "Welcome to UMBC Bloons!" << endl;
    m_curRound = START_ROUND;
    m_curMoney = START_MONEY;
    m_curLife = START_LIFE;
    
    // Keeps loading MainMenu unless the player inputs 6
    while (MainMenu() != 6) {}
    
    cout << "Thanks for playing! Goodbye." << endl;
}

// MainMenu
// Display menu
int Game::MainMenu() {
    int MainMenuChoice; // The player's menu choice
    bool keepPlaying = true; // Is program running
    
    // Game end condition when the player's lose all of their life
    if (m_curLife <= 0) {
        cout << "Sorry, you have lost the game" << endl;
        return 6;
    }
    
    // Menu
    while (m_curLife > 0 && keepPlaying) {
        cout << "What would you like to do?" << endl;
        cout << "1. View Map" << endl;
        cout << "2. Buy New Monkey" << endl;
        cout << "3. Improve Existing Monkey" << endl;
        cout << "4. Progress Round" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: " << endl;
        
        cin >> MainMenuChoice;
        
        switch (MainMenuChoice) {
            case 1:
                // Prints a map
                PrintMap();
                break;
                
            case 2:
                // Buy a monkey
                BuyMonkey();
                break;
                
            case 3:
                // Upgrade a monkey
                ImproveMonkey();
                break;
                
            case 4:
                // Gameplay flow
                PlayRound();
                break;
                
            case 5:
                // Displays the current game information
                Stats();
                break;
                
            case 6:
                // Quits the program
                keepPlaying = false;
                return 6;
                
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
    return 0;
}

// Stats
// Displays the current game information; round, number of monkeys, money, and the player's lives
void Game::Stats() {
    cout << "Current Round: " << m_curRound << endl;
    cout << "Number of Monkeys: " << m_monkeys.size() << endl;
    cout << "Money: " << m_curMoney << endl;
    cout << "Lives Left: " << m_curLife << endl;
}

// PlayRound
// Gameplay flow of round progression
void Game::PlayRound() {
    cout << "Starting Round " << m_curRound << endl;
    
    // Populates bloons in the initial location
    PopulateBloons();
    
    // Monkeys attack bloons
    ResolveBattle();
   
    // All the bloons moves to the next location
    MoveBloons();
    
    // Removes bloons that is equal to or less than 0
    for (int i = 0; i < 5; i++) {
        RemovePopped();
    }
    
    // Checks if bloons are survived and reaches the player's tower
    for (int i = 0; i < 5; i++) {
        CheckPath();
    }

    cout << "Round " << m_curRound << " Completed" << endl;
    m_curRound++;
}

// PopulateBloons
// Creates bloons in each round
void Game:: PopulateBloons() {
    for (int i = 1; i <= m_curRound; i++) {
        Bloon *newBloon = new Basic(i, START_BLOON);
        m_bloons.push_back(newBloon);
        cout << "A new " << newBloon -> GetColor() << " bloon appears!" << endl;
    }
}

// ResolveBattle
// Each monkey attacks the bloons
void Game::ResolveBattle() {
    for (unsigned int j = 0; j < m_monkeys.size(); j++) {
        bool dartMonkeyAttacked = false; // Add a flag for Dart monkey

        for (unsigned int i = 0; i < m_bloons.size(); i++) {
            
            // Monkeys only can attack if the bloons are located in the same location
            if (m_bloons[i] && m_bloons[i] -> GetHealth() > 0 && m_bloons[i]->GetLocation() == m_monkeys[j]->GetLocation()) {
                int newHealth = 0; // Updated bloon's health after pops

                if (m_monkeys[j]->GetType() == "Boomerang") {
                    cout << "The boomerang monkey throws a boomerang!" << endl;
                    
                } else if (m_monkeys[j]->GetType() == "Dart" && !dartMonkeyAttacked) {
                    cout << "The dart monkey throws a dart!" << endl;
                    cout << "The " << m_bloons[i] -> GetColor() << " bloon pops!" << endl;
                    if (newHealth <= 0){
                        cout << "The bloon is now gone!" << endl;
                        
                    } else {
                        m_bloons[i]->SetHealth(newHealth);
                        cout << "The bloon is now " << m_bloons[i]->GetColor() << "."<< endl;
                    }
                    
                } else if (m_monkeys[j]->GetType() == "Bomb"){
                    cout << "The bomb shooter launches a bomb!" << endl;

                }
                
                if (m_monkeys[j]->GetType() == "Bomb" || m_monkeys[j]->GetType() == "Boomerang") {
                    cout << "The " << m_bloons[i] -> GetColor() << " bloon pops!" << endl;
                }
                    
                // Boomerang monkey's attacking ability
                if (m_monkeys[j]->GetType() == "Boomerang") {
                    vector<Bloon*> tempBloons1; // Copied bloon vector
                    tempBloons1.push_back(m_bloons[i]);
                    int oldHealth = m_bloons[i]->GetHealth(); // Saves original health before pops
                    newHealth = m_monkeys[j] -> Attack(tempBloons1);
                    
                    int moneyGained = 0; // Amount of money gained after bloons pop

                    // Checks all the money gained by popping
                    for (int h = oldHealth; h > newHealth; --h) {
                        moneyGained += m_bloons[i]->Pop(1);
                    }
                    
                    m_curMoney += moneyGained;
                
                // Bomb monkey's attacking ability
                } else if (m_monkeys[j]->GetType() == "Bomb") {
                    vector<Bloon*> tempBloons2; // Copied bloon vector
                    tempBloons2.push_back(m_bloons[i]);
                    int oldHealth = m_bloons[i]->GetHealth(); // Saves original health before pops
                    newHealth = m_monkeys[j] -> Attack(tempBloons2);
                    
                    int moneyGained = 0; // Amount of money gained after bloons pop

                    // Checks all the money gained by popping
                    for (int h = oldHealth; h > newHealth; --h) {
                        moneyGained += m_bloons[i]->Pop(1);
                    }
                    
                    m_curMoney += moneyGained;
                    m_bloons[i]->SetHealth(newHealth);
                    
                } else if (m_monkeys[j]->GetType() == "Dart" && !dartMonkeyAttacked) {
                    int moneyGained = 0; // Amount of money gained after bloons pop

                    vector<Bloon*> tempBloons5; // Copied bloon vector
                    tempBloons5.push_back(m_bloons[i]);
                    newHealth = m_monkeys[j] -> Attack(tempBloons5);
                    
                    moneyGained += m_bloons[i]->Pop(1);
                    
                    
                    m_curMoney += moneyGained;
                    dartMonkeyAttacked = true;
                }
                
                if (m_monkeys[j]->GetType() == "Bomb" || m_monkeys[j]->GetType() == "Boomerang"){
                    if (newHealth <= 0){
                        cout << "The bloon is now gone!" << endl;
                        
                    } else {
                        m_bloons[i]->SetHealth(newHealth);
                        cout << "The bloon is now " << m_bloons[i]->GetColor() << "."<< endl;
                    }
                }
            }
        }
    
                    
        // Boomerang monkey should attack one more time
        if (m_monkeys[j]->GetType() == "Boomerang") {
            for (unsigned int i = 0; i < m_bloons.size(); i++) {
                
                // Monkeys only can attack if the bloons are located in the same location
                if (m_bloons[i] && m_bloons[i] -> GetHealth() > 0 && m_bloons[i]->GetLocation() == m_monkeys[j]->GetLocation()) {
                    vector<Bloon*> tempBloons3; // Copied bloon vector
                    int newHealth = 0; // Updated bloon's health after pops
                    int moneyGained = 0; // Amount of money gained after bloons pop
                    
                    cout << "The " << m_bloons[i] -> GetColor() << " bloon pops!" << endl;
                    tempBloons3.push_back(m_bloons[i]);
                    int oldHealth = m_bloons[i]->GetHealth(); // Saves original health before pops
                    newHealth = m_monkeys[j] -> Attack(tempBloons3);
                    
                    // Checks all the money gained by popping
                    for (int h = oldHealth; h > newHealth; --h) {
                        moneyGained += m_bloons[i]->Pop(1);
                    }
                    
                    m_curMoney += moneyGained;

                    if (newHealth <= 0){
                        cout << "The bloon is now gone!" << endl;
                        
                    } else {
                        m_bloons[i]->SetHealth(newHealth);
                        cout << "The bloon is now " << m_bloons[i]->GetColor() << "."<< endl;
                    }
                }
            }
        }
    }
}

// RemovePopped
// Removes any bloons whose health is equal to or less than 0
void Game::RemovePopped() {
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        if (m_bloons[i] && m_bloons[i] -> GetHealth() <= 0) {
            delete m_bloons[i];
            m_bloons.erase(m_bloons.begin() + i);
            }
        }
    }

// MoveBloons
// All alive bloons move to the next location
void Game::MoveBloons() {
    cout << "The bloons move along the path" << endl;
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        m_bloons[i] -> SetLocation(m_bloons[i] -> GetLocation() + 1);
    }
}

// CheckPath
// Checks if alive bloons reaches the player's tower and deduct the player's life
void Game::CheckPath() {
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        if (m_bloons[i] -> GetLocation() >= PATH_LENGTH) {
            cout << "A bloon made it to the end of the path and you took " << m_bloons[i] -> GetHealth() << " damage." << endl;
            m_curLife -= m_bloons[i] -> GetHealth();
            delete m_bloons[i];
            m_bloons.erase(m_bloons.begin() + i);
        }
    }
}
