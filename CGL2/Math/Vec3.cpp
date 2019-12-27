#include "Vec3.h"

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
constexpr Vec3::Vec3()
    : x_( 0.0 )
    , y_( 0.0 )
    , z_( 0.0 )
{
}

// =======================================================================
//
constexpr Vec3::Vec3( double x,
                      double y,
                      double z )
    : x_( x )
    , y_( y )
    , z_( z )
{
}

// =======================================================================
//
void Vec3::reset( double x,
                  double y,
                  double z )
{
    x_ = x;
    y_ = y;
    z_ = z;
}

// =======================================================================
//
double Vec3::dot( const Vec3& rhs ) const
{
    return ( x_ * rhs.x_ ) + ( y_ * rhs.y_ ) + ( z_ * rhs.z_ );
}


// =======================================================================
//
Vec3 Vec3::cross( const Vec3& rhs ) const
{
    return Vec3( y_ * rhs.z_ - z_ * rhs.y_,
                 z_ * rhs.x_ - x_ * rhs.z_,
                 x_ * rhs.y_ - y_ * rhs.x_ );
}

// =======================================================================
//
double Vec3::length() const
{
    return std::sqrt( x_ * x_ + y_ * y_ + z_ * z_ );
}

// =======================================================================
//
void Vec3::normalize()
{
    double len = length();
    if( len != 0 )
    {
        x_ = x_ / len;
        y_ = y_ / len;
        z_ = z_ / len;
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
void Vec3::print() const
{
    std::cout << "x: " << x_ << " y: " << y_ << " z: " << z_ << std::endl;
}

// =======================================================================
//
double Vec3::operator[]( size_t i ) const
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
    default:
        throw std::exception( "math::Vec3 - Access out of vector bounds" );
    }
}

// =======================================================================
//
Vec3 Vec3::operator*( double scalar ) const
{
    return Vec3( x_ * scalar,
                 y_ * scalar,
                 z_ * scalar );
}

// =======================================================================
// We should only use this if transforming a normal. In this case, we do
// not care about the translation component. So considering only the first
// three components is adequate.
Vec3 Vec3::operator*( const Mat4& rhs ) const
{
    Vec3 result;

    for( int i = 0; i < 3; i++ )
    {
        result.x_ += ( *this )[i] * rhs[i][0];
        result.y_ += ( *this )[i] * rhs[i][1];
        result.z_ += ( *this )[i] * rhs[i][2];
    }

    return result;
}

// =======================================================================
//
Vec3 Vec3::operator-( const Vec3& rhs ) const
{
    return Vec3( x_ - rhs.x_,
                 y_ - rhs.y_,
                 z_ - rhs.z_ );
}

// =======================================================================
//
Vec3 Vec3::operator+( const Vec3& rhs ) const
{
    return Vec3( x_ + rhs.x_,
                 y_ + rhs.y_,
                 z_ + rhs.z_ );
}

// =======================================================================
//
void Vec3::test()
{
    std::cout << std::endl << "Unit Tests: Vec3" << std::endl;
    Mat4 M = Mat4::translate( 1.0, 2.0, 3.0 );
    Vec3 v( 1.0, 2.0, 3.0 );
    M.print();
    v.print();
    ( v * M ).print();
    ( M * v ).print();

    M = Mat4::rotate_deg( 66.66666666, AXIS::z );
    Vec3 v2( 1.0, 0.0, 0.0 );
    M.print();
    v2.print();
    ( v2 * M ).print();
    ( M * v2 ).print();

    M = Mat4::translate( 1.0, 2.0, 3.0 ) * M;
    M.print();
    v2 = Vec3( 1.0, 2.0, 3.0 );
    ( v2 * M ).print();
    ( M * v2 ).print();
    std::cout << ( v2 * M ).length() << std::endl;
}

}
