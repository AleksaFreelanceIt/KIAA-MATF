#include <iostream>
#include <vector>

using namespace std;

int broj_dana(vector<vector<int>>& graf){
  int n = graf.size();                //Inic blok
  int brojac = 0;                     //Brojac koji treba da vratimo na kraju -1 ako ne moze da se obidju svi cvorovi
  vector<int> zavisnost(n);     //Niz zavisnosti
  vector<int> redosled;          //Niz kojim redosled se obilaze elementi
  
  for(int i = 0; i<n;i++){           //Ubacivanje u niz zavisnosti na osnovu cvorova i koje grane ulaze u njih
    for(int sused : graf[i])
      zavisnost[sused]++;
  }
  
  for(int i = 0; i < n; i++){        //Pronalazimo sve cvorove koji su nezavisni i ubacujemo ih u redosled
    if(zavisnost[i] == 0)
      redosled.push_back(i);
  }
  if(redosled.empty()) return -1;
  
  for(int i = 0; i < redosled.size(); i++){                                     //Prolazimo kroz redosled niz 
    int cvor = redosled[i];                                                   //Uzmemo cvor iz niza
    for(int sused : graf[cvor]){                                    
      zavisnost[sused]--;                                                     //Svakom susedu od tog niza smanjujemo zavisnost
      if(zavisnost[sused] <= 0) {                                          //Ako je zavinost 0 posle smanjenja onda ubacujemo u redosled
        redosled.push_back(sused);
        brojac ++;
      }
    }
  }
 if(redosled.size() == graf.size()) return brojac;                  //Ako je redosled iste dimenzije kao i originalni graf vracamo brojac, inace -1
 else return -1;
}

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> graf(n);
  for(int i = 0; i<m;i++){
    int a,b; cin >> a >> b;
    graf[a-1].push_back(b-1);
  }
  cout << broj_dana(graf);
}
