#include "functions.h"

int main()
{
    vector<student> A;
    int num=0;
    int inp, gen,asmuo;
Ivestis:
    cout << "Ivesti duomenis ranka (0) ar skaityti is failo (1): ";
    cin >> inp;
    if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Ivestis; }
    if(inp==0)
    {
        Generavimas:
        A.push_back(student());
        ivedimas(A, num);
        cout << "Pazymius ivesti ranka - (0). Pazymius generuoti atsitiktinai - (1): ";
        cin >> gen;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Generavimas; }
        if(gen==0)
        {
            pazymiai(A, num);
            rastiMediana(A, num);
            rastiVidurki(A, num);
        }
        if(gen==1)
        {
            generuoti(A, num);
            rastiMediana(A, num);
            rastiVidurki(A, num);
        }
        if(!((gen>=0)&&(gen<=1))) goto Generavimas;
        num++;
        Pridejimas:
        cout << "Jei norite prideti dar viena asmeni iveskite 1. Jei norite testi, iveskite 0: ";
        cin >> asmuo;
        if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Negalima reiksme, bandykite dar karta\n"; goto Pridejimas; }
        if(asmuo==1) goto Generavimas;
        if(!((asmuo>=0)&&(asmuo<=1))) goto Pridejimas;
    }
    for(int i=0; i<num; i++)
    {
        if(i==0) header();
        rikiavimas(A, num);
        spausdinimas(A, i);
    }
    if(inp==1)
    {
        num=0;
        std::ifstream in("kursiokai.txt");
        in.ignore(1024, '\n');
        skaitymas(A, num, in);
        for (int i=0; i<num; i++)
        {
            rastiMediana(A, i);
            rastiVidurki(A, i);
            if (i==0)
                header();
//            rikiavimas(A, num);
            spausdinimas (A, i);
        }
        in.close();
    }
    if(!((inp>=0)&&(inp<=1))) goto Ivestis;
    return 0;
}
