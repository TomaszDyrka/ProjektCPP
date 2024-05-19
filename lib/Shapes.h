#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <cmath>
#include <vector>

class Shape
{
    public:
        std::vector<int> sides;
        
        unsigned int perimiter = 0;
        double area = 1.0;

        virtual void Call();                             // wypisanie nazwe figury
        virtual void CalcArea() = 0;                         // obliczanie pola
        virtual void CalcPerimiter();                        // obliczanie obowdu

};

class Rectangle : 
    public Shape
{
    public:
        explicit Rectangle( unsigned int = 0, unsigned int = 0 );  // konstruktor kopiujacy
        ~Rectangle();                            // destruktor

        void Call();                             // wypisanie nazwy figury
        void CalcArea();                         // obliczanie pola
        void CalcPerimiter();                    // obliczanie obowdu
        unsigned int GetArea();                  // zwracanie pola 
        unsigned int GetPerimiter();             // zwracanie obowdu 
        friend std::ostream& operator<<( std::ostream&, Rectangle& );

};

class TriangleBase:
    public Shape
{
    public:
        double * angles = (double*)calloc(3, sizeof(double));

        void Call();                            // wypisanie nazwy figury
        virtual void CalcArea();                // obliczanie pola
        void CalcPerimiter();                   // obliczanie obowdu
        virtual void CalcAngles();              // obliczanie katow (na podstawie funkcji trygonometrycznych)
        double GetArea();                       // zwracanie pola
        unsigned int GetPerimiter();            // zwracanie obowdu 

};

class Triangle:
    public TriangleBase
{
    public:
        explicit Triangle( unsigned int = 0, unsigned int = 0, unsigned int = 0 );   // konstruktor kopiujacy
        ~Triangle();                                                                 // destruktor

        friend std::ostream& operator<<( std::ostream&, Triangle& ); 

};

class TriRight : 
    public TriangleBase
{
    public:
        explicit TriRight( unsigned int = 0, unsigned int = 0, unsigned int = 0 ); // konstruktor
        ~TriRight();                    // destruktor

        void CalcAngles();              // obliczanie katow (na podstawie funkcji trygonometrycznych)
        friend std::ostream& operator<<( std::ostream&, TriRight& ); 

};

class Disc:
    public Shape
{
    public:
        unsigned int r;
        
        explicit Disc( unsigned int = 0 );       // konstruktor kopiujacy
        ~Disc();

        void Call();                    // wypisanie nazwy figury
        void CalcArea();                // obliczanie pola
        void CalcPerimiter();           // obliczanie obowdu
        std::string GetArea();          // zwracanie pola 
        std::string GetPerimiter();     // zwracanie obowdu 
        friend std::ostream& operator<<( std::ostream&, Disc& );

    private:
        unsigned int area;
        unsigned int perimiter;

};

#endif