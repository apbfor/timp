//
// Created by apbfor on 26.03.19.
//

/*
 * Поиск подстроки в строке. Алгоритм Рабина-Карпа
*/
#define PRIME_NUMBER 23
#define ALPHABET_ENG 26
#define START_ASKII_ENG 97
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int tonum(char c){//для чисел
    return int(c-START_ASKII_ENG);
}

int my_pow(int d,int m,int q){
    d=d%q;
    int k=(m-1)%(q-1);
    if(int(pow(d,k))%q>=0)
        return int(pow(d, k))%q;
    return int(pow(d, k))%q+q;
}
int rabin_karp_matcher(string T,string P,int d=ALPHABET_ENG,int q=PRIME_NUMBER)//d-мощность алфавита q-произвольное простое число
{
    int n =T.size();
    int m =P.size();
    int h =my_pow(d,m,q);

    int p=0;
    vector<int> t;
    t.push_back(0);
    for(int i=0;i<m;i++){
        p=(d*p+tonum(P[i]))%q;
        t[0]=(d*t[0]+tonum(T[i]))%q;
    }
    for(int s=0;s<n-m+1;++s){
        if(p==t[s])
            if (P==T.substr(s,m)){
                return s;
            }
        if (s<n-m)
            if(((d*(t[s]-tonum(T[s])*h)+tonum(T[s+m]))%q)<0)
                t.push_back(((d*(t[s]-tonum(T[s])*h)+tonum(T[s+m]))%q)+q);
            else t.push_back(((d*(t[s]-tonum(T[s])*h)+tonum(T[s+m]))%q));
    }
    return -1;
}