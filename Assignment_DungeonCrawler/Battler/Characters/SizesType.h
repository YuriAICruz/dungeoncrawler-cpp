#pragma once
#include <string>

class SizesType
{
public:
    static enum Sizes
    {
        Small,
        Medium,
        Big,
        SIZES_LENGTH
    };

    static std::string ToString(Sizes size)
    {
        switch (size)
        {
        case Small:
            return "Small";
        case Medium:
            return "Medium";
        case Big:
            return "Big";
        default:
            return "__INVALID__";
        }
    }    
};
