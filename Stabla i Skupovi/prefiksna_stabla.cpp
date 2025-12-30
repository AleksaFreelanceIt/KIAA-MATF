#include <iostream>
#include <map>

using namespace std;

struct Cvor{
    map<char,*Cvor> grane;                        //Mapa nam daje pristup granama po charu
    bool kraj_reci = false;                            
    string rec;                                             //Cuvamo rec u poslednjem cvoru iste, ako nam treba pri obradi, neobavezno polje
    int brojac;                                             //Cuvamo koliko reci deli konkretno slovo cvora 
};

void dodaj_rec(const string& rec, Cvor* stablo){
    for(char c : rec){                                                     //Za svako slovo u reci
        if(stablo->grane.find(c) == stablo->grane.end()){    //Ako ne postoji grana u nizu za dato slovo, napravimo je
            stablo->grane[c] = new Cvor();
        }
        stablo = stablo->grane[c];                                    //Premestamo se u cvor datog slova
    }
    stablo->rec = rec;                                                   //Posle petlje sacuvamo rec i namestimo da je kraj_reci true
    stablo->kraj_reci = true;
}

void obrisi_stablo(Cvor * stablo){
    for(auto grana : stablo->grane){                                //Za svaku granu u trenutnom cvoru rekurzivno obidji stablo i obrisi od dole na gore
        obrisi_stablo(grana.second);
    }
    delete stablo;
}

bool nadji(const string& rec, Cvor* stablo){
    for(char c : rec){                                                     //Za svako slovo u reci
        if(stablo->grane.find(c) == stablo->grane.end())    //Ako nepostoji cvor za dato slovo automatski ne postoji rec u stablu
            return false;
        stablo = stablo->grane[c];                                   //Prolazimo kroz stablo do poslednjeg slova reci
    }
    return stablo->kraj_reci;                                         //Vratimo da li je to zapravo kraj reci
}

int main(){


  return 0;
}
