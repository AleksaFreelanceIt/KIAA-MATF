#include <iostream>
#include <vector>

using namespace std;
vector<int> roditelj;                               //Niz koji pokazuje na roditelja broja, predstavnik skupa je sam sebi roditelj
vector<int> rang;                                  //Predstavlja visinu disjunktnog skupa

void inicijalizuj_skupove(int broj_el){        
    roditelj.resize(broj_el);
    rang.resize(broj_el);
    
    for(int i = 0; i < broj_el; i++){
        roditelj[i] = i;                               //Pri inicijalizaciji svaki broj je sam sebi roditelj
        rang[i] = 0;                                 //Visina je 0 svakom skupu
    }        
}

int pronadji_skup(int element){
    int x = element;
    while(x != roditelj[x]){                      //Predstavlja validan argument jer kad stignemo do prestavnika on je sam sebi roditelj pa je nebitno koliko roditelja prelazimo preko korena
      roditelj[x] = roditelj[roditelj[x];       //Iterativno se penjemo kroz cvorove
      x = roditelj[x];
    }
    return x;
}

void unija_skupova(int element_x, int element_y){
  int skup_x = pronadji_skup(element_x);                          //Nalazimo predstavnike cvorova
  int skup_y = pronadji_skup(element_y);
  
  if(skup_x == skup_y) return;                                         //Ako su isti predstavnici unija ne vraca nista, skup ostaje isti
  if(rang[skup_x] < rang[skup_y]) swap(skup_x,skup_y);    //Cist uslov jer hocemo da manji skup prispojimo na veci
  
  roditelj[skup_y] = skup_x;                                             //Prispojimo predstavnika jednog skupa na drugi
  if(rang[skup_x] == rang[skup_y]) rang[skup_x]++;          //Ako su bili istog ranga, vizuelno je jasno zasto se povecava za 1
}

int main(){

return 0;
}
