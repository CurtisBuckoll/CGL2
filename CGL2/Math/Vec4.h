#pragma once

#include "Vec3.h"

// =======================================================================
//
namespace math
{

// =======================================================================
//
class Mat4;

// =======================================================================
//
class Vec4
{
public:

    // -----------------------------------------------------------------
    //
    constexpr Vec4();

    // -----------------------------------------------------------------
    //
    constexpr Vec4( double x,
                    double y,
                    double z,
                    double w = 1.0 );

    // -----------------------------------------------------------------
    // Construct a homogeneous coordinate from a 3 vector.
    Vec4( const Vec3& xyz, 
          double w = 1.0 );

    // -----------------------------------------------------------------
    // All of x, y, z, w components are considered in this calculation.
    double dot( const Vec4& rhs ) const;

    // -----------------------------------------------------------------
    // I think we should not ever really have to rely on this if
    // restricted to affine transforms.
    // But let's include the method anyways.
    // This will not be fast. Avoid if possible.
    void hgdivide();

    // -----------------------------------------------------------------
    //
    void print() const;

    // -----------------------------------------------------------------
    //
    static void test();

    // -----------------------------------------------------------------
    //
    double operator[]( size_t i ) const;

    // -----------------------------------------------------------------
    // Use friend class or something if we need this:
    //Vec4 operator*( double scalar ) const;

    // -----------------------------------------------------------------
    //
    Vec4 operator*( const Mat4& rhs ) const;

    // -----------------------------------------------------------------
    // Returns Vec3. This is a specialization to the types of operations
    // we know we will perform - Sutraction of homogeneous coordinates
    // should return a vector.
    //
    // We also do NOT take into account homogeneous coordinates where
    // the w componenent is not equal to 1. This is for speed. We should
    // not worry about this if only applying affine transforms.
    Vec3 operator-( const Vec4& rhs ) const;

    // -----------------------------------------------------------------
    // Returns Vec3. This is a specialization to the types of operations
    // we know we will perform - Addition of homogeneous coordinates
    // should return a vector.
    //
    // We also do NOT take into account homogeneous coordinates where
    // the w componenent is not equal to 1. This is for speed. We should
    // not worry about this if only applying affine transforms.
    Vec3 operator+( const Vec4& rhs ) const;

    // -----------------------------------------------------------------
    //
    ~Vec4()                        = default;
    Vec4( const Vec4& )            = default;
    Vec4( Vec4&& )                 = default;
    Vec4& operator=( const Vec4& ) = default;
    Vec4& operator=( Vec4&& )      = default;

    // -----------------------------------------------------------------
    //
    double x_;
    double y_;
    double z_;
    double w_;
};

}
