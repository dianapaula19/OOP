#include "whatever.h"

whatever::whatever()
{
    //ctor
}

whatever::~whatever()
{
    //dtor
}

whatever::whatever(const whatever& other)
{
    //copy ctor
}

whatever& whatever::operator=(const whatever& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
