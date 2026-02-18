#include <iostream>
#include <string>
#include <vector>

using namespace std;

int add(int a, int b, int M){
    return ((long long)a + b) % M;
}
int sub(int a, int b, int M){
    return ((long long)M + a - b) % M;
}
int mul(int a, int b, int M){
    return ((long long)a * b) % M;
}
int num(char c){
    return c - 'a' + 1;
}
int hesh(string s){
    int p = 31, M = 1000000009;
    
    int sh = 0;
    for(char c : s){
       //sh = p * sh + num(c);
        sh = add(mul(p, sh, M), num(c), M);
    }
    return sh;
}
void search(string s, string t){  //nalazi substring u reci
    int p = 31, M = 1000000009;
    int n = s.size();
    int m = t.size();
    
    int s_hesh = hesh(s);
    int t_hesh = hesh(t.substr(0,n));
    
    int pn = 1;
    for(int i = 0; i < n-1; i++)
        pn = mul(pn, p, M);
    if(s_hesh == t_hesh)
        cout << 0 << ' ';
    for(int i = n; i < m; i++){
        t_hesh = sub(t_hesh, mul(pn, num(t[i-n]),M), M);      //th -= p^n-1 * t[i-n];
        t_hesh = mul(t_hesh, p, M);                                    //th *= p;
        t_hesh = add(t_hesh, num(t[i]), M);                        //th += t[i];
        if(s_hesh == t_hesh)
            cout << i-n+1 << ' ';
    }
    cout << '\n';
}
vector<int> z_niz(string s){ //nalazi prefix u reci
    int n = s.size();
    vector<int> z(n);
    
    int l = 0, d = 0;
    for(int i = 1; i < n; i++){
        if(i <=d) 
            z[i] = min(z[i-l], d-i+1);
        while(i + z[i] < n && s[i+z[i]] == s[z[i]])
            z[i]++;
        if(i + z[i] - 1 > d){
            l = i;
            d = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> manacher(string s){// nalazi najduzi palindrom u reci
    int n = s.size();
    vector<int> p(n, 1);
    int l = 0, d = 0;
    for(int i = 0; i < n; i++){
        if(i <= d)
            p[i] = min(p[l+d-i], d-i+1);
        while(i+p[i] < n && i-p[i] >= 0 && s[i-p[i]] == s[i+p[i]])
            p[i]++;
        if(i+p[i]-1 > d){
            l = i - p[i] + 1;
            d = i + p[i] - 1;
        }
    }
    return p;
}
vector<int> kmp(string s){  //nalazi prefix u reci
    int n = s.size();
    vector<int> p(n);
    
    for(int i = 1; i < n; i++){
        int j = p[i - 1];                         //j je broj prefiksa prethodnog u nizu
        while(j > 0 && s[i] != s[j])        // dok je j vece od nule i s[i] i s[j] se razlikuju
            j = p[j - 1];                         //j skace unazad ili dok nije 1 ili dok ne budu isti
        if(s[i] == s[j])                         //ako su isti j se uvecava
            j++;
        p[i] = j;                                   //na kraju se i-tom elementu dodeli velicina prefixa j
    }
    return p;
}

int main(){
    /*Hesiranje
    string s, t; cin >> s >> t;
    search(s, t);*/
    
    /* Z algoritam
    string s; cin >> s;
    vector<int> z = z_niz(s);*/
    
   /*Primer upotrebe z alg
   string s, t; cin >> s >> t;
    string p = s + "#" + t;
    vector<int> z = z_niz(p);
    for(int i = 0; i < p.size(); i++){
        if(z[i] == s.size())
            cout << i - s.size() - 1 << ' ';
    }
    cout << '\n';*/
    
    /*Manacher alg
    string s; cin >> s;
    string t = "";
    for(int i = 0; i < s.size(); i++){
        t += s[i];
        t += "#";
    }
    t.pop_back();
    cout << t << '\n';
    vector<int> p = manacher(t);
    for(int x : p)
        cout << x << " ";
    cout << "\n";*/
    
    /*KMP algoritam*/
    string s, t; cin >> s >> t;
    string p = s + "#" + t;
    vector<int> ps = kmp(p);
    for(int i = s.size(); i < ps.size(); i++)
        if(ps[i] == s.size())
            cout << i - 2*s.size() << " ";
    cout << '\n';
    return 0; 
}
