#pragma once

#include <cmath>

#include "MathConst.h"

namespace math
{

inline bool close_to_zero_fine( double x )
{
    return std::abs( x ) < EPSILON_FINE;
}

}