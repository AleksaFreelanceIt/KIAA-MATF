#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using koordinate = pair<int,int>;

const vector<koordinate> potezi = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};  //U kojim smerovima moze skakac da ide
int bfs(koordinate pocetak, koordinate cilj){
    vector<bool> posecen(64,false);                                                                   //Inic blok za nizove distance i posecenosti i queue zbog bfs
    vector<int> distanca(64,0);
    queue <koordinate> q;
    
    int indeks = pocetak.first * 8 + pocetak.second;                                             //pozicija pocetnih koordinata u 1D nizu 8x8 table
    if(pocetak == cilj) return distanca[indeks];                                                     //proveravamo da li je pocetak isti kao i cilj
    q.push(pocetak);                                                                                          //stavljamo pocetak u queue za bfs i stavljamo da je posecen
    posecen[indeks] = true;
    
    while(!q.empty()){                                                                                          //dok nam ne nestane cvorova vrti
        koordinate trenutni = q.front(); q.pop();                                                       //uzimamo prvi u queue-u i izbacujemo ga 
        indeks = trenutni.first*8+trenutni.second;                                                 //njegova pozicija u nizu table
        for(koordinate potez : potezi){                                                                   //za svaki validan potez proveravamo da li je to polje poseceno ako nije ubacujemo ga u queue
            koordinate potencijalni_potez = {trenutni.first + potez.first,trenutni.second+potez.second};
            if((potencijalni_potez.first >= 0 && potencijalni_potez.first < 8)&& (potencijalni_potez.second>=0 && potencijalni_potez.second < 8)){
                int pot_indeks = potencijalni_potez.first * 8 + potencijalni_potez.second;
                if(!posecen[pot_indeks]){
                    if(potencijalni_potez == cilj) return distanca[indeks]+1;                    //ako smo stigli do cilja to je to
                    q.push(potencijalni_potez);                                                           //inace ubacujemo u queue validan cvor
                    posecen[pot_indeks] = true;                                                        //oznacimo da je posecen u nizu table
                    distanca[pot_indeks] = distanca[indeks] + 1; //                               //podesimo distancu semi-rekurzivno
                }
            }
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i<n;i++){
        koordinate pocetak, cilj; cin >> pocetak.first >> pocetak.second >> cilj.first >> cilj.second;
        pocetak.first--;pocetak.second--;cilj.first--;cilj.second--;
        cout << bfs(pocetak,cilj) << endl;
    }
    return 0;
}
