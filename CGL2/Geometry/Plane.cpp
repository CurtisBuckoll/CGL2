#include "Plane.h"

#include <iostream>

#include "../Math/Utility.h"

// =======================================================================
//
namespace geom
{

// =======================================================================
//
constexpr Plane::Plane( double A, double B, double C, double D )
    : p_{ A, B, C, D }
{
}

// =======================================================================
//
Plane::Plane( const math::Vec3& a, const math::Vec3& b, const math::Vec3& c )
    : p_( ( b - a ).cross( c - a ), 0.0 )
{
    p_.w_ = -( a.x_ * p_.x_ + 
               a.y_ * p_.y_ + 
               a.z_ * p_.z_ );
}

// =======================================================================
//
double Plane::test_coord( const math::Vec4& coord ) const
{
    return p_.dot( coord );
}

// =======================================================================
// 
bool Plane::ray_intersect( const math::Vec4& pos,
                           const math::Vec3& v,
                           math::Vec4& result )
{
    const double denom = v.x_ * p_.x_ + 
                         v.y_ * p_.y_ + 
                         v.z_ * p_.z_;
    if( math::close_to_zero_fine( denom ) )
    {
        return false;
    }
    const double t = -pos.dot( p_ ) / denom;
    result = math::Vec4( pos + ( v * t ) );
    return true;
}

// =======================================================================
// 
bool Plane::segment_intersect( const math::Vec4& p0,
                               const math::Vec4& p1,
                               math::Vec4& result )
{
    const math::Vec3 v = p1 - p0;
    const double denom = v.x_ * p_.x_ +
                         v.y_ * p_.y_ +
                         v.z_ * p_.z_;
    if( math::close_to_zero_fine( denom ) )
    {
        return false;
    }
    const double t = -p0.dot( p_ ) / denom;
    if( t < 0 || t > 1 )
    {
        return false;
    }
    result = math::Vec4( p0 + ( v * t ) );
    return true;
}

// =======================================================================
//
void Plane::print() const
{
    std::cout << "A: " << p_.x_ << " B: " << p_.y_ << " C: " << p_.z_ << " D: " << p_.w_ << std::endl;
}

// =======================================================================
//
void Plane::test()
{
    std::cout << std::endl << "Unit Tests: Plane" << std::endl;

    math::Vec3 a( 3.0, 1.0, 1.0 );
    math::Vec3 b( 1.0, 4.0, 2.0 );
    math::Vec3 c( 1.0, 3.0, 4.0 );

    Plane P( a, b, c );
    P.print();

    std::cout << P.test_coord( a ) << std::endl;
    std::cout << P.test_coord( b ) << std::endl;
    std::cout << P.test_coord( c ) << std::endl;
    std::cout << P.test_coord( math::Vec4( 6.0, 2.0, 6.0 ) ) << std::endl;

    math::Vec3 e( 1.0,  2.0, -2.0 );
    math::Vec3 f( 3.0, -2.0,  1.0 );
    math::Vec3 g( 5.0,  1.0, -4.0 );

    Plane Q( e, f, g );
    Q.print();

    std::cout << Q.test_coord( e ) << std::endl;
    std::cout << Q.test_coord( f ) << std::endl;
    std::cout << Q.test_coord( g ) << std::endl;
    std::cout << Q.test_coord( math::Vec4( 6.0, 2.0, 6.0 ) ) << std::endl;

    std::cout << std::endl << "Ray Intersect:" << std::endl;

    Plane R( 2.0, 1.0, -4.0, -4.0 );
    math::Vec4 pos1( 0.0, 2.0, 0.0 );
    math::Vec3 dir1( 1.0, 3.0, 1.0 );
    math::Vec4 res1;
    if( !R.ray_intersect( pos1, dir1, res1 ) )
    {
        std::cout << "No unique intersection." << std::endl;
    }
    else
    {
        res1.print();
    }

    math::Vec4 pos2( 1.0, 4.0, 0.0 );
    math::Vec3 dir2( 1.0, 2.0, 1.0 );
    math::Vec4 res2;
    if( !R.ray_intersect( pos2, dir2, res2 ) )
    {
        std::cout << "No unique intersection." << std::endl;
    }
    else
    {
        res2.print();
    }

    std::cout << std::endl << "Segment Intersect:" << std::endl;
    math::Vec4 res3;
    if( !R.segment_intersect( pos1, pos1 + dir1 * 3.0, res3 ) )
    {
        std::cout << "No unique intersection." << std::endl;
    }
    else
    {
        res3.print();
    }

    math::Vec4 res4;
    if( !R.segment_intersect( pos1, pos1 + dir1, res4 ) )
    {
        std::cout << "No unique intersection." << std::endl;
    }
    else
    {
        res4.print();
    }
}

}