#include "Battler.h"

#include <iostream>
#include <random>
#include <sstream>

#include "Characters/Character.h"
#include "Characters/Enemy.h"
#include "Characters/SizesType.h"

Battler::Battler(const std::string& playerName, int enemies_amount, uint32_t seed)
{
    _random_seed = seed;
    _rng.seed(_random_seed);
    std::uniform_int_distribution<uint32_t> size_dist(0, SizesType::SIZES_LENGTH-1);
    _enemiesAmount = enemies_amount;

    _playerCharacter = Character(playerName, _maxHealth, _maxDamage, static_cast<SizesType::Sizes>(size_dist(_rng)));
}

void Battler::CreateEnemies()
{
    _enemies = std::vector<Enemy>(_enemiesAmount);

    _rng.seed(_random_seed);
    std::uniform_int_distribution<uint32_t> size_dist(0, SizesType::SIZES_LENGTH-1);
    std::uniform_int_distribution<uint32_t> health_dist(1, _maxHealth);
    std::uniform_int_distribution<uint32_t> damage_dist(1, _maxDamage);

    for (int i = 0; i < _enemiesAmount; ++i)
    {
        _enemies[i] = Enemy(health_dist(_rng), damage_dist(_rng), static_cast<SizesType::Sizes>(size_dist(_rng)));
    }
}

Enemy& Battler::NextEnemy()
{
    if (!HasAliveEnemy())
    {
        return _enemies[_currentEnemy];
    }

    _currentEnemy = (_currentEnemy + 1) % _enemiesAmount;

    if (_enemies[_currentEnemy].IsAlive())
    {
        return _enemies[_currentEnemy];
    }

    return NextEnemy();
}

bool Battler::HasAliveEnemy()
{
    for (int i = 0; i < _enemiesAmount; ++i)
    {
        if (_enemies[i].IsAlive())
        {
            return true;
        }
    }

    return false;
}

void Battler::Battle(Human& a, Human& b)
{
    b.DoDamage(a.GetDamage());

    if (!b.IsAlive())
        return;

    a.DoDamage(b.GetDamage());
}

void Battler::Execute()
{
    CreateEnemies();

    while (_playerCharacter.IsAlive() && HasAliveEnemy())
    {
        Battle(_playerCharacter, NextEnemy());
    }
}

void Battler::PrintResults()
{
    std::cout << (_playerCharacter.IsAlive() ? "You Win!" : "You Lose!");
    std::cout << "\nEnemies Slain:";

    for (int i = 0; i < SizesType::SIZES_LENGTH; ++i)
    {
        std::cout << "\n" + SizesType::ToString(static_cast<SizesType::Sizes>(i)) + ":\t";
        int count = 0;
        int total = 0;
        for (int j = 0; j < _enemiesAmount; ++j)
        {
            if (_enemies[j].GetSize() != i)
            {
                continue;
            }

            total ++;

            if (_enemies[j].IsAlive())
            {
                continue;
            }

            count++;
        }
        std::cout << std::to_string(count) + "/" + std::to_string(total);
    }
}
