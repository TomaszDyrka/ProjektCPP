#ifndef SHAPES_H
#define SHAPES_H

#include <string>

class Square
{
    public:
        unsigned int a;
        
        explicit Square( unsigned int = 0 );     // konstruktor kopiujacy
        
        void CalcArea();                // obliczanie pola
        void CalcPerimiter();           // obliczanie obowdu
        void PrintData();               // wypisywanie boku i kata
        unsigned int GetArea();         // zwracanie pola 
        unsigned int GetPerimiter();    // zwracanie obowdu 
    
    private:
        unsigned int angle = 90;
        unsigned int area;
        unsigned int perimiter;
};

class Rectangle
{
    public:
        unsigned int a;
        unsigned int b;

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
        unsigned int a;
        unsigned int b;
        unsigned int c;

        explicit Triangle( unsigned int = 0 );   // konstruktor kopiujacy
        
        void CalcArea();                // obliczanie pola
        void CalcPerimiter();           // obliczanie obowdu
        void PrintData();               // wypisywanie bokow i katow
        unsigned int GetArea();         // zwracanie pola
        unsigned int GetPerimiter();    // zwracanie obowdu 

    private:
        unsigned int angleAlpha;
        unsigned int angleBeta;
        unsigned int angleGamma;
        unsigned int area;
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