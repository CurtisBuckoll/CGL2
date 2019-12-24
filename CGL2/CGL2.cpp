// CGL2.cpp : Defines the entry point for the console application.
//

#include "Math/Mat4.h"

int main()
{
    math::Mat4 R( math::Mat4::rotate_deg( 45, math::AXIS::z ) );
    R.print();
    R.inverse().print();

    ( R * R.inverse() ).print();
    ( R.inverse() * R ).print();

    R = math::Mat4::rotate_deg( 45, math::AXIS::y );
    R.print();

    ( R * R.inverse() ).print();
    ( R.inverse() * R ).print();

    R = math::Mat4::rotate_deg( 45, math::AXIS::x );
    R.print();

    ( R * R.inverse() ).print();
    ( R.inverse() * R ).print();

    math::Mat4 S( math::Mat4::scale( 1.0, 2.0, 3.0 ) );
    S.print();

    math::Mat4 U = math::Mat4::scale_uniform( 4.0 );
    U.print();

    math::Mat4 T = math::Mat4::translate( 5.0, 6.0, 7.0 );
    T.print();

    T = math::Mat4::translate( 5.0, 6.0, 7.0 );

    math::Mat4 m;
    m.print();

    m.random(1.0, 10.0);
    m.print();
    //m[0][0] = 1.0;
    //m[1][0] = 1.0;
    //m[0][1] = 3.0;
    //m[1][1] = 3.0;
    m.print();

    //math::Mat4 mi = m.inverse2();
    //math::Mat4 i = mi * m;
    //i.print();
    //mi.print();

    math::Mat4 mi = m.inverse();
    
    mi.print();
    ( mi * m ).print();
    ( m * mi ).print();


    //getchar();
    return 0;
}

