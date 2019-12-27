#include "Vec2.h"

#include <iostream>
#include <cmath>
#include <exception>

#include "Mat4.h"

// =======================================================================
//
namespace math
{

// =======================================================================
//
Vec2::Vec2()
    : x_( 0.0 )
    , y_( 0.0 )
{
}

// =======================================================================
//
constexpr Vec2::Vec2( double x,
                      double y )
    : x_( x )
    , y_( y )
{
}

// =======================================================================
//
void Vec2::reset( double x,
                  double y )
{
    x_ = x;
    y_ = y;
}

// =======================================================================
//
void Vec2::print() const
{
    std::cout << "x: " << x_ << " y: " << y_ << std::endl;
}

// =======================================================================
//
double Vec2::operator[]( size_t i ) const
{
    switch( i )
    {
    case 0:
        return x_;
        break;
    case 1:
        return y_;
        break;
    default:
        throw std::exception( "math::Vec2 - Access out of vector bounds" );
    }
}

}
