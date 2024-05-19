#include <iostream>
#include <memory>
#include "./lib/Shapes.h"

int main()
{
    int userChoice;
    int flag; // flag jako kontroler dzialania petli wewnetrznych

    int * obj = nullptr;
    int a;
    int b;
    int c;

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
            std::cout << "Dostepne opcje:\n1. Prostokat \n2. Trojkat \n3. Trojkat prostokatny \n4. Kolo \n5. Test Figur \n6. Powrot do poczatku programu \n7. Wyjscie \n-> ";
            std::cin >> userChoice;

            switch(userChoice)
            {
                case 1:
                {
                    std::cout << "\nPodaj wysokosc prostokata: ";
                    std::cin >> a;
                    std::cout << std::endl;
                    
                    std::cout << "\nPodaj szerokosc prostokata: ";
                    std::cin >> b;
                    std::cout << std::endl;

                    std::unique_ptr<Rectangle> obj (new Rectangle(a, b));                               // inteligentny wskaznik - dokladniej unique_pointer
                    
                    std::cout << "\nPole: " << obj->GetArea() << std::endl;
                    std::cout << "Obwod: " << obj->GetPerimiter() << std::endl;

                    std::cout << "\n------------------" << *obj << "------------------" << std::endl;
                }

                    flag = 0;
                    break;
                
                case 2:
                {
                    std::cout << "\nPodaj bok A trojkata: ";
                    std::cin >> a;
                    std::cout << std::endl;
                    
                    std::cout << "\nPodaj bok B trojkata: ";
                    std::cin >> b;
                    std::cout << std::endl;

                    std::cout << "\nPodaj bok C trojkata: ";
                    std::cin >> c;
                    std::cout << std::endl;

                    if (not ( (a + b > c) && (b + c > a) && (a + c > b) ))
                    {
                        std::cout << "\nWartosci nie spelniaja warunku istnienia trojkata!" << std::endl;
                        continue;
                    }
                    
                    std::unique_ptr<Triangle> obj (new Triangle(a, b, c));                              // znowu obiekt utworzony za pomoca wskaznika inteligentnego
                                                                                                        
                    std::cout << "\nPole: " << obj->GetArea() << std::endl;
                    std::cout << "Obwod: " << obj->GetPerimiter() << std::endl;

                    std::cout << "\n------------------" << *obj << "\n------------------" << std::endl;
                }

                    flag = 0;
                    break;

                case 3:
                {
                    std::cout << "\nPodaj bok A trojkata: ";
                    std::cin >> a;
                    std::cout << std::endl;
                    
                    std::cout << "\nPodaj bok B trojkata: ";
                    std::cin >> b;
                    std::cout << std::endl;

                    std::cout << "\nPodaj bok C trojkata: ";
                    std::cin >> c;
                    std::cout << std::endl;

                    if (not ( (a*a + b*b == c*c) || (b*b + c*c == a*a) || (a*a + c*c == b*b) ))
                    {
                        std::cout << "\nWartosci nie spelniaja twierdzenia pitagorasa!" << std::endl;
                        continue;
                    }

                    TriRight obj(a, b, c);
                    obj.Call();
                    std::cout << "\nPole: " << obj.GetArea() << std::endl;
                    std::cout << "Obwod: " << obj.GetPerimiter() << std::endl;

                    std::cout << "\n------------------" << obj << "\n------------------" << std::endl;
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

                    std::cout << "\n------------------" << obj << "\n------------------" << std::endl;
                }

                    flag = 0;
                    break;

                case 5:
                {
                    Shape **tab = new Shape*[3];

                    tab[0] = new Rectangle();
                    tab[1] = new TriangleBase();
                    tab[2] = new Disc();


                    for(int i = 0; i < 3; i++)
                    {
                        tab[i]->Call();
                        delete(tab[i]);
                    }
                }

                case 6:
                    std::cout << "Rozpoczynam od nowa!" << std::endl;
                    flag = 2;
                    break;

                case 7:
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