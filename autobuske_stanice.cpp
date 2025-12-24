#include <iostream>
#include <limits>
#include <set>
#include <vector>
#define inf numeric_limits<int>::max()
using namespace std;
using put= pair<int, int>; //do stanice, cena

int najjeftiniji(int cvor, vector<vector <put>>& graf){
  int n = graf.size();
  vector<int> uk_cena ( n,inf);
  set<pair<int,int> >pq;  //cena, grana
  pq.insert({uk_cena[cvor] = 0, cvor});
  while(!pq.empty()){
    int stanica = pq.begin()->second;
    pq.erase(pq.begin());
    
    for(put p: graf[stanica]){
    int sused = p.first, cena_do_suseda = p.second;
    int korigovana_cena = cena_do_suseda - uk_cena[stanica];
    if(korigovana_cena < 0) korigovana_cena = 0;
    if(uk_cena[stanica] + korigovana_cena < uk_cena[sused]){
      pq.erase({ uk_cena[sused], sused });
      uk_cena[sused] = uk_cena[stanica] + korigovana_cena;
      pq.insert({uk_cena[sused], sused});
    }
    }
  }
  return uk_cena[n-1];
}

int main(){
  int br_stanica, br_puteva, stanica_od, stanica_do, cena_puta, ukupna_cena = 0;
  cin >> br_stanica >> br_puteva;
  vector< vector< put>> gradska_mreza(br_stanica);
  for(int i = 0; i < br_puteva; i++){
  cin>> stanica_od >> stanica_do >> cena_puta;
  stanica_od--; stanica_do--;
  gradska_mreza[stanica_od].push_back({stanica_do,  cena_puta});
  gradska_mreza[stanica_do].push_back({stanica_od,  cena_puta});
  }
  
  cout << najjeftiniji(0 , gradska_mreza);
  
  return 0;
}
