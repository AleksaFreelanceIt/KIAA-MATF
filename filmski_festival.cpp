#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Cvor{
map<char, Cvor*> grane; 
bool kraj = false;
int brojac = 0;
};

void dodaj( Cvor* stablo, string ime){
  for(char c: ime){
    if(stablo->grane.find(c) == stablo->grane.end()){// ako ne postoji cvor sa tim slovom napravi novi
      stablo->grane[c] = new Cvor();
    }
    stablo->brojac++;
    stablo = stablo->grane[c];
  }
  stablo->kraj = true;
}

string skracenica(Cvor* stablo,string ime){
  string skraceno = "";
  for(char c: ime){
  stablo = stablo->grane[c];
  skraceno += c;
  if(stablo->brojac == 1){
    return skraceno;
  }
  }
  return ime;
}
void obrisi(Cvor* stablo){
for(auto cvor: stablo->grane){
obrisi(cvor.second);
}
delete(stablo);
}
int main(){
  int n;
  Cvor* stablo = new Cvor();
  cin >> n;
  vector<string> imena(n);
  for(int i = 0; i<n; i++){
    cin >> imena[i];
    dodaj(stablo,imena[i]);
  }
  for(int i = 0; i<n; i++){
    string skraceno_ime ="";
    cout << skracenica(stablo, imena[i]) << endl;
  }
return 0;
}
