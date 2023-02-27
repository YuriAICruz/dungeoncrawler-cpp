
#include <iostream>
#include <sstream>

#include "Battler/Battler.h"

int MAX_ENEMIES = 100000;

int main(int argc, char* argv[])
{
    std::string playerName;
    std::string input;
    std::stringstream stream;
    
    std::cout << "Set character name:\n";
    std::cin >> playerName;
    
    int enemiesAmount = 0;
    while (enemiesAmount <= 0 || enemiesAmount >= MAX_ENEMIES)
    {
        std::cout << "How many enemies:\n";
        std::cin >> input;
        
        stream.clear();
        stream.str(std::string());

        stream << input;
        stream >> enemiesAmount;
        if(enemiesAmount <= 0 || enemiesAmount >= MAX_ENEMIES)
        {
            std::cout << "invalid amount, must be a number, higher than 0 and lower than " + std::to_string(MAX_ENEMIES) + "\n";
        }
    }

    int32_t seed = -1;
    while (seed <= 0)
    {
        std::cout << "please input a seed:\n";
        std::cin >> input;

        for (int i = 0, n = input.length(); i < n; ++i)
        {
            seed += input[i];
        }
    }
    
    Battler battle = Battler(playerName, enemiesAmount, seed);

    battle.Execute();

    battle.PrintResults();
    
    return 0;
}
