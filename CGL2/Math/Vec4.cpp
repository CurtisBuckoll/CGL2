#include "Vec4.h"

#include <iostream>
#include <cmath>
#include <exception>

#include "Mat4.h"

/**
normal vs
*/

// =======================================================================
//
namespace math
{

// =======================================================================
//
constexpr Vec4::Vec4()
    : x_(0.0)
    , y_(0.0)
    , z_(0.0)
    , w_(1.0)
{
}

// =======================================================================
//
constexpr Vec4::Vec4( double x,
                      double y,
                      double z,
                      double w /*= 1*/ )
    : x_( x )
    , y_( y )
    , z_( z )
    , w_( w )
{
}

// =======================================================================
//
double Vec4::dot( const Vec4& rhs ) const
{
    return ( x_ * rhs.x_ ) + ( y_ * rhs.y_ ) + ( z_ * rhs.z_ ) + ( w_ * rhs.w_ );
}


// =======================================================================
//
Vec4 Vec4::cross( const Vec4& rhs ) const
{
    return Vec4( y_ * rhs.z_ - z_ * rhs.y_,
                 z_ * rhs.x_ - x_ * rhs.z_,
                 x_ * rhs.y_ - y_ * rhs.x_, 0.0f );
}

// =======================================================================
// Ignores the w component
double Vec4::length() const
{
    return std::sqrt( x_ * x_ + y_ * y_ + z_ * z_ );
}

// =======================================================================
//
void Vec4::normalize()
{
    double len = length();
    if( len != 0 )
    {
        x_ = x_ / len;
        y_ = y_ / len;
        z_ = z_ / len;
        w_ = 0; // I think this makes the most sense.
    }

    //float n = 0.15625;
    //std::cout << Q_rsqrt( n ) << std::endl;
    //std::cout << 1.0f / length << std::endl;
    //float isqrt = Q_rsqrt( x * x + y * y + z * z );
    //std::cout << isqrt << std::endl;

    //x = x * isqrt;
    //y = y * isqrt;
    //z = z * isqrt;
    //w = w * isqrt; // w = 0 ... w should always be 0.0f here if we're in some sitch to be using normalize so not sure why I did this before..
}

// =======================================================================
//
void Vec4::hgdivide()
{
    // I think we should not ever really have to rely on this.
    // But let's include the method anyways.
    if( w_ != 0.0 && w_ != 1.0 )
    {
        x_ = x_ / w_;
        y_ = y_ / w_;
        z_ = z_ / w_;
        w_ = 1.0f;
    }
}

// =======================================================================
//
void Vec4::print() const
{
    std::cout << "x: " << x_ << " y: " << y_ << " z: " << z_ << " w: " << w_ << std::endl;
}

// =======================================================================
//
double Vec4::operator[]( int i ) const
{
    switch( i )
    {
    case 0:
        return x_;
        break;
    case 1:
        return y_;
        break;
    case 2:
        return z_;
        break;
    case 3:
        return w_;
        break;
    default:
        throw std::exception( "math::Vec4 - Access out of vector bounds" );
    }
}

// =======================================================================
//
Vec4 Vec4::operator*( double scalar ) const
{
    return Vec4( x_ * scalar, 
                 y_ * scalar,
                 z_ * scalar, 
                 w_ );
}

// =======================================================================
//
Vec4 Vec4::operator*( const Mat4& rhs ) const
{
    Vec4 result;

    for( int i = 0; i < 4; i++ )
    {
        result.x_ += ( *this )[i] * rhs[i][0];
        result.y_ += ( *this )[i] * rhs[i][1];
        result.z_ += ( *this )[i] * rhs[i][2];
        result.w_ += ( *this )[i] * rhs[i][3];
    }

    return result;
}

// =======================================================================
//
Vec4 Vec4::operator-( const Vec4& rhs ) const
{
    return Vec4( x_ - rhs.x_, 
                 y_ - rhs.y_, 
                 z_ - rhs.z_, 
                 0.0 );
}

// =======================================================================
//
Vec4 Vec4::operator+( const Vec4& rhs ) const
{
    return Vec4( x_ + rhs.x_,
                 y_ + rhs.y_,
                 z_ + rhs.z_,
                 0.0 );
}

}
