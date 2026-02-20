#include <iostream>
#include <vector>

using namespace std;

int num = 0;
vector<int> low;
vector<int> numeracija;

int boja = 0;
vector<int>boje;

vector<int> stek;
vector<bool> u_steku;
//komponente povezanosti          tarjan
void komponente(int cvor, vector<vector<int>>& graf){     //dfs
    low[cvor] = numeracija[cvor] = ++num;                         //dfs numeracija svakog cvora da bi omogucili koriscenje low
    
    stek.push_back(cvor);                                                 //ubacimo ga u stek da bi kasnije koristili grane koje nisu u dfs stablu
    u_steku[cvor] = true;                                                  //oznacimo da je ubacena grana u stek
    
    for(int sused : graf[cvor])
        if(numeracija[sused] == 0){                                     //ukoliko nije obidjen
            komponente(sused, graf);                                                //pokreni  dfs koji ce izracunati za suseda low
            low[cvor] = min(low[cvor], low[sused]);                //uporedi low vrednost
        }else if(u_steku[sused])                                           //ako je cvor idalje u steku
            low[cvor] = min(low[cvor], numeracija[sused]);     //proverimo opet low vrednost
        
    if(low[cvor] == numeracija[cvor]){                                //ovaj uslov nam daje predstavnika komponente
          int temp_cvor = -1;
          while(temp_cvor != cvor){                                      
              temp_cvor = stek.back();                                   //izbacujemo cvorove dok ne dodjemo do predstavnika
              stek.pop_back();                                               //
              u_steku[temp_cvor] = false;                             //izbacujemo ih i iz steka
              //cout << temp_cvor << ' ';                                    //ispisujemo cvorove iz iste komponente
              boje[temp_cvor] = boja;
          }
          boja++;
         // cout << '\n';
    }
}
//Dobijanje  graf od boja
vector<vector<bool>> kolicnicki_graf(vector<vector<int>>& graf){
    vector<vector<bool>> kol(boja, vector<bool>(boja));
    
    for(int cvor = 0; cvor < graf.size(); cvor++)                         //formiranje matrice povezanosti
        for(int sused : graf[cvor])
            if(boje[cvor] != boje[sused])
                kol[boje[cvor]][boje[sused]] = true;
    return kol;
}

int main(){
    int n, m; cin >> n >> m;
    
    vector<vector<int>> graf(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        
        graf[a].push_back(b);
    }
    low = vector<int>(n, 0);
    numeracija = vector<int>(n, 0);
    u_steku = vector<bool>(n, false);
    boje = vector<int>(n); //boje[cvor] = boja cvora
    
    for(int cvor = 0; cvor < n; cvor++)
        if(numeracija[cvor] == 0)
            komponente(cvor, graf);
    vector<vector<bool>> kol =  kolicnicki_graf(graf);
    for(int i = 0; i < boja; i++){
        for(int j = 0; j < boja; j++)
            cout << kol[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
