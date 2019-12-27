#pragma once

#include <array>

#include "Vertex.h"

// =======================================================================
//
namespace geom
{

// =======================================================================
//
class Triangle
{
public:

    // -----------------------------------------------------------------
    //
    Triangle( const Vertex& v1, 
              const Vertex& v2, 
              const Vertex& v3 );

    // -----------------------------------------------------------------
    //
    template<size_t i>
    void set( const Vertex& v );

    // -----------------------------------------------------------------
    //
    template<size_t i>
    Vertex get();

    // -----------------------------------------------------------------
    //
    static void test();

    // -----------------------------------------------------------------
    // Hide the default constructor.
    Triangle() = delete;

    // -----------------------------------------------------------------
    //
    ~Triangle() = default;
    Triangle( const Triangle& ) = default;
    Triangle( Triangle&& ) = default;
    Triangle& operator=( const Triangle& ) = default;
    Triangle& operator=( Triangle&& ) = default;

    // -----------------------------------------------------------------
    //
    std::array<Vertex, 3> vertices_;
};

}
