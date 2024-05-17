#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <cmath>

class Shape
{
    private:
        unsigned perimiter;
        
};

class Rectangle : public Shape
{
    public:
        unsigned int * sides[2];

        explicit Rectangle( unsigned int = 0, unsigned int = 0 );  // konstruktor kopiujacy

        void CalcArea();                         // obliczanie pola
        void CalcPerimiter();                    // obliczanie obowdu
        void PrintData();                        // wypisywanie boku i kata
        unsigned int GetArea();                  // zwracanie pola 
        unsigned int GetPerimiter();             // zwracanie obowdu 

    private:
        unsigned int angle = 90;
        unsigned int area;
        unsigned int perimiter;
};

class Triangle
{
    public:
        unsigned int * sides[3];

        explicit Triangle( unsigned int = 0, unsigned int = 0, unsigned int = 0 );   // konstruktor kopiujacy
        
        void CalcArea();                // obliczanie pola
        void CalcPerimiter();           // obliczanie obowdu
        void CalcAngles();              // obliczanie katow (na podstawie funkcji sinus i cos)
        double GetArea();               // zwracanie pola
        unsigned int GetPerimiter();    // zwracanie obowdu 

    private:
        double * angles[3];
        double area;
        unsigned int perimiter;
};

class Disc
{
    public:
        unsigned int r;
        
        explicit Disc( unsigned int = 0 );       // konstruktor kopiujacy
        
        void CalcArea();                // obliczanie pola
        void CalcPerimiter();           // obliczanie obowdu
        std::string GetArea();          // zwracanie pola 
        std::string GetPerimiter();     // zwracanie obowdu 

    private:
        unsigned int area;
        unsigned int perimiter;

    friend std::ostream& operator<<( std::ostream&, Disc& );
};

#endif