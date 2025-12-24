#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int velicina(int n){
  int visina = ceil(log2(n));
  return pow(2,visina);
}

vector<float> napravi_stablo(vector<float>& stablo, int velicina){
  vector<float> seg_stablo(2*velicina,0);
  copy(stablo.begin(),stablo.end(),seg_stablo.begin()+velicina);
  for(int i = velicina-1;i>0;i--){
  seg_stablo[i] = seg_stablo[2*i] + seg_stablo[2*i+1];
  }
  return seg_stablo;
}
void izmeni_dan(vector<float>& stablo, int velicina,int temperatura, int i){
  stablo[i+=velicina ] = temperatura;
  for(i/=2; i>0; i/=2){
  stablo[i] = stablo[2*i] + stablo[2*i+1];
  }
}
float prosek(int l, int r, vector<float>& stablo, int velicina){
  float suma = 0.0;
  float brojac = (r-l+  1);
  for(l += velicina, r += velicina; l<=r;l/=2, r/=2){
  if(l % 2 == 1)  {suma += stablo[l++];}
  if(r % 2 == 0) {suma += stablo[r--];}
  }
  return suma/brojac;
}

int main(){
  int broj_dana, broj_upita;
  cin >> broj_dana;
  vector<float> dani(broj_dana);
  for(int i = 0; i<broj_dana;i++){
  cin>> dani[i];
  }
  int nova_velicina = velicina(broj_dana);
  vector<float> temperature = napravi_stablo(dani,nova_velicina);
  cin >> broj_upita;

  for(int i = 0; i<broj_upita; i++){
  char c;
  cin >> c;
  if(c == 'u'){
    int dan,temperatura;
    cin >> dan >> temperatura;
    izmeni_dan(temperature, nova_velicina, temperatura, dan-1);
  } else if(c == 'p'){
    int dan1, dan2;
    cin >> dan1 >> dan2;
    cout << prosek(dan1-1,dan2-1,temperature,nova_velicina)<<endl;
  }
  }
  
return 0;
}
