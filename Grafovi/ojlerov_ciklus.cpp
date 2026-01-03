#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> usmeren_ojler(vector<vector<int>>& graf){
    vector<int> ciklus;                                                   //Ciklus pod kojim se mora obici graf da bi bio ojlerov
    stack<int> redosled;                                                //Redosled pod kojim se obradjuju cvorovi
    redosled.push(0);
    
    while(!redosled.empty()){                                                   
        int trenutni = redosled.top();                                 //Uzimamo sa vrha steka
        if(graf[trenutni].empty()){                                      //Proveravamo da li taj cvor ima grana ako nema stavljamo ga u ciklus
            ciklus.push_back(trenutni);                               //I sklanjamo sa redosleda
            redosled.pop();
        } else {
            redosled.push(graf[trenutni].back());                 //Ako nije prazan uzimamo 'poslednju' granu  i stavljamo u redosled da se obradi
            graf[trenutni].pop_back();                                //Potom je obrisemo kao granu iz originalnog grafa
        }
    }
    reverse(ciklus.begin(), ciklus.end());                           //Reverse ciklus da bi dobili pravu putanju
    return ciklus;
}
vector<int> neusmeren_ojler(vector<vector<int>>& graf){
    int velicina = graf.size();
    vector<vector<bool>> grana(velicina, vector<bool>(velicina));//Matricna reprezentacija grana
    for(int cvor1 = 0; cvor1 < velicina; cvor1++)                            //Popunjavamo matricu
        for(int cvor2 : graf[cvor1])
            grana[cvor1][cvor2] = true;
    vector<int> ciklus;                                                          //CIklus prolaska kroz graf da bi bio ojlerov
    stack<int> redosled;                                                       //Redosled pri obradi cvorova
    redosled.push(0);
    
    while(!redosled.empty()){
        int trenutni = redosled.top();                                                                      //Uzimamo cvor sa vrha
        while(!graf[trenutni].empty() && !grana[trenutni][graf[trenutni].back()])         //Uklanjamo vec posecene grane
            graf[trenutni].pop_back();
        if(graf[trenutni].empty()){                                                                          //Ako posle uklanjanja cvor nema suseda, dodajemo ga u ciklus
            ciklus.push_back(trenutni);                                                                   //I vadimo iz redosleda
            redosled.pop();
        } else {
            grana[trenutni][graf[trenutni].back()] = grana[graf[trenutni].back()][trenutni] = false;  //Ako posle uklanjanja ima susede, ukinemo ga
            redosled.push(graf[trenutni].back());                                                                        //Dodamo u redosled za dalju obradu
            graf[trenutni].pop_back();                                                                                       //Uklonimo granu
        }  
    }
    return ciklus;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graf(n);
    for(int i = 0; i < m; i++){
    int od_cvor, do_cvor; cin >> od_cvor >> do_cvor;
    graf[od_cvor].push_back(do_cvor);
    graf[do_cvor].push_back(od_cvor);
    }
    
    vector<int> ojler_ciklus = usmeren_ojler(graf);
    for( int cvor : ojler_ciklus)
        cout << cvor << " ";
    cout << endl;
    return 0;
}
