#include "Vertex.h"

// =======================================================================
//
namespace geom
{

// =======================================================================
//
Vertex::Vertex()
{
}

// =======================================================================
//
Vertex::Vertex( math::Vec4 local_position, 
                math::Vec3 local_normal, 
                math::Vec4 colour )
    : pos_local_( local_position )
    , normal_local_( local_normal )
    , colour_( colour )
{
}

}