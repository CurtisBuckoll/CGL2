#include "Triangle.h"

// =======================================================================
//
namespace geom
{

// =======================================================================
//
Triangle::Triangle( const Vertex& v1,
                    const Vertex& v2,
                    const Vertex& v3 )
    : vertices_{ { v1, v2, v3 } }
{
}

// =======================================================================
//
template<size_t i>
void Triangle::set( const Vertex& v )
{
    vertices_[i] = v; 
}

// =======================================================================
//
template<size_t i>
Vertex Triangle::get() 
{ 
    return vertices_[i]; 
}

// =======================================================================
//
void Triangle::test()
{
    Vertex v1( math::Vec4( 0.0, 0.0, 0.0 ), math::Vec3( 0.0, 0.0, 0.0 ), math::Vec4( 0.0, 0.0, 0.0 ) );
    Vertex v2( math::Vec4( 1.0, 1.0, 1.0 ), math::Vec3( 0.0, 0.0, 0.0 ), math::Vec4( 0.0, 0.0, 0.0 ) );
    Vertex v3( math::Vec4( 2.0, 2.0, 2.0 ), math::Vec3( 0.0, 0.0, 0.0 ), math::Vec4( 0.0, 0.0, 0.0 ) );

    Triangle T( v1, v2, v3 );
    T.get<0>().pos_local_.print();
    T.get<1>().pos_local_.print();
    T.get<2>().pos_local_.print();

    T.set<0>( Vertex(math::Vec4( 4.0, 4.0, 4.0 ), math::Vec3( 0.0, 0.0, 0.0 ), math::Vec4( 0.0, 0.0, 0.0 )) );
    T.get<0>().pos_local_.print();
    T.get<1>().pos_local_.print();
    T.get<2>().pos_local_.print();
}

}
