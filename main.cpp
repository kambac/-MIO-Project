#include <iostream>
#include "kandydat.h"

using namespace std;

int main(){
    int n;
    cout << "WITAMY W PROGRAMIE ROZMYTE ZATRUDNIANIE!\n";
    cout << "Podaj liczbe kandydatow:\n";
    cin >> n;
    if(n < 0)
    {
        cout << -n << " pracownikow zostalo zwolnionych z twojej firmy. Naucz sie pisac dodatnie liczby.\n";
        return 0;
    }
    vector <kandydat> tab(n);
    //kandydat* tab = new kandydat[n];
    int tmp=1;
    //5 kryteriow
    unsigned l_kryteriow =10 +2;
    bool kryteria[l_kryteriow];
    int pensja[2];
    for (unsigned i=0; i<l_kryteriow; i++){
        kryteria[i]=0;
    }
    string opis[l_kryteriow];
    opis[0] = "1 - doswiadczenie\n";
    opis[1] = "2 - prawo jazdy(tylko jesli niezbedne)\n";
    opis[2] = "3 - jezyki obce\n";
    opis[3] = "4 - jezyki programowania\n";
    opis[4] = "5 - umiejetnosc szybkiego przyswajania wiedzy\n";
    opis[5] = "6 - wiek\n";
    opis[6] = "7 - sprawnosc w uzywaniu technologii\n";
    opis[7] = "8 - wyksztalcenie\n";
    opis[8] = "9 - sprawnosc fizyczna\n";
    opis[9] = "10 - zdolnosci managerskie\n";
    

    cout << "Wybierz kryteria:\n";
    //cout << "1 - doswiadczenie\n 2 - prawo jazdy\n 3 - jezyki obce\n 4 - jezyki programowania\n 5 - umiejetnosc szybkiego przyswajania wiedzy\n 0 - zakoncz wybor\n 9 - anuluj wszystkie wybory\n";
    bool First_flag = 0;
    while(tmp!=0){
        if(First_flag)
        {
            cout << "Wybrane do tej pory:\n";
            for(unsigned i=0; i<l_kryteriow; i++)
                if(kryteria[i])
                    cout << opis[i];

        }
        First_flag=1;
        cout << "Mozliwe do wyboru:\n";
        for(unsigned i=0; i<l_kryteriow; i++)
            if(!kryteria[i])
                cout << opis[i];
        cout << "Aby anulowac jeden wybor, wpisz numer kryterium ponownie\n0 - zakoncz wybor\n-1 - anuluj wszystkie wybory\n";
        cin >> tmp;
        if(kryteria[tmp-1] == 1)
        {
            kryteria[tmp-1] = 0;   
        }
        else if (tmp >= 1 && tmp <= l_kryteriow) kryteria[tmp-1] = 1;
        if (tmp==-1){
            for (unsigned i=0; i<l_kryteriow; i++){
                kryteria[i]=0;
            }
        }
        
    }
    cout << "Minimalna miesieczna pensja jaka jestes gotowy zaplacic(co najmniej 2000 zl):\n";
    while(true)
    {
        cin >> tmp;
        if(tmp >= 2000 && tmp <= 1000000)
        {
            pensja[0] = tmp;
            break;
        }
        else cout << "NIEPOPRAWNE DANE\n";
    }
    cout << "Maksymalna miesieczna pensja jaka jestes gotowy zaplacic:\n";
    while(true)
    {
        cin >> tmp;
        if(tmp >= pensja[0] && tmp <= 1000000)
        {
            pensja[1] = tmp;
            break;
        }
        else cout << "NIEPOPRAWNE DANE\n";
    }
    for (unsigned i=0; i<n; i++){
        cout << "Kandydat (" << i+1 << ")\n";
        
        if (kryteria[0]==1){
            while (true){
                cout << "Doswiadczenie(lata):\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 100){
                    tab[i].insert(tmp, "doswiadczenie");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        
        if (kryteria[1]==1){
            while (true){
                cout << "Prawo jazdy(1-tak,0-nie):\n";
                cin >> tmp;
                if (tmp == 0 || tmp == 1){
                    tab[i].insert(tmp, "prawo jazdy");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        
        if (kryteria[2]==1){
            while (true){
                cout << "Ilosc poznanych językow obcych:\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 100){
                    tab[i].insert(tmp, "jezyki obce");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        //ograniczenie
        if (kryteria[3]==1){
            while (true){
                cout << "Ilosc opanowanych językow programowania:\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 100){
                    tab[i].insert(tmp, "jezyki programowania");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }

        if (kryteria[4]==1){
            while (true){
                cout << "Umiejetnosc szybkiego przyswajania wiedzy(od 0 do 10):\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 10){
                    tab[i].insert(tmp, "przyswajanie wiedzy");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        if (kryteria[5]==1){
            while (true){
                cout << "wiek(od 0 do 100):\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 100){
                    tab[i].insert(tmp, "wiek");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        if (kryteria[6]==1){
            while (true){
                cout << "umiejetnosc korzystania z technologii(od 0 do 10):\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 10){
                    tab[i].insert(tmp, "technologia");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        if (kryteria[7]==1){
            while (true){
                cout << "wyksztalcenie(0 - podstawowe, 1 - srednie, 2 - wyzsze(licencjat/inzynier), 3 - magister, 4 - doktorat i wyżej ):\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 4){
                    tab[i].insert(tmp, "wyksztalcenie");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        if (kryteria[8]==1){
            while (true){
                cout << "sprawnosc fizyczna(od 0 do 10):\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 10){
                    tab[i].insert(tmp, "sprawnosc fizyczna");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
        if (kryteria[9]==1){
            while (true){
                cout << "zdolnosci managerskie(od 0 do 10):\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 10){
                    tab[i].insert(tmp, "managerskie");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }
        }
            while (true){
                cout << "Pensja zaproponowana(miesieczna)\n";
                cin >> tmp;
                if (tmp >= 0 && tmp <= 1000000){
                    tab[i].insert(tmp, "Pensja");
                    break;}
                else{
                    cout << "NIEPOPRAWNE DANE\n";
                }
            }    
    tab[i].insert(pensja[0], "Minimalna pensja");
    tab[i].insert(pensja[1], "Maksymalna pensja");
        
    }
    double przystosowanie[n][4];
    double najlepsze_przystosowanie[4]={0,0,0};
    double najlepszy_indeks[4] = {0,0,0};
    for (unsigned i=0; i<n; i++){
        tab[i].fuzzy(kryteria);
        cout << "\nKandydat " << i+1 << ": ";
        tab[i].print();
        
        cout << "\nPrzystosowanie kandydata:\nt-norma minimum: ";
        
        przystosowanie[i][0] = 2;
        for(unsigned j=0; j< (tab[i].cele.size() -2); j++)
        {
            if(przystosowanie[i][0] > tab[i].cele[j]._value)
                przystosowanie[i][0] = tab[i].cele[j]._value;
        }
        if(najlepsze_przystosowanie[0] < przystosowanie[i][0])
        {
            najlepsze_przystosowanie[0] = przystosowanie[i][0];
            najlepszy_indeks[0] = i+1;
        }
        cout << przystosowanie[i][0] << "\nt-norma iloczyn: ";
        
        przystosowanie[i][1] = 1;
        for(unsigned j=0; j< (tab[i].cele.size() -2); j++)
        {
            przystosowanie[i][1] *= tab[i].cele[j]._value;
        }
        if(najlepsze_przystosowanie[1] < przystosowanie[i][1])
        {
            najlepsze_przystosowanie[1] = przystosowanie[i][1];
            najlepszy_indeks[1] = i+1;
        }
        cout << przystosowanie[i][1] << "\ns-norma maksimum: ";
        
        przystosowanie[i][2] = -1;
        for(unsigned j=0; j< (tab[i].cele.size() -2); j++)
        {
            if(przystosowanie[i][2] < tab[i].cele[j]._value)
                przystosowanie[i][2] = tab[i].cele[j]._value;
        }
        if(najlepsze_przystosowanie[2] < przystosowanie[i][2])
        {
            najlepsze_przystosowanie[2] = przystosowanie[i][2];
            najlepszy_indeks[2] = i+1;
        }
        cout << przystosowanie[i][2] <<endl;
    }
    cout << "Najlepszy kandydat wedlug t-normy minimum(ma najlepsza najgorzej przystosowana ceche) to kandydat: " << najlepszy_indeks[0] << " z wynikiem: "<< najlepsze_przystosowanie[0]<<"\n";
    cout << "Najlepszy kandydat wedlug t-normy iloczyn(bierze pod uwage wszystkie cechy) to kandydat: " << najlepszy_indeks[1] << " z wynikiem: "<< najlepsze_przystosowanie[1]<<"\n";
    cout << "Najlepszy kandydat wedlug s-normy maksimum(ma najlepsza najlepsza przystosowana ceche) to kandydat: " << najlepszy_indeks[2] << " z wynikiem: "<< najlepsze_przystosowanie[2]<<"\n";
    
}