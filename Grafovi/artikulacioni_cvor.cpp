#include <iostream>
#include <vector>

using namespace std;

int dfs_num(vector<vector<int>>& graf, vector<int>& numeracija, int cvor, int& num, int roditelj){
    int low = numeracija[cvor] = ++num;
    int broj_podstabla = 0;
    bool artikulaciona_tacka = false;
    posecen[cvor] = true;
    
    for(int sused : graf[cvor])
        if(numeracija[sused] == 0){
            int low_suseda = dfs_num(graf, posecen, sused);
            if(roditelj != -1 && low_suseda >= num[u]) artikulaciona_tacka = true;
            low = min(low_suseda, low);
            broj_podstabla++;
        }else if(roditelj != sused){
            low = min(low, numeracija[sused]);
        }
    
    if(artikulaciona_tacka || (p == -1 && broj_podstabla > 1) cout << cvor << ' ';
    return low;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graf(n);
    while(m--){
        int a, b; cin >> a >> b;
        
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
}
