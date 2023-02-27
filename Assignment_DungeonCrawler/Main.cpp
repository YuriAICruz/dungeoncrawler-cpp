
#include <iostream>
#include <sstream>

#include "Battler/Battler.h"

int main(int argc, char* argv[])
{
    std::string playerName;
    std::string input;
    std::stringstream stream;
    
    std::cout << "Set character name:\n";
    std::cin >> playerName;

    std::cout << "How many enemies:\n";
    std::cin >> input;
    
    stream << input;
    int enemiesAmount;
    stream >> enemiesAmount;

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
