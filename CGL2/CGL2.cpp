// CGL2.cpp : Defines the entry point for the console application.
//

#include "Math/Mat4.h"
#include "Math/Vec4.h"
#include "Geometry/Plane.h"

void test_all()
{
    math::Mat4::test();
    math::Vec4::test();
    math::Vec3::test();
    geom::Plane::test();
}

int main()
{
    test_all();

    return 0;
}

