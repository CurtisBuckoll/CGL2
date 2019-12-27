#pragma once

#include "../Math/Vec3.h"
#include "../Math/Vec4.h"

// =======================================================================
//
namespace geom
{

// =======================================================================
//
class Vertex
{
public:

    // -----------------------------------------------------------------
    //
    Vertex();

    // -----------------------------------------------------------------
    //
    Vertex( math::Vec4 local_position,
            math::Vec3 local_normal, 
            math::Vec4 colour );

    // -----------------------------------------------------------------
    //
    ~Vertex()                          = default;
    Vertex( const Vertex& )            = default;
    Vertex( Vertex&& )                 = default;
    Vertex& operator=( const Vertex& ) = default;
    Vertex& operator=( Vertex&& )      = default;

    // -----------------------------------------------------------------
    //
    math::Vec4 pos_local_;
    math::Vec4 pos_world_;
    math::Vec4 pos_camera_;

    math::Vec3 normal_local_;
    math::Vec3 normal_world_;

    math::Vec4 colour_;
};

}
