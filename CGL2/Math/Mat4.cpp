#include "Mat4.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <random>

#include "MathConst.h"

// =======================================================================
//
namespace math
{

// =======================================================================
//
double random_entry( double min, double max )
{
    std::random_device device;
    std::mt19937 rng( device() );
    std::uniform_real_distribution<double> distribution( min, max );
    return distribution( rng );
}

// =======================================================================
//
constexpr Mat4::Mat4()
    : matrix_{ 0.0 }
{
    matrix_[0][0] = matrix_[1][1] = matrix_[2][2] = matrix_[3][3] = 1.0;
}

// =======================================================================
//
//void Mat4::scale_uniform( double s )
//{
//    scale( s, s, s );
//}

// =======================================================================
//
//void Mat4::scale( double x,
//                  double y,
//                  double z )
//{
//    Mat4 scale;
//    scale.matrix_[0][0] = x;
//    scale.matrix_[1][1] = y;
//    scale.matrix_[2][2] = z;
//    *this = ( *this ) * scale;
//}

// =======================================================================
//
//void Mat4::translate( double x,
//                      double y,
//                      double z )
//{
//    Mat4 transform;
//    transform.matrix_[3][0] = x;
//    transform.matrix_[3][1] = y;
//    transform.matrix_[3][2] = z;
//    *this = ( *this ) * transform;
//}

// =======================================================================
//
//void Mat4::rotate_deg( double angle,
//                       AXIS axis )
//{
//    Mat4 rotate;
//
//    switch( axis )
//    {
//    case AXIS::x:
//        rotate.matrix_[1][1] = std::cos( angle * PI_OVER_180 );
//        rotate.matrix_[2][1] = std::sin( angle * PI_OVER_180 );
//        rotate.matrix_[1][2] = -std::sin( angle * PI_OVER_180 );
//        rotate.matrix_[2][2] = std::cos( angle * PI_OVER_180 );
//        break;
//
//    case AXIS::y:
//        rotate.matrix_[0][0] = std::cos( angle * PI_OVER_180 );
//        rotate.matrix_[2][0] = -std::sin( angle * PI_OVER_180 );
//        rotate.matrix_[0][2] = std::sin( angle * PI_OVER_180 );
//        rotate.matrix_[2][2] = std::cos( angle * PI_OVER_180 );
//        break;
//
//    case AXIS::z:
//        rotate.matrix_[0][0] = std::cos( angle * PI_OVER_180 );
//        rotate.matrix_[1][0] = std::sin( angle * PI_OVER_180 );
//        rotate.matrix_[0][1] = -std::sin( angle * PI_OVER_180 );
//        rotate.matrix_[1][1] = std::cos( angle * PI_OVER_180 );
//        break;
//
//    default:
//        // TODO: error - shouldn't ever see this though.
//        break;
//    }
//
//    *this = ( *this ) * rotate;
//}

// =======================================================================
//
Mat4 Mat4::scale( double x,
                  double y,
                  double z )
{
    Mat4 scale;
    scale.matrix_[0][0] = x;
    scale.matrix_[1][1] = y;
    scale.matrix_[2][2] = z;
    return scale;
}

// =======================================================================
//
Mat4 Mat4::scale_uniform( double s )
{
    return scale( s, s, s );
}

// =======================================================================
//
Mat4 Mat4::translate( double x,
                      double y,
                      double z )
{
    Mat4 transform;
    transform[0][3] = x;
    transform[1][3] = y;
    transform[2][3] = z;
    return transform;
}

// =======================================================================
//
Mat4 Mat4::rotate_deg( double angle,
                       AXIS axis )
{
    Mat4 rotate;

    switch( axis )
    {
    case AXIS::x:
        rotate.matrix_[1][1] =  std::cos( angle * PI_OVER_180 );
        rotate.matrix_[1][2] = -std::sin( angle * PI_OVER_180 );
        rotate.matrix_[2][1] =  std::sin( angle * PI_OVER_180 );
        rotate.matrix_[2][2] =  std::cos( angle * PI_OVER_180 );
        break;

    case AXIS::y:
        rotate.matrix_[0][0] =  std::cos( angle * PI_OVER_180 );
        rotate.matrix_[0][2] =  std::sin( angle * PI_OVER_180 );
        rotate.matrix_[2][0] = -std::sin( angle * PI_OVER_180 );
        rotate.matrix_[2][2] =  std::cos( angle * PI_OVER_180 );
        break;

    case AXIS::z:
        rotate.matrix_[0][0] =  std::cos( angle * PI_OVER_180 );
        rotate.matrix_[0][1] = -std::sin( angle * PI_OVER_180 );
        rotate.matrix_[1][0] =  std::sin( angle * PI_OVER_180 );
        rotate.matrix_[1][1] =  std::cos( angle * PI_OVER_180 );
        break;

    default:
        // TODO: error - shouldn't ever see this though.
        break;
    }

    return rotate;
}

// =======================================================================
//
void Mat4::random( double min,
                   double max )
{
    for( size_t r = 0; r < kMAT_SIZE_; ++r )
    {
        for( size_t c = 0; c < kMAT_SIZE_; ++c )
        {
            matrix_[r][c] = random_entry( min, max );
        }
    }
}

// =======================================================================
//
void Mat4::swap_rows( size_t r1, size_t r2 )
{
    double temp = 0.0;
    for( size_t c = 0; c < kMAT_SIZE_; ++c )
    {
        temp = matrix_[r1][c];
        matrix_[r1][c] = matrix_[r2][c];
        matrix_[r2][c] = temp;
    }
}


// =======================================================================
// Matrix must have a non-zero determinant
Mat4 Mat4::inverse() const
{
    Mat4 curr(*this);
    Mat4 res;
    
    double s = 0.0;
    for( size_t i = 0; i < kMAT_SIZE_; ++i )
    {
        for( size_t r = i + 1; r < kMAT_SIZE_; ++r )
        {
            if( curr.matrix_[i][i] == 0 )
            {
                // swap row
                for( int k = i + 1; k < 4; ++k )
                {
                    if( curr.matrix_[k][i] != 0 )
                    {
                        curr.swap_rows( k, i );
                        res.swap_rows( k, i );
                        break;
                    }
                }
            }

            s = curr.matrix_[r][i] / curr.matrix_[i][i];

            for( size_t c = i; c < kMAT_SIZE_; ++c )
            {
                curr.matrix_[r][c] = curr.matrix_[r][c] - s * curr.matrix_[i][c];
            }

            for( size_t c = 0; c < kMAT_SIZE_; ++c )
            {
                res.matrix_[r][c] = res.matrix_[r][c] - s * res.matrix_[i][c];
            }
        }
    }

    // back substitute
    for( int i = kMAT_SIZE_ - 1; i > 0; --i )
    {
        for( int r = i - 1; r >= 0; --r )
        {
            s = curr.matrix_[r][i] / curr.matrix_[i][i];

            for( size_t c = i; c < kMAT_SIZE_; ++c )
            {
                curr.matrix_[r][c] = curr.matrix_[r][c] - s * curr.matrix_[i][c];
            }
            for( size_t c = 0; c < kMAT_SIZE_; ++c )
            {
                res.matrix_[r][c] = res.matrix_[r][c] - s * res.matrix_[i][c];
            }
        }
    }

    // reduce diagonal to 1's
    for( size_t r = 0; r < kMAT_SIZE_; ++r )
    {
        s = 1.0 / curr.matrix_[r][r];
        curr.matrix_[r][r] = s * curr.matrix_[r][r];

        for( size_t c = 0; c < kMAT_SIZE_; ++c )
        {
            res.matrix_[r][c] = s * res.matrix_[r][c];
        }
    }

    return res;
}

// =======================================================================
//
void Mat4::print() const
{
    const double epsilon = 0.0001;
    for( int r = 0; r < kMAT_SIZE_; ++r )
    {
        for( int c = 0; c < kMAT_SIZE_; ++c )
        {
            std::cout << std::setprecision( 4 ) << (std::abs(matrix_[r][c]) < epsilon ? 0.0 : matrix_[r][c]) << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// =======================================================================
//
Mat4 Mat4::operator*( const Mat4& mat ) const
{
    Mat4 result;

    for( size_t r = 0; r < kMAT_SIZE_; ++r )
    {
        for( size_t c = 0; c < kMAT_SIZE_; ++c )
        {
            double sum = 0.0f;
            for( int i = 0; i < kMAT_SIZE_; ++i )
            {
                sum += matrix_[r][i] * mat.matrix_[i][c];
            }
            result.matrix_[r][c] = sum;
        }
    }

    return result;
}

// =======================================================================
//
//vec4 mat4::operator*( const vec4& vec ) const
//{
//    vec4 result = vec4( 0.0f, 0.0f, 0.0f, 0.0f );
//
//    for( int i = 0; i < 4; i++ )
//    {
//        result.x += matrix[i][0] * vec[i];
//        result.y += matrix[i][1] * vec[i];
//        result.z += matrix[i][2] * vec[i];
//        result.w += matrix[i][3] * vec[i];
//    }
//
//    result.color = vec.color;
//    return result;
//}

// =======================================================================
//
double* Mat4::operator[]( size_t r )
{
    return &matrix_[r][0];
}

// =======================================================================
//
const double* Mat4::operator[]( size_t r ) const
{
    return &matrix_[r][0];
}

}

