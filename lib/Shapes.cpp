#include <iostream>
#include <string>
#include <cmath>
#include "Shapes.h"


//-------------------
//     Prostokat
//-------------------

Rectangle::Rectangle( unsigned int x, unsigned int y )
{
    sides[0] = &x;
    sides[1] = &y;
}

void Rectangle::CalcArea()
{
    area = (*sides[0]) * (*sides[1]);
}

void Rectangle::CalcPerimiter()
{
    perimiter = 2 * (*sides[0]) + 2 * (*sides[1]);
}

void Rectangle::PrintData()
{
    std::cout<<"a: "<<sides[0]<<";b: "<<sides[1]<<"; kat: "<<angle<<std::endl;
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
//     Trojkat
//-------------------

Triangle::Triangle( unsigned int x, unsigned int y, unsigned int z)
{
    *sides[0] = x;
    *sides[1] = y;
    *sides[2] = z;
}

void Triangle::CalcArea()
{
    int s = perimiter / 2;
    area = sqrt(s * (s - (*sides[0])) * (s - (*sides[1])) * (s - (*sides[2]))); 
}

void Triangle::CalcPerimiter()
{
    perimiter = (*sides[0]) + (*sides[1]) + (*sides[2]);
}

void Triangle::CalcAngles()
{
    int a = (*sides[0]);
    int b = (*sides[1]);
    int c = (*sides[2]);
    
    double cosA = ((b*b) + (c*c) - (a*a)) / (2 * b * c);
    double cosB = ((c*c) + (a*a) - (b*b)) / (2 * c * a);

    *angles[0] = acos(cosA);
    *angles[1] = acos(cosB);
    *angles[2] = 180 - *angles[1] - *angles[0];
}

double Triangle::GetArea()
{
    return area;
}

unsigned int Triangle::GetPerimiter()
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

std::ostream& operator<<( std::ostream& os, Rectangle& r)
{
    std::string output = "\nBoki:\n";

    

    return os;
};

std::ostream& operator<<( std::ostream& os, Triangle& t)
{
    
    return os;
};

std::ostream& operator<<( std::ostream& os, Disc& d)
{
    os << "\nPromien: " << d.r;
    return os;
};