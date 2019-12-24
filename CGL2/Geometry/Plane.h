#pragma once

#include "../Math/Vec3.h"
#include "../Math/Vec4.h"

// =======================================================================
//
namespace geom
{

// =======================================================================
//
class Plane
{
public:

    // -----------------------------------------------------------------
    // The plane equation is stored in the form: Ax + By + Cz - D = 0
    constexpr Plane( double A, double B, double C, double D );

    // -----------------------------------------------------------------
    // Creates the plane with normal (b - a) x ( c - a) where we assume
    // linear independence.
    // The plane equation is stored in the form: Ax + By + Cz - D = 0
    Plane( const math::Vec3& a, const math::Vec3& b, const math::Vec3& c );

    // -----------------------------------------------------------------
    // Apply the plane equation to a homogeneous coordinate. If 0 (or
    // close to within some epsilon) the point is on the plane.
    double test_coord( const math::Vec4& coord ) const;

    // -----------------------------------------------------------------
    // Returns true if intersection found
    bool find_ray_intersect( const math::Vec4& p,
                             const math::Vec4& v,
                             math::Vec4& result );

    // -----------------------------------------------------------------
    // Returns true if intersection found
    bool find_segment_intersect( const math::Vec4& p0, 
                                 const math::Vec4& p1,
                                 math::Vec4& result );

    // -----------------------------------------------------------------
    //
    void print() const;

    // -----------------------------------------------------------------
    //
    static void test();

    // -----------------------------------------------------------------
    // Hide the default constructor.
    Plane() = delete;

    // -----------------------------------------------------------------
    //
    ~Plane()                         = default;
    Plane( const Plane& )            = default;
    Plane( Plane&& )                 = default;
    Plane& operator=( const Plane& ) = default;
    Plane& operator=( Plane&& )      = default;

private:

    // -----------------------------------------------------------------
    // The plane componenets A, B, C, D are represented by
    // p_.x_, p_.y_, p_.z_, p_.w_ respectively.
    math::Vec4 p_;
};

}
