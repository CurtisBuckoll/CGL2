#pragma once

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
                    double w = 1.0f );

    // -----------------------------------------------------------------
    // The w component is included.
    double dot( const Vec4& rhs ) const;

    // -----------------------------------------------------------------
    //
    Vec4 cross( const Vec4& rhs ) const;

    // -----------------------------------------------------------------
    //
    double length() const;

    // -----------------------------------------------------------------
    //
    void normalize();

    // -----------------------------------------------------------------
    //
    void hgdivide();

    // -----------------------------------------------------------------
    //
    void print() const;

    // -----------------------------------------------------------------
    //
    double operator[]( int i ) const;

    // -----------------------------------------------------------------
    //
    Vec4 operator*( double scalar ) const;

    // -----------------------------------------------------------------
    //
    Vec4 operator*( const Mat4& rhs ) const;

    // -----------------------------------------------------------------
    //
    Vec4 operator-( const Vec4& rhs ) const;

    // -----------------------------------------------------------------
    //
    Vec4 operator+( const Vec4& rhs ) const;

    // -----------------------------------------------------------------
    //
    ~Vec4() = default;
    Vec4( const Vec4& ) = default;
    Vec4( Vec4&& ) = default;
    Vec4& operator=( const Vec4& ) = default;
    Vec4& operator=( Vec4&& ) = default;

    // -----------------------------------------------------------------
    //
    double x_;
    double y_;
    double z_;
    double w_;
};

}
