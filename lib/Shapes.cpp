#include <iostream>
#include <string>
#include "Shapes.h"



//-------------------
//     Kwadrat
//-------------------

Square::Square( unsigned int x )
{
    a = x;
}

void Square::CalcArea()
{
    area = a*a;
}

void Square::CalcPerimiter()
{
    perimiter = 4*a;
}

void Square::PrintData()
{
    std::cout<<"a: "<<a<<"; kat: "<<angle<<std::endl;
}

unsigned int Square::GetArea()
{
    return area;
}

unsigned int Square::GetPerimiter()
{
    return perimiter;
}



//-------------------
//     Prostokat
//-------------------

Rectangle::Rectangle( unsigned int x, unsigned int y )
{
    a = x;
    b = y;
}

void Rectangle::CalcArea()
{
    area = a*b;
}

void Rectangle::CalcPerimiter()
{
    perimiter = 2*a + 2*b;
}

void Rectangle::PrintData()
{
    std::cout<<"a: "<<a<<";b: "<<b<<"; kat: "<<angle<<std::endl;
}

unsigned int Rectangle::GetArea()
{
    return area;
}

unsigned int Rectangle::GetPerimiter()
{
    return perimiter;
}



//-------------------
//       Kolo
//-------------------

Disc::Disc( unsigned int x )
{
    r = x;
}

void Disc::CalcArea()
{
    area = r*r;
}

void Disc::CalcPerimiter()
{
    perimiter = 2*r;
}

std::string Disc::GetArea()
{
    return std::to_string(area) + "PI";
}

std::string Disc::GetPerimiter()
{
    return std::to_string(perimiter) + "PI";
}

//-------------------
//      Misc.
//-------------------

std::ostream& operator<<( std::ostream& os, Disc& d)
{
    os << "\nPromien: " << d.r;
    return os;
};