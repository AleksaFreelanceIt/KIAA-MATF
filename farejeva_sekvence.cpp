#include <iostream>

using namespace std;
  
int nzd(int a, int b){
  while(b>0){
    int temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}
int phi(int n){
  int brojac = 0;
  for(int i = 1; i<=n;i++){
    if(nzd(i,n) == 1) brojac++;
  }
  return brojac;
}

int farej(int n){
  int suma = 1;
  for(int d = 1; d <= n; d++){
    suma += phi(d);
  }
  return suma;
}
int main(){
  int N; cin >> N;
  cout << farej(N) << endl;
  return 0;
} 
