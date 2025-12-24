#include <iostream>
#include <map>
using namespace std;

struct Cvor{
  map<char, Cvor*> grane;
  bool kraj;
};

void dodaj(Cvor* stablo, string& rec){
  for(char c : rec){
    if(stablo->grane.find(c) == stablo->grane.end()) stablo->grane[c] = new Cvor();
    stablo = stablo->grane[c];
  }
  stablo->kraj = true;
}
bool prefiks(Cvor* stablo, string& rec, int broj){
  for(char c: rec){
    if(stablo->grane.find(c) == stablo->grane.end()) return false;
    if(--broj) stablo = stablo->grane[c]; else return true;
  }
  return true;
}
int main(){
int br_reci, br_upita;
cin >> br_reci >> br_upita;
Cvor *stablo = new Cvor();
for(int i = 0; i<br_reci; i++){
  string rec;
  cin >> rec;
  dodaj(stablo,rec);
}
for(int i = 0; i<br_upita; i++){
string rec;
int broj;
cin >> rec >> broj;
cout << prefiks(stablo,rec,broj);
}

return 0;
}
