//
// Created by apbfor on 26.03.19.
//

#include <iostream>
#include <string>
#include "cstdio"
#include <ctime>
#include <math.h>
#include <vector>
using namespace std;

#ifndef TEST_EMPTY_DDZ_H
#define TEST_EMPTY_DDZ_H

#endif //TEST_EMPTY_DDZ_H

/*
 * Поиск подстроки в строке.
 * Простейший алгоритм. Алгоритм Рабина-Карпа.
 * Сравнение времени выполнения реализаций указанных алгоритмов.
 */
#define PRIME_NUMBER 11
#define ALPHABET_ENG 26
#define START_ASKII_ENG 97

using namespace std;

int tonum(char c){
    return int(c-START_ASKII_ENG);
}

int my_pow(int d,int m,int q){
    d=d%q;
    int k=(m-1)%(q-1);
    if(int(pow(d,k))%q>=0)
        return int(pow(d, k))%q;
    return int(pow(d, k))%q+q;
}
vector<int> rabin_karp_matcher(string T,string P,int d=ALPHABET_ENG,int q=PRIME_NUMBER)//d-мощность алфавита q-произвольное простое число
{
    vector<int> vec;
    if ((T.size()==0)||(P.size()==0))
        return vec;
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
                vec.push_back(s);
            }
        if (s<n-m)
            if(((d*(t[s]-tonum(T[s])*h)+tonum(T[s+m]))%q)<0)
                t.push_back(((d*(t[s]-tonum(T[s])*h)+tonum(T[s+m]))%q)+q);
            else t.push_back(((d*(t[s]-tonum(T[s])*h)+tonum(T[s+m]))%q));
    }
    return vec;
}
