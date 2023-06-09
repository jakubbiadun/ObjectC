#include <iostream>
#include "organizm.h"
//#include "zlab02.h"
//#include "zlab03.h"

using namespace std;

void drukujOrganizm(const Organizm & o);

int main()
{
    //1. Test kreacji obiektów
    Organizm organizm1(8,3,2);
    Organizm organizm2 = organizm1;
    Organizm organizm3(organizm1);

    cout << "Wynik testu kreacji obiektow:"
         << endl << endl;
    cout << "Organizm1:" << endl;
    drukujOrganizm(organizm1);
    cout << "Organizm2" << endl;
    drukujOrganizm(organizm1);
    cout << "Organizm3" << endl;
    drukujOrganizm(organizm2);

    //2. Test niezależności obiektów
    organizm1.posilek();
    organizm1.posilek();
    organizm2.posilek();
    organizm3.krokSymulacji();

    cout << "Wynik testu niezaleznosci obiektow:"
         << endl << endl;
    cout << "Organizm1:" << endl;
    drukujOrganizm(organizm1);
    cout << "Organizm2" << endl;
    drukujOrganizm(organizm2);
    cout << "Organizm3" << endl;
    drukujOrganizm(organizm3);

    //3. Test symulacji
    Organizm organizm4(8,3,2);

    cout << "Wynik testu symulacji:"
         << endl << endl;
    cout << "Stan poczatkowy:" << endl;
    drukujOrganizm(organizm4);

    for(int i=1; i<11; i++){

        organizm4.krokSymulacji();

        if(organizm4.paczkujacy()){
            organizm4.potomek();
            cout << "---> Potomek" << endl;
        } else organizm4.posilek();

        cout << "Po wykonaniu kroku symulacji: "
             << i << endl;
        drukujOrganizm(organizm4);
    }

    return 0;

}


void drukujOrganizm(const Organizm & o)
{
    cout << "licznikZycia: "
         << o.stanLicznikaZycia()
         << " licznikPosilkow: "
         << o.stanLicznikaPosilkow() << endl
         << "limitPosilkow: "
         << o.limitPosilkow
         << " kosztPotomka: "
         << o.kosztPotomka << endl
         << "glodny: " << o.glodny()
         << " paczkujacy: "
         << o.paczkujacy() << endl << endl;
}
