#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int velicina(int n){                            //Funkcija sluzi za vracanje broja koji je stepen 2
    int visina = ceil(log2(n));
    return pow(2,visina);
}

vector<int> napravi_segmentno(vector<int>& niz, int velicina){   //Pravimo segmentno tako sto uzmemo modifikovanu velicinu niza i napravimo novi niz
    vector<int> segmentno_stablo(velicina*2,0);                          //koji je duplo veci, potom prekopiramo originalni niz u drugu polovinu novog, potom u petlji
    copy(niz.begin(),niz.end(),segmentno_stablo.begin()+n);           //racunamo ostale clanove prateci logiku segmentnog stabla, ova implementacija je za sumu
    
    for(int i = n-1; i>0; i--)
        segmentno_stablo[i] = segmentno_stablo[2*i] + segmentno_stablo[2*i+1];
        
    return segmentno_stablo;
}

void izmeni_element(int index, int x, vector<int>& segmentno_stablo, int velicina){      //Korisnik misli da menja element u originalnom nizu a ne u segmentnom
    segmentno_stablo[index+=velicina] = x;                                                                //Zato moramo modifikovati indeks da upadne u tu drugu polovinu stabla gde se nalazi niz
    for(int i = index/2; i >0 ; i/=2)                                                                               //Potom updejtujemo sve elemente na koje je ta pozicija uticala
        segmentno_stablo[i] = segmentno_stablo[2*i] + segmentno_stablo[2*i+1];
}

int suma_na_intervalu(int l_granica, int d_granica, vector<int>& segmentno_stablo, int velicina){   
    int suma = 0;
    
    for(l_granica += velicina, r_granica += velicina; l_granica<= r_granica; l/=2, r/=2){ //Zbog nacina kako indeksujemo elemente u stablu ako je leva granica
        if(l_granica % 2 == 1) suma+= segmentno_stablo[l_granica++];                           //na parnom indeksu, u interval spadaju oba elementa na tom nivou pa
        if(r_granica % 2 == 0) suma+= segmentno_stablo[r_granica--];                           //se moze uzeti element iznad koji ih oba obuhvata, ista logika za desnu
    }
    
    return suma;
}


int main(){

return 0;
}
