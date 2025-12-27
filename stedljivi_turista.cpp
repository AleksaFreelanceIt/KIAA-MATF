#include <iostream>
#include <set>
#include <vector>
#include <limits>

using namespace std;
using edge = pair<int,int>;                                                             //{cvor,daljina} u grafu, obrnuto u dajkstri
int dajkstra(int pocetak, int cilj, vector<vector<edge>>& graf){
  int n = graf.size();
  vector<int> daljina(n, numeric_limits<int>::max());                         //Postavljamo daljinu do svakog cvora kao beskonacno

  set<edge> pq;                                                                           //Set "zamisljamo" kao {daljina,cvor} da bi se sortirao po daljini
  pq.insert({daljina[pocetak] = 0, pocetak});                                     //Ubacujemo pocetni cvor u set
  while(!pq.empty()){                                                                      //Dok set nije zavrsen vrtimo
    int trenutni = pq.begin()->second;  pq.erase(pq.begin());              //Izvlacimo prvi iz seta i brisemo ga da ne bi dobili beskonacnu petlju
    for(edge e : graf[trenutni]){                                                      //Prolazimo kroz sve njegove susede
      int sused = e.first, sused_daljina = e.second;                          //Izvlacimo broj suseda i njegovu daljinu od trenutnog cvora
      if(daljina[trenutni] + sused_daljina < daljina[sused]){                //Da li je daljina do trenutnog cvora + daljina od trenutnog do suseda manja od daljine koju taj sused vec ima
        pq.erase({daljina[sused],sused});                                          //Ako jeste brisemo iz seta jer vise ta daljina nije optimalna
        daljina[sused] = daljina[trenutni] + sused_daljina;                  //Update daljinu i ubacimo nazad u set za dalju obradu njegovih suseda
        pq.insert({daljina[sused],sused});
      }
    }
  }
  return daljina[cilj];                                                                     //Kad se zavrsi sve vracamo daljinu od pocetka do zeljenog cilja
}

int main(){
  int n,m; cin >> n >> m;
  vector<vector<edge>> graf(n);
  for(int i = 0; i<m;i++){                                                //Unosenje cvorova u graf
    int od_cvora, do_cvora, tezina;
    cin >> od_cvora >> do_cvora >> tezina;
    graf[od_cvora].push_back({do_cvora,tezina});
    graf[do_cvora].push_back({od_cvora,tezina});
  }
  
  int pocetak, kraj, put_1, put_2;                                    //Unosenje kljucnih cvorova
  cin >> pocetak >> kraj >> put_1  >> put_2;
  
  int suma_1 = dajkstra(pocetak, put_1, graf) + dajkstra(put_1, kraj, graf);
  int suma_2 = dajkstra(pocetak, put_2, graf) + dajkstra(put_2, kraj, graf);
  if(suma_1 < suma_2) cout << suma_1 << endl;
  else cout << suma_2 << endl;

  return 0;
}
