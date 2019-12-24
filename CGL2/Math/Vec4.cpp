#include "Vec4.h"

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
Vec4::Vec4( const Vec3& xyz,
            double w )
    : x_( xyz.x_ )
    , y_( xyz.y_ )
    , z_( xyz.z_ )
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
void Vec4::hgdivide()
{
    if( w_ != 1.0 && w_ != 0.0 )
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
double Vec4::operator[]( size_t i ) const
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
Vec4 Vec4::operator*( const Mat4& rhs ) const
{
    Vec4 result = Vec4{ 0.0, 0.0, 0.0, 0.0 };

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
Vec3 Vec4::operator-( const Vec4& rhs ) const
{
    return Vec3( x_ - rhs.x_,
                 y_ - rhs.y_, 
                 z_ - rhs.z_ );
}

// =======================================================================
//
Vec3 Vec4::operator+( const Vec4& rhs ) const
{
    return Vec3( x_ + rhs.x_,
                 y_ + rhs.y_,
                 z_ + rhs.z_ );
}

// =======================================================================
//
void Vec4::test()
{
    std::cout << std::endl << "Unit Tests: Vec4" << std::endl;
    Mat4 M = Mat4::translate( 1.0, 2.0, 3.0 );
    Vec4 v( 1.0, 2.0, 3.0 );
    M.print();
    v.print();
    ( v * M ).print();
    ( M * v ).print();

    M = Mat4::rotate_deg( 66.66666666, AXIS::x );
    Vec4 v2( 1.0, 0.0, 0.0 );
    M.print();
    v2.print();
    ( v * M ).print();
    ( M * v ).print();
}

}
