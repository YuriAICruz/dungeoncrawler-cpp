#pragma once
#include <utility>
#include <xstring>

#include "Human.h"

class Character : public Human
{
public:
    Character(): Human(0,0,SizesType::Small)
    {
    }

    Character(std::string name, int health, int damage, SizesType::Sizes size) : Human(health, damage, size)
    {
        _name = std::move(name);
    }

private:
    std::string _name;
};
