#include <iostream>
#include <vector>
#include <set>
#include <limits>
using namespace std;
using grana = pair<int,int>; //grana oznacava do kog cvora se ide i kolika je tezina grane


vector<int> dajkstra(int pocetni_cvor, vector<vector<grana>>& tezinski_graf){
    vector<int> tezina(tezinski_graf.size(), numeric_limits<int>::max());              //Prateci dajkstrin algoritam postavljamo da je tezina do svakog cvora inf
    set<grana> putevi;                                                                                    //Namestamo skup da bi se sortiralo po tezinama grana ovde predstavlja <tezina,cvor>
    tezina[pocetni_cvor] = 0;                                                                           //Tezina do pocetnog cvora je 0
    putevi.insert({tezina[pocetni_cvor], pocetni_cvor});                                      //Stavljamo pocetni cvor u skup i pokrecemo petlju
    
    while(!putevi.empty()){
        int trenutni = putevi.begin()->second;                                                     //Uzimamo prvi koji je na redu cvor i potom ga brisemo iz skupa
        putevi.erase(putevi.begin());
        
        for(grana sused : tezinski_graf[trenutni]){                                              //Obilazimo sve susede
            int sused_cvor = sused.first, sused_tezina = sused.second;                //Izvlacimo podatke o susedu, grana u grafu je stavljena kao <cvor,tezina> suprotno od skupa
            if(tezina[trenutni] + sused_tezina < tezina[sused_cvor]){                    //Gledamo da li je dolazeci od trenutnog cvora kraci put do suseda nego neki drugi put
                putevi.erase({ tezina[sused_cvor], sused_cvor });                           //Ako jeste brisemo ga iz skupa, ova funkcija radi iako taj cvor nije u skupu
                tezina[sused_cvor] = tezina[trenutni] + sused_tezina;                    //Namestamo mu novu tezinu
                putevi.insert({ tezina[sused_cvor], sused_cvor });                           //Vracamo ga nazad u skup da bi ta izmena uticala na cvorove sa kojima je on povezan
            }
        }
    }
    return tezina;                                                                                          //Vracamo niz tezina koji nam govori od pocetnog cvora do svakog koja je tezina
}

int main(){
    int n,m; cin >> n >> m;
    vector<vector<grana>> tezinski_graf(n);
    for(int i = 0; i<m; i++){
        int od_cvor, do_cvor, tezina; cin >> od_cvor >> do_cvor >> tezina;
        tezinski_graf[od_cvor].push_back({do_cvor, tezina});
        tezinski_graf[do_cvor].push_back({od_cvor,tezina});
    }
    vector<int> tezine = dajkstra(0,tezinski_graf);
    for(int i : tezine) cout << i << " ";
    cout << endl;
    
    return 0;
}
