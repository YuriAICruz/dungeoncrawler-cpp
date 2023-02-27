#pragma once
#include <vector>

#include "Characters/Character.h"
#include "Characters/Enemy.h"

class Battler
{
private:
    void CreateEnemies();
    Enemy& NextEnemy();
    bool HasAliveEnemy();
    
public:
    Battler(const std::string& playerName, int enemies_amount, uint32_t seed = 123456);

    void Battle(Human& character, Human& enemy);

    void Execute();

    void SetMaxHealth(const int& health)
    {
        _maxHealth = health;   
    }

    void SetMaxDamage(const int& damage)
    {
        _maxDamage = damage;
    }

    void SetSeed(const uint32_t& seed)
    {
        _random_seed = seed;
    }

    void PrintResults();

private:
    int _enemiesAmount = 1;
    std::vector<Enemy> _enemies;
    Character _playerCharacter;
    int _maxHealth = 100;
    int _maxDamage = 10;
    uint32_t _random_seed;
    int _currentEnemy = 0;
    std::mt19937 _rng;
};
