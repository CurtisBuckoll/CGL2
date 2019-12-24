#include "Plane.h"

#include <iostream>

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

// -----------------------------------------------------------------
// Returns true if intersection found
bool Plane::find_ray_intersect( const math::Vec4& p,
                                const math::Vec4& v,
                                math::Vec4& result )
{
    // TODO: implement
    return true;
}

// -----------------------------------------------------------------
// Returns true if intersection found
bool Plane::find_segment_intersect( const math::Vec4& p0,
                                    const math::Vec4& p1,
                                    math::Vec4& result )
{
    // TODO: implement
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
}

}