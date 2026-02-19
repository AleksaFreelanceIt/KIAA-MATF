#include <iostream>
#include <vector>

using namespace std;

//kanov algoritam
vector<int> topsort(vector<vector<int>>& graf){
    int n = graf.size();
    
    vector<int>zavisnost(n,0);                          //Niz u kome cuvamo koliko grana vodi do i-tog cvora
    for(int cvor = 0; cvor < n; cvor++)             
        for(int sused : graf[cvor]) 
            zavisnost[sused]++;                           
    
    vector<int> red;
    for(int cvor = 0; cvor < n; cvor++)
        if(zavisnost[cvor] == 0)
            red.push_back(cvor);                      //Prvo u redosled ubacujemo cvorove koji su nezavisni
    for(int i = 0; i < red.size(); i++){               //Onda prolazimo kroz taj redolsed i updejtujemo zavisnost suseda
        int cvor = red[i];                          
        for(int sused : graf[cvor]){                 
            zavisnost[sused]--;                         //ovde
            if(zavisnost[sused] == 0)                //ako postane nezavistan onda ga ubacimo u redosled
                red.push_back(sused);
        }
    }
    return red;                                             //topolosko sortiranje nije jedinstveno
}
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> usmeren_graf(n);
    while(m--){
        int a, b; cin >> a >> b;
        usmeren_graf[a].push_back(b);
    }
    vector<int> s = topsort(usmeren_graf);
    
    if(s.size() != n) cout << "Ciklican graf\n";  //ako topoloski redosled nije iste velicine kao i pocetni graf, graf je ciklican
    else for(int cvor : s) cout << cvor << " ";
    cout << '\n';
    return 0;
}
