#pragma once

namespace math
{
// -----------------------------------------------------------------
//
enum class AXIS
{
    x = 0,
    y,
    z
};

// -----------------------------------------------------------------
//
static constexpr double PI             = 3.141592653589793239;
static constexpr double PI_OVER_180    = PI / 180.0;
static constexpr double EPSILON_COARSE = 0.0001;
static constexpr double EPSILON_FINE   = 0.0000000000000001;

}
