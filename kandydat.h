#include <vector>
using namespace std;

struct ob{
       double _value;
       string _string;
};

struct kandydat{
public:

    
    kandydat(){}
    void insert(int x, const char* str){
        ob tmp;
        tmp._value = x;
        tmp._string = str;
        cele.push_back(tmp);
    }
    
    void print()const{
        int i;
        for (i=0; i< (cele.size()-2); i++){
            cout << cele[i]._string << " (" << cele[i]._value << ") ";
        }

    }

    //zbiory rozmyte
    void fuzzy(bool* kryteria){
        int tmp = 0;
        //doświadczenie obliczne jest z założeniem, że z każdym
        //kolejnym rokiem pracy zdobywamy coraz mniej doświadczenia w branży
        if (kryteria[0]==1){
            if (cele[tmp]._value == 0) cele[tmp]._value = 0;
            else if (cele[tmp]._value <= 2) cele[tmp]._value = 0.15*cele[tmp]._value;
            else if (cele[tmp]._value <= 5) cele[tmp]._value = 0.3+ 0.2/3.*(cele[tmp]._value-2);
            else if (cele[tmp]._value <= 10) cele[tmp]._value = 0.5 + 0.25/5.*(cele[tmp]._value-5);
            else if (cele[tmp]._value <= 20) cele[tmp]._value = 0.75 + 0.15/10.*(cele[tmp]._value-10);
            else if (cele[tmp]._value <= 40) cele[tmp]._value = 0.9 + 0.1/20.*(cele[tmp]._value-20);
            else cele[tmp]._value = 1.;
            tmp++;
        }
        
        //prawo jazdy kryterium to powinno się stosować tylko jeśli prawo jazdy jest NIEZBĘDNE
        if (kryteria[1]==1){
            if (cele[tmp]._value == 0) cele[tmp]._value = 0;
            if (cele[tmp]._value == 1) cele[tmp]._value = 1;
            tmp++;
        }
        
        //języki obce - znajomośc jednego ma duży wpływ, każdego kolejnego coraz mniejszy
        if (kryteria[2]==1){
            if (cele[tmp]._value==0) cele[tmp]._value = 0.0;
            else cele[tmp]._value = 1. - 1./(1.+cele[tmp]._value);
            tmp++;
        }
        
        //jezyki programowania - to samo co języki obce
        if (kryteria[3]==1){
            if (cele[tmp]._value==0) cele[tmp]._value = 0.0;
            else cele[tmp]._value =  1. - 1./(1.+cele[tmp]._value);
            tmp++;
        }
        //szybkosc uczenia sie - skala od 0-10 zgodnie z uznaniem rekrutującego, rozmycie liniowe
        if (kryteria[4]==1){
            cele[tmp]._value /= 10.;
            tmp++;
        }
        //wiek - pracować można od 16 roku życia, najlepszy wynik ma kandydat 20-letni, potem coraz gorszy wynik
        if(kryteria[5]==1){
            if (cele[tmp]._value < 16) cele[tmp]._value = 0.0;
            else if (cele[tmp]._value <= 20) cele[tmp]._value = 20 - cele[tmp]._value * 0.25;
            else cele[tmp]._value = 1. - 1./60. * cele[tmp]._value;
            tmp++;
        }
        //technologia - zdolności wykorzystania technologi z jaką pracownik będzie miał do czynienia,
        // wartość i rozmycie tak samo jak w szybkości uczenia się
        if (kryteria[6]==1){
            cele[tmp]._value /= 10.;
            tmp++;
        }
        //wyksztalcenie - im wyzsze doswiadczenie tym lepszy wynik
        if (kryteria[7]==1){
            if (cele[tmp]._value == 0) cele[tmp]._value = 0.0;
            else if (cele[tmp]._value == 1) cele[tmp]._value = 0.2;
            else if (cele[tmp]._value == 2) cele[tmp]._value = 0.6;
            else if (cele[tmp]._value == 3 ) cele[tmp]._value = 0.8;
            else if (cele[tmp]._value == 4) cele[tmp]._value = 1.;
            tmp++;
        }
        //sprawnosc fizyczna - to samo co w szybkosci uczenia
        if (kryteria[8]==1){
            cele[tmp]._value /= 10.;
            tmp++;
        }
        //zdolnosci managerskie - to samo co w szybkosci uczenia
        if (kryteria[9]==1){
            cele[tmp]._value /= 10.;
            tmp++;
        }
        //pensja - obliczana liniowo zgodnie z podanymi przez rekrutera granicami pensji
        if(cele[tmp]._value < cele[tmp+1]._value)
            cele[tmp]._value = 1.;
        else if(cele[tmp]._value > cele[tmp+2]._value) 
            cele[tmp]._value = 0.;
        else cele[tmp]._value =  1.0 - (cele[tmp]._value  - cele[tmp+1]._value )
                                /(cele[tmp+2]._value - cele[tmp+1]._value);
    }
    
    
    ~kandydat(){}
    
    
    vector<ob> cele;
    double przystosowania[3];
};