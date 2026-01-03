#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int cvor, vector<bool>& posecen, vector<vector<int>>& graf){
    posecen[cvor] = true;                                     //Oznacimo da je trenutni cvor posecen
    cout << cvor << " ";                                       //Vrsimo obradu nad trenutnim cvorom
    for( int sused : graf[cvor]){                             //Za svakog njegovog suseda
        if(!posecen[sused])                                    //Ako nije posecen
            dfs(sused,posecen,graf);                       //Obidji i njega
    }
}

void bfs(int pocetni_cvor, vector<bool>& posecen, vector<vector<int>>& graf){
    posecen[pocetni_cvor] = true;                                       //Postavimo da je pocetni cvor posecen da se ne bi vratili u njega
    queue<int> redosled;                                                    //Koristimo queue da bi vrsili pretragu u sirinu, u njemu cuvamo
    redosled.push(pocetni_cvor);                                         //redosled kojim treba da obidjemo graf
    
    while(!redosled.empty()){
        int trenutni = redosled.front(); redosled.pop();             //Izbacimo prvi iz queue i vrsimo obradu cvora
        cout << trenutni << " ";
        for(int sused : graf[trenutni]){                                     //Gledamo njegove susede
            if(!posecen[sused]){                                              //Koji nisu poseceni, dodajemo ih u queue i krecemo iznova
                posecen[sused] = true;
                redosled.push(sused);
            }
        }
    }
}

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> neusmeren_graf(n);
  //vector<vector<int>> usmeren_graf(n);
    vector<bool> posecen(n,false);
    
    for(int i = 0; i < m; i++){
      int od_cvor, do_cvor;
      cin >> od_cvor >> do_cvor;
      neusmeren_graf[od_cvor].push_back(do_cvor);
      neusmeren_graf[do_cvor].push_back(od_cvor);
    }
  /*for(int i = 0; i < m; i++){                                             Pravljenje grafa kao usmerenom grafu
      int od_cvor, do_cvor;
      cin >> od_cvor >> do_cvor;
      usmeren_graf[od_cvor].push_back(do_cvor);
    }*/
    
    dfs(0,posecen,neusmeren_graf);
  //bfs(0,posecen,neusmeren_graf);
    return 0;
}
