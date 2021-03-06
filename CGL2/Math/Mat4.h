#pragma once

#include "MathConst.h"

// =======================================================================
//
namespace math
{

class Vec3;
class Vec4;

// =======================================================================
//
class Mat4
{
public:

    // -----------------------------------------------------------------
    //
    constexpr Mat4();

    //// -----------------------------------------------------------------
    ////
    //void scale_uniform( double s );

    //// -----------------------------------------------------------------
    ////
    //void scale( double x, 
    //            double y, 
    //            double z );

    //// -----------------------------------------------------------------
    ////
    //void translate( double x, 
    //                double y, 
    //                double z);

    //// -----------------------------------------------------------------
    ////
    //void rotate_deg( double angle,
    //                 AXIS axis);

    // -----------------------------------------------------------------
    //
    static Mat4 scale( double x,
                       double y,
                       double z );

    // -----------------------------------------------------------------
    //
    static Mat4 scale_uniform( double s );


    // -----------------------------------------------------------------
    //
    static Mat4 translate( double x,
                           double y,
                           double z );

    // -----------------------------------------------------------------
    //
    static Mat4 rotate_deg( double angle,
                            AXIS axis );

    // -----------------------------------------------------------------
    //
    Mat4 inverse() const;

    // -----------------------------------------------------------------
    //
    void random( double min,
                 double max );

    // -----------------------------------------------------------------
    //
    void print() const;

    // -----------------------------------------------------------------
    //
    static void test();

    // -----------------------------------------------------------------
    //
    Mat4 operator*( const Mat4& mat ) const;

    // -----------------------------------------------------------------
    // Transform a vector with the w componenet fixed at 0.
    Vec3 operator*( const Vec3& vec ) const;

    // -----------------------------------------------------------------
    // Transforming a homogeneous coordinate.
    Vec4 operator*( const Vec4& vec ) const;

    // -----------------------------------------------------------------
    //
    double* operator[]( size_t r );

    // -----------------------------------------------------------------
    //
    const double* operator[]( size_t r ) const;

    // -----------------------------------------------------------------
    //
    ~Mat4()                        = default;
    Mat4( const Mat4& )            = default;
    Mat4( Mat4&& )                 = default;
    Mat4& operator=( const Mat4& ) = default;
    Mat4& operator=( Mat4&& )      = default;

private:

    // -----------------------------------------------------------------
    //
    void swap_rows( size_t r1, size_t r2 );

    // -----------------------------------------------------------------
    //
    static const size_t kMAT_SIZE_ = 4;
    double matrix_[kMAT_SIZE_][kMAT_SIZE_];
};

}

