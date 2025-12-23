#include <iostream>
#include <vector>

using namespace std;
int brojac = 0;
void prebroj(int cvor, vector<bool>& posecen, vector<vector<int>>& graf){
  brojac++;
  posecen[cvor] = true;
  for(int sused : graf[cvor])
    if(!posecen[sused]){
      prebroj(sused,posecen,graf);
    }
}

int main(){
  int br_osoba,  br_upita, osoba1, osoba2;
  cin >> br_osoba >> br_upita;
  vector<vector<int>> mreza(br_osoba);
  char upit;
  vector<bool> posecen(br_osoba);
  while(br_upita){
  cin>>upit;
  if(upit == 'Q'){ //Prikazi drustvenu mrezu u kojoj se nalazi osoba1
    cin >> osoba1;
    osoba1--;
    prebroj(osoba1,posecen, mreza);
    cout << brojac << endl;
    brojac = 0;
    for(int i = 0; i<br_osoba;i++){
      posecen[i] = false;
    }
  } else if (upit == 'M'){ //Dodaj granu izmedju osobe1 i osobe2
    cin >> osoba1 >> osoba2;
    osoba1--;
    osoba2--;
    mreza[osoba1].push_back(osoba2);
    mreza[osoba2].push_back(osoba1);
  }
  br_upita--;
  }
  return 0;
}
