#include <iostream>
#include "./lib/Shapes.h"

int main()
{
    int userChoice;
    int flag; // flag jako kontroler dzialania petli wewnetrznych

    int * obj = nullptr;
    int a;
    int b;

    while(true) // główna pętla programu
    {
        flag = 1;

        while(flag) // petla opcje
        {
            std::cout << "Co chcesz zrobic?: \n1. Utworzyc nowa figure \n2. Wyjsc \n-> ";
            std::cin >> userChoice;

            switch(userChoice)
            {
                case 1:
                    flag = 0;
                    break;
                case 2:
                    std::cout << "Koncze program!" << std::endl;
                    exit(EXIT_SUCCESS);
                default:
                    std::cout << "zla opcja!!!" << std::endl;
            }
        }
        
        flag = 1; // reset flaga

        while(flag == 1) // petla na wybor figury i jej paremetrow, wypisanie danych
        {
            std::cout << "Dostepne opcje:\n1. Kwadrat \n2. Prostokat \n3. Trojkat \n4. Kolo \n5. Powrot do poczatku programu \n6. Wyjscie \n-> ";
            std::cin >> userChoice;

            switch(userChoice)
            {
                case 2:
                    {
                    std::cout << "\nPodaj wysokosc prostokata: ";
                    std::cin >> a;
                    std::cout << std::endl;
                    
                    std::cout << "\nPodaj szerokosc prostokata: ";
                    std::cin >> b;
                    std::cout << std::endl;

                    Rectangle obj(a, b);
                    
                    obj.CalcArea();
                    std::cout << "Pole: " << obj.GetArea() << std::endl;
                    
                    obj.CalcPerimiter();
                    std::cout << "Obwod: " << obj.GetPerimiter() << std::endl;

                    obj.PrintData();
                    }

                    flag = 0;
                    break;

                case 4:
                    {
                    std::cout << "\nPodaj promien: ";
                    std::cin >> a;
                    std::cout << std::endl;
                    
                    Disc obj(a);
                    
                    obj.CalcArea();
                    std::cout << "Pole: " << obj.GetArea() << std::endl;

                    obj.CalcPerimiter();
                    std::cout << "Obwod: " << obj.GetPerimiter() << std::endl;

                    std::cout << obj;
                    }

                    flag = 0;
                    break;

                case 5:
                    std::cout << "Rozpoczynam od nowa!" << std::endl;
                    flag = 2;
                    break;

                case 6:
                    std::cout << "Koncze program!" << std::endl;
                    exit(EXIT_SUCCESS);

                default:
                    std::cout << "zla opcja!!!" << std::endl;
            }
        }

        if(flag == 2)
        {
            continue;
        }
    }   
    return 0;
}