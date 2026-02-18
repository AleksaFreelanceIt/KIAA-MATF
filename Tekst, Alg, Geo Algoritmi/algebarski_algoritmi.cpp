#include <iostream>

using namespace std;
int mod(int a, int m){
    if(a > 0)
        return a % m;
    else
        return (m + a % m) % m;
}
int add(int a, int b, int m){
    return mod(a+b, m);
}
int mul(int a, int b, int m){
    return mod(a*b, m);
}
int sub(int a, int b, int m){
    return mod(m+ a-b, m);
}
int pow(int a, int b, int m){
    int rez = 1;
    while(b != 0){
        if(b&1)
            rez = mul(rez, a, m);
        a = mul(a,a,m);
        b >>= 1;
    }
    return rez;
}
int nzd(int a, int b){
    while(b>0){
        //(a, b) = b, a%b
        int temp = mod(a, b);
        a = b;
        b = temp;
    }
    return a;
}
pair<int, int> skrati(int a, int b){
    int d = nzd(a, b);
    return {a/b, b/d};
}
int nzd2(int a, int b, int& x, int& y){
     int xp = 1, yp = 0;    //a = xp*a + yp*b;
     int xs = 0, ys = 1;    //b = xs*a + ys*b;
     
     while(b>0){
        int q = a/b;
        
        tie(a, b) = make_pair(b, a - q*b);
        tie(xp, xs) = make_pair(xs, xp - q*xs);
        tie(yp, ys) = make_pair(ys, yp - q*ys);
     }
     x = xp;
     y = yp;
     return a;
}
bool diofant(int a, int b, int c, int& x, int& y){
    int d = nzd(abs(a), abs(b), x, y);
    if(c<0)
        (a, b, c) = make_tuple(-a, -b, -c);
    if(c&d != 0)
        return false;
    if(a < 0)
        x = -x;
    if(b < 0)
        y = -y;
    x *= c/d;
    y *= c/d;
    return true;
}
int kong(int a, int c, int m){
    int x, y;
    if(!diofant(a, m, c, x, y))
        return -1;
    return mod(x, m);
}
int inv(int a, int m){
    //return kong(a, 1, m);
    int x, y;
    int d = nzd(a, m, x, y);
    if(d != 1)
        return -1;
    else
        return mod(x, m);
}
int crt(vector<int>& as, vector<int>& ns){
    int N = 1;
    for(int n : ns)
        N *= n;
    vector<int> Ns(as.size());
    for(int i = 0; i < as.size(); i++)
        Ns[i] = N/ns[i];
    vector<int> ms(as.size());
    for(int i = 0; i < as.size(); i++)
        ms[i] = inv(Ns[i], ns[i]);
    int x = 0;
    for(int i = 0; i < as.size(); i++)
        x = add(x,mul(as[i],mul(Ns[i],ms[i],N),N),N);
    return x;
}

int main(){
    //rng number generator
    /*int a = 10, c = 6, m = 19;
    int seed; cin >> seed;
    int rez = seed;
    
    while(true){
        cout << rez;
        // x = x*a+c
        rez = add(mul(rez, a, m), c, m);
        cin.ignore();
    }*/
    //casovnik koji ne radi
    /*int a, int n; cin >> a >> n;
    cout << kong(a, n, 12) << '\n''*/
    return 0;
}
