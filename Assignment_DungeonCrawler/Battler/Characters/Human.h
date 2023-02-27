#pragma once
#include "SizesType.h"


class Human
{
public:
    Human(int health, int damage, SizesType::Sizes size)
    {
        Health = health;
        Damage = damage;
        Size = size;
    }

    bool IsAlive() const { return Health > 0; }

    int& GetHealth(){ return Health; }
    
    void DoDamage(int damage);
    int& GetDamage(){ return Damage; }
    
    SizesType::Sizes& GetSize(){ return Size; }

private:
    int Health;
    int Damage;
    SizesType::Sizes Size;
};
