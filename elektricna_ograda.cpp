#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;
using tacka = pair<int,int>;

tacka vektor(tacka a, tacka b){
  return {b.first - a.first, b.second - a.second};
}
int vektorski_proizvod(tacka a, tacka b){
  return a.first*b.second - a.second*b.first;
}
int orientacija( tacka a, tacka b, tacka c){
  return vektorski_proizvod(vektor(a,b),vektor(a,c));
}

vector<tacka> convex_hull(vector<tacka>& tacke){
  vector<int> hull;                                                                         //Inicijalizacija niza indeksa i tacaka omotaca
  vector<tacka> omotac;
  int t = min_element(tacke.begin(),tacke.end()) - tacke.begin();         //Vraca indeks minimalnog elementa
  
  do{
    hull.push_back(t);                                                                       //Stavi indeks t u niz indeksa
    omotac.push_back(tacke[t]);                                                       //Stavi tacku t u niz tacaka
    int nt = (t+1)%tacke.size();                                                          //Nasumicna tacka nt(indeks)
    for(int i = 0; i < tacke.size(); i++){
      if(i != t && orientacija(tacke[t],tacke[i],tacke[nt])>0) nt = i;           //Ako indeks i nije jednak t i i je dalji od nt , nt = i;
    }
    t = nt;
  }while(t!= hull[0]);                                                                          //Vrti dok ne dodjes do pocetne tacke
  return omotac;
}
int distanca( tacka a, tacka b){
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(){
  int min_razdaljina = numeric_limits<int>::max(), n; cin>>n;
  vector<tacka> tacke(n);
  tacka dovod_struje, najbliza_tacka;
  for(int i = 0; i<n;i++)
    cin >> tacke[i].first >> tacke[i].second;
  cin>> dovod_struje.first >> dovod_struje.second;
  vector<tacka> omotac = convex_hull(tacke);
  for(tacka stub : omotac){
    int temp_razdaljina = distanca(dovod_struje, stub);
    if(temp_razdaljina < min_razdaljina){
    min_razdaljina = temp_razdaljina;
    najbliza_tacka = stub;
    }
  }
  cout << najbliza_tacka.first << " " << najbliza_tacka.second;
  return 0;
}
