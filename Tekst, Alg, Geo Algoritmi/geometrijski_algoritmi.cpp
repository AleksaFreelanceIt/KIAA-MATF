#include <iostream>
#include <vector>

using namespace std;
using tacka = pair<int, int>;

tacka vekt(tacka a, tacka b){
    return {b.first - a.first, b.second - a.second};
}
int skalarni_proizvod(tacka a, tacka b){
    // x1*x2 + y1*y2
    return (a.first * b.first)+(a.second * b.second);
}
int vektorski_proizvod(tacka a, tacka b){
    // x1 * y2 - y1 * x2
    return (a.first * b.second)-(a.second * b.first);
}

int orijentacija(tacka a, tacka b, tacka c){
    return vektorski_proizvod(vekt(a, b), vekt(a, c));
}

bool kolinearne(tacka a, tacka b, tacka c){
    return orijentacija(a, b, c) == 0;
}

bool tacka_u_uglu(tacka p, tacka a, tacka b, tacka c){
    if(orijentacija(a, b, c) < 0) return tacka_u_uglu(p, a, c ,b);
    return orijentacija(a, b, p) >= 0 && orijentacija(a, p, c) >= 0;
}

bool tacka_u_trouglu(tacka p, tacka a, tacka b, tacka c){
    return tacka_u_uglu(p, a, b, c) && tacka_u_uglu(p, b, c, a); 
}
bool provera_konveksnosti(vector<tacka>& teme){
    int n = teme.size();
    bool poz = false, neg = false;
    for(int i = 0; i < n; i++){
        int ori = orijentacija(teme[i], teme[(i+1)%n], teme[(i+2)%n]);
        if(ori < 0) neg = true;
        if(ori >= 0) poz = true;
    }
    return !(poz && neg);
}

void prost_mnogougao(vector<tacka>& tacke){
    swap(tacke[0], *min_element(tacke.begin(), tacke.end()));
    sort(tacke.begin()+1, tacke.end(),
        [tacke](tacka a, tacka b){
            return orijentacija(tacke[0], a, b) > 0;
        }); 
}
//pakovanje poklona, ako je orijentacija veca od 0, i je manje od novo t
vector<int> jarvis(vector<tacka>& tacke){
    vector<int> hull;
    int t = min_element(p.begin(), p.end()) - p.begin();
    do{
        hull.push_back(t);
        int novot = (t+1) % tacke.size();
        for(int i = 0; i < tacke.size(); i++)
            if(i != t && orientacija(tacke[t], tacke[i], tacke[novot]) > 0)
                novot = i;
        t = nt;
    }while(t != hull[0]);
    return hull;
}

vector<int> graham(vector<int>& tacke){
    swap(tacke[0], *min_element(tacke.begin(), tacke.end()));
    sort(tacke.begin()+1, tacke.end(),
        [&tacke](tacka a, tacka b){
            return orijentacija(tacke[0], a, b) > 0;
        }); 
    vector<int> hull(1, 0);
    for(int i = 1; i < n; i++){
        while(hull.size()>1 && orient(tacke[hull[hull.size()-2]], 
                                                  tacke[hull[hull.size()-1]], 
                                                  tacke[i]) < 0)
            hull.pop_back();
        hull.push_back(i);
    }// invarijanta je da je omotac konveksan
    return hull;
}

bool u_konveksnom(vector<tacka>& tacke, tacka p){
    auto it = lower_bound(tacke.begin() + 1, tacke.end(),
                                      [&tacke](tacka a, tacka b){
                                          return orijentacija(tacke[0], a, b);
                                      });
    if(it != tacke.end())
        return false;
    int i = it - tacke.begin();
    return tacka_u_trouglu(p, tacke[0], tacke[i-1], tacke[i]);
}
float povrsina(tacka a, tacka b, tacka c){
    return (float) orijentacija(a,b,c)/2;
}
float povrsina(vector<tacka>& tacke){
    float p = 0;
    for(int i = 2; i < n; i++)
        p += povrsina(tacke[0], tacke[i-1], tacke[i]);
    return p;
}

struct prava{
    int a, b, c;
    tacka  v_pravca(){
        return {a, b};
    }
};
double norma(tacka v){
    return sqrt(v.first * v.first + v.second * v.second);
}
double duzina(tacka t, prava p){
    return (p.a * t.first + p.b * t.second - p.c)/norma(p.v_pravca());
}
int strana_prave(tacka t, prava p){
    return (p.a * t.first + p.b * t.second - p.c);
}


int main(){
    
    
    return 0;
}

