#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "Shapes.h"



//--------------------------
//     Bazowa Ksztalt
//--------------------------

void Shape::CalcPerimiter()
{
    std::vector<int>::iterator ptr;

    for (ptr = sides.begin(); ptr < sides.end(); ptr++)
    {
        perimiter += *ptr;
    }
};

void Shape::Call()
{
    std::cout <<  "-------------\n" << "Jestem... figura?" << std::endl;
};

//-------------------
//     Prostokat
//-------------------

Rectangle::Rectangle( unsigned int x, unsigned int y )                   // konstruktor kopiuje x i y do wektora sides
{
    sides.push_back(x);
    sides.push_back(y);

    CalcPerimiter();
    CalcArea();
}

Rectangle::~Rectangle()
{
    std::vector<int>().swap(sides);                                     // czyscimy sides swapujac go za utworzony na szybko pusty wektor - dealokujac pamiec
    
    std::cout << "\nUsunieto Prostokat!\n" << std::endl;
}

void Rectangle::Call()
{
    std::cout << "-------------\n" << "Jestem Prostokatem!" << "\n-------------" << std::endl;
}

void Rectangle::CalcArea()                                              // obliczanie pola za pomoca petli i "domnazania" zmiennej area
{
    std::vector<int>::iterator ptr;

    for (ptr = sides.begin(); ptr < sides.end(); ptr++)
    {
        area *= *ptr;
    }

}

void Rectangle::CalcPerimiter()                                         // obliczanie obwodu mnozac przez 2 i dodajac do siebie miejsca wektorow
{
    int a = *(sides.begin());
    int b = *(sides.begin() + 1);
    perimiter = 2 * a + 2 * b;
}

unsigned int Rectangle::GetArea()
{
    return area;
}

unsigned int Rectangle::GetPerimiter()
{
    return perimiter;
}



//------------------------
//     Trojkat Bazowy
//------------------------

void TriangleBase::Call()
{
    std::cout << "-------------\n" << "Jestem Trojkatem!" << "\n-------------" << std::endl;
}

void TriangleBase::CalcArea()                                               // oblicza pole za pomoca wzoru z polowa obwodu
{
    int a = *(sides.begin());
    int b = *(sides.begin() + 1);
    int c = *(sides.begin() + 2);

    double s = perimiter/2;

    area = sqrt(s * (s - a) * (s - b) * (s - c)); 
}

void TriangleBase::CalcPerimiter()                                          // oblicza obwod dodajac do siebie poszczegolne wartosci indeksow tablicy
{
    int a = *(sides.begin());
    int b = *(sides.begin() + 1);
    int c = *(sides.begin() + 2);
    
    perimiter = (a) + (b) + (c);
}

void TriangleBase::CalcAngles()                                             // ustala katy za pomoca twierdzenia cosinusow
{
    double a = *(sides.begin());
    double b = *(sides.begin() + 1);
    double c = *(sides.begin() + 2);

    double cosA = ((b * b) + (c * c) - (a * a)) / (2 * b * c);
    double cosB = ((c * c) + (a * a) - (b * b)) / (2 * c * a);
    
    double degreesA = acos(cosA) * (180.0/M_PI);
    double degreesB = acos(cosB) * (180.0/M_PI);
    
    angles[0] = degreesA;
    angles[1] = degreesB;
    angles[2] = 180 - angles[1] - angles[0];
}

double TriangleBase::GetArea()
{
    return area;
}

unsigned int TriangleBase::GetPerimiter()
{
    return perimiter;
}

//-------------------
//     Trojkat
//-------------------

Triangle::Triangle( unsigned int x, unsigned int y, unsigned int z )     // konstruktor kopiuje x y z do tablicy 3-elementowej sides
{
    sides.push_back(x);
    sides.push_back(y);
    sides.push_back(z);


    CalcArea();
    CalcPerimiter();
    CalcArea();
}

Triangle::~Triangle()
{
    std::vector<int>().swap(sides);                                     // czyscimy sides swapujac go za utworzony na szybko pusty wektor - dealokujac pamiec
    delete[] angles;                                                    // dealokujemy tablice angles
    
    std::cout << "\nUsunieto Trojkat!\n" << std::endl;
}



//-----------------------------
//     Trojkat Prostokaty
//-----------------------------

TriRight::TriRight( unsigned int x, unsigned int y, unsigned int z )
{
    sides.push_back(x);
    sides.push_back(y);
    sides.push_back(z);

    CalcAngles();
    CalcPerimiter();
    CalcArea();
}

TriRight::~TriRight()
{
    std::vector<int>().swap(sides);                                     // czyscimy sides swapujac go za utworzony na szybko pusty wektor - dealokujac pamiec
    delete[] angles;                                                    // dealokujemy tablice angles

    std::cout << "\nUsunieto Trojkat Prostokatny!" << std::endl;
}

void TriRight::CalcAngles()                                             // oblicza katy korzystajac z sinusa i wlasciwosci trojkata prostokatnego
{
    auto a = std::min_element(sides.begin(), sides.end());
    auto c = std::max_element(sides.begin(), sides.end());
    
    std::cout<<*a<<std::endl;
    double aAngle = asin((*a * 1.0) / (*c * 1.0)) * (180.0/M_PI);
    double bAngle = 90.0 - aAngle;
    
    std::cout<<aAngle;

    angles[0] = aAngle;
    angles[1] = bAngle;
}

//-------------------
//       Kolo
//-------------------

Disc::Disc( unsigned int x )                                            // konstruktor kopiuje x do zmiennej r
{
    r = x;

    CalcPerimiter();
    CalcArea();
}

Disc::~Disc()
{
    std::cout << "\nUsunieto Kolo!\n" << std::endl;
}

void Disc::Call()
{
    std::cout << "-------------\n" <<"Jestem Kolem!" << std::endl;
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
    std::string output = "\n\nBoki:\n";
    std::vector<int>::iterator ptr;
    
    for (ptr = r.sides.begin(); ptr < r.sides.end(); ptr++) 
        output += std::to_string(*ptr) + "\n";
    
    output += "\nKat: 90\n";

    os << output << std::endl;
    
    return os;
};

std::ostream& operator<<( std::ostream& os, Triangle& t)
{
    std::string output = "\n\nBoki:\n";

    for(auto& v: t.sides)
    {
        output += std::to_string(v) + "\n";
    }

    output += "\nKaty:\n";

    for(int i = 0; i < 3; i++)
    {
        output += std::to_string(t.angles[i]) + "\n";
    }

    os << output;

    return os;
};

std::ostream& operator<<( std::ostream& os, TriRight& t)
{    
    std::string output = "\n\nBoki:\n";

    for(auto& v: t.sides)
    {
        output += std::to_string(v) + "\n";
    }

    output += "\nKaty:\n90\n";

    for(int i = 0; i < 2; i++)
    {
        output += std::to_string(t.angles[i]) + "\n";
    }

    os << output;

    return os;
};

std::ostream& operator<<( std::ostream& os, Disc& d)
{
    os << "\n\nPromien: " << d.r << std::endl;
    return os;
};
