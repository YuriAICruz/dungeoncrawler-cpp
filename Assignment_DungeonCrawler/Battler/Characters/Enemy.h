#pragma once
#include <random>

#include "Human.h"

class Enemy : public Human
{
public:
    Enemy(): Human(0,0,SizesType::Small)
    {
    }

    Enemy(int result, int damage_dist, SizesType::Sizes sizes) : Human(result, damage_dist, sizes)
    {
        
    }
};
