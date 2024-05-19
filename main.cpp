#include <iostream>
#include <memory>
#include "./lib/Shapes.h"

int main()
{
    std::string buf;
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
            std::cin >> buf;

            try
            {
                userChoice = std::stoi( buf );
                if(not((userChoice == 1) || (userChoice == 2)))
                {
                    throw 1;
                }
            }

            catch (std::exception& err) // inne przypadki
            {
                std::cout << "\nPodaj prawdziwy numer!\n";
                continue;
            }

            catch (int num) // jesli wpisana zostala zla opcja
            {
                std::cout << "\nPodaj prawdziwa opcje!\n";
                continue;
            }

            switch(userChoice)
            {
                case 1:
                    flag = 0;
                    break;
                case 2:
                    std::cout << "Koncze program!" << std::endl;
                    exit(EXIT_SUCCESS);
            }
        }
        
        flag = 1; // reset flaga

        while(flag == 1) // petla na wybor figury i jej paremetrow, wypisanie danych
        {
            try
            {
                std::cout << "Dostepne opcje:\n1. Prostokat \n2. Trojkat \n3. Trojkat prostokatny \n4. Kolo \n5. Test Figur \n6. Powrot do poczatku programu \n7. Wyjscie \n-> ";
                std::cin >> buf;
                userChoice = std::stoi(buf);
                if((userChoice < 1) || (userChoice > 7))
                {
                    throw 1;
                }
            }
            
            catch (std::exception& err) // inne przypadki
            {
                std::cout << "\nPodaj prawdziwy numer!\n";
                continue;
            }

            catch (int num) // jesli wpisana zostala zla opcja
            {
                std::cout << "\nPodaj prawdziwa opcje!\n";
                continue;
            }

            switch(userChoice)
            {
                case 1:
                {
                    try
                    {
                        std::cout << "\nPodaj wysokosc prostokata: ";
                        std::cin >> buf;
                        std::cout << std::endl;
                        
                        a = std::stoi(buf);

                        if (a < 1)
                        {
                            throw 1;
                        }
                        else if (a > 50)
                        {
                            throw 2;
                        }

                        std::cout << "\nPodaj szerokosc prostokata: ";
                        std::cin >> buf;
                        std::cout << std::endl;

                        b = std::stoi(buf);

                        if (b < 1)
                        {
                            throw 3;
                        }
                        else if (b > 50)
                        {
                            throw 4;
                        }
                    }

                    catch (int num) // jesli numer poza zakresem 0-50, case'y podwojone zeby latwo mozna bylo rozdzielic pozniej jakby byla potrzeba
                    {
                        switch(num)
                        {
                            case 1:
                            case 3:
                                std::cout<<"Dlugosc nie moze byc mniejsza od 1!\n";
                                continue;
                            
                            case 2:
                            case 4:
                                std::cout<<"Dlugosc nie moze byc za dluga (max 50)!\n";
                                continue;
                        }
                    }
                    
                    catch (std::exception& e) // inne przypadki
                    {
                        std::cout << "\nPodaj prawdziwa, naturalna liczbe!\n";
                        continue;
                    }
                    

                    std::unique_ptr<Rectangle> obj (new Rectangle(a, b));                               // inteligentny wskaznik - dokladniej unique_pointer
                    
                    std::cout << "\nPole: " << obj->GetArea() << std::endl;
                    std::cout << "Obwod: " << obj->GetPerimiter() << std::endl;

                    std::cout << "\n------------------" << *obj << "------------------" << std::endl;   // tutaj korzystam z przeciazonego operatora <<, 
                }                                                                                       // podobnie dla innych figur

                    flag = 0;
                    break;
                
                case 2:
                {
                    try
                    {
                        std::cout << "\nPodaj bok A trojkata: ";
                        std::cin >> buf;
                        std::cout << std::endl;
                        
                        a = std::stoi(buf);

                        if (a < 1)
                        {
                            throw 1;
                        }
                        else if (a > 50)
                        {
                            throw 2;
                        }

                        std::cout << "\nPodaj bok B trojkata: ";
                        std::cin >> buf;
                        std::cout << std::endl;
                        
                        b = std::stoi(buf);

                        if (b < 1)
                        {
                            throw 3;
                        }
                        else if (b > 50)
                        {
                            throw 4;
                        }

                        std::cout << "\nPodaj bok C trojkata: ";
                        std::cin >> buf;
                        std::cout << std::endl;

                        c = std::stoi(buf);

                        if (c < 1)
                        {
                            throw 5;
                        }
                        else if (c > 50)
                        {
                            throw 6;
                        }

                        if (not ( (a + b > c) && (b + c > a) && (a + c > b) ))
                        {
                            throw 7;
                        }
                    }
                    catch (int num) // jesli numer poza zakresem 0-50 oraz sprawdzenie warunku istnienia, case'y potrojone rowniez zeby latwo mozna bylo rozdzielic pozniej
                    {
                        switch(num)
                        {
                            case 1:
                            case 3:
                            case 5:
                                std::cout<<"Dlugosc nie moze byc mniejsza od 1!\n";
                                continue;
                            
                            case 2:
                            case 4:
                            case 6:
                                std::cout<<"Dlugosc nie moze byc za dluga (max 50)!\n";
                                continue;
                            
                            case 7:
                                std::cout << "Wartosci nie spelniaja warunku istnienia trojkata!\n";
                                continue;
                        }
                    }
                    
                    catch (std::exception& e) // inne przypadki
                    {
                        std::cout << "\nPodaj prawdziwa, naturalna liczbe!\n";
                        continue;
                    }

                    std::unique_ptr<Triangle> obj (new Triangle(a, b, c)); // znowu obiekt utworzony za pomoca wskaznika inteligentnego
                                                                                                        
                    std::cout << "\nPole: " << obj->GetArea() << std::endl;
                    std::cout << "Obwod: " << obj->GetPerimiter() << std::endl;

                    std::cout << "\n------------------" << *obj << "\n------------------" << std::endl;
                }

                    flag = 0;
                    break;

                case 3:
                {
                    try
                    {
                        std::cout << "\nPodaj bok A trojkata: ";
                        std::cin >> buf;
                        std::cout << std::endl;
                        
                        a = std::stoi(buf);

                        if (a < 1)
                        {
                            throw 1;
                        }
                        else if (a > 50)
                        {
                            throw 2;
                        }

                        std::cout << "\nPodaj bok B trojkata: ";
                        std::cin >> buf;
                        std::cout << std::endl;
                        
                        b = std::stoi(buf);

                        if (b < 1)
                        {
                            throw 3;
                        }
                        else if (b > 50)
                        {
                            throw 4;
                        }

                        std::cout << "\nPodaj bok C trojkata: ";
                        std::cin >> buf;
                        std::cout << std::endl;

                        c = std::stoi(buf);

                        if (c < 1)
                        {
                            throw 5;
                        }
                        else if (c > 50)
                        {
                            throw 6;
                        }

                        if (not ( (a*a + b*b == c*c) || (b*b + c*c == a*a) || (a*a + c*c == b*b) ))
                        {
                            throw 7;
                        }
                    }
                    catch (int num) // jesli numer poza zakresem 0-50 oraz sprawdzenie pitagorasa
                    {
                        switch(num)
                        {
                            case 1:
                            case 3:
                            case 5:
                                std::cout<<"Dlugosc nie moze byc mniejsza od 1!\n";
                                continue;
                            
                            case 2:
                            case 4:
                            case 6:
                                std::cout<<"Dlugosc nie moze byc za dluga (max 50)!\n";
                                continue;
                            
                            case 7:
                                std::cout << "Wartosci nie spelniaja twierdzenia pitagorasa!\n";
                                continue;
                        }
                    }
                    
                    catch (std::exception& e) // inne przypadki
                    {
                        std::cout << "\nPodaj prawdziwa, naturalna liczbe!\n";
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
                    try
                    {
                        std::cout << "\nPodaj promien: ";
                        std::cin >> buf;
                        std::cout << std::endl;

                        a = std::stoi(buf);

                        if(a < 1)
                        {
                            throw 1;
                        }
                        else if(a > 50)
                        {
                            throw 2;
                        }
                    }

                    catch (int num)
                    {
                        switch(num)
                        {
                            case 1:
                                std::cout<<"Dlugosc nie moze byc mniejsza od 1!\n";
                                continue;
                            
                            case 2:
                                std::cout<<"Dlugosc nie moze byc za dluga (max 50)!\n";
                                continue;
                        }
                    }

                    catch (std::exception& err)
                    {
                        std::cout << "\nPodaj prawdziwa, naturalna liczbe!\n";
                        continue;
                    }
                    
                    Disc obj(a);
                    
                    obj.CalcArea();
                    std::cout << "Pole: " << obj.GetArea() << std::endl;

                    obj.CalcPerimiter();
                    std::cout << "Obwod: " << obj.GetPerimiter() << std::endl;

                    std::cout << "\n------------------" << obj << "\n------------------" << std::endl;
                }

                    flag = 0;
                    break;

                case 5: // polimorfizm
                {
                    Shape **tab = new Shape*[3];

                    tab[0] = new Rectangle(1,1);
                    tab[1] = new TriangleBase();
                    tab[2] = new Disc();


                    for(int i = 0; i < 3; i++)
                    {
                        tab[i]->Call();
                        delete(tab[i]);
                    }
                    delete[](tab);
                    break;
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