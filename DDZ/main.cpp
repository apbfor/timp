//
// Created by apbfor on 26.03.19.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "RKMatcher.h"
#include <random>
#include "cstdio"
#include <list>
#include <string>
#include <time.h>

using namespace std;


static const char aplphabet[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
=======
int tonum(char c){
    int x = c - '0';
    return x;
}
//#define tonum(c) (c >= 'A' && c <= 'Z' ? c - 'A' : c - 'a' + 26)


void show_vector( vector<int>&a)
{
    for (vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it)
        cout<<*it << " ";
    cout << endl;
}

void benchmark(int size_str, int size_substr){
    int n,m,s;
    string T;
    string P;
    n = size_str;
    m = size_substr;
    s = rand() % (n - m);
    for (int i = 0; i < s; i++)
        T.push_back(rand() % ALPHABET_ENG + START_ASKII_ENG);

    for (int i = s; i < s + m; i++) {

        char c = rand() % ALPHABET_ENG + START_ASKII_ENG;
        T.push_back(c);
        P.push_back(c);
    }
    for (int i = s + m; i < n; i++)
        T.push_back(rand() % ALPHABET_ENG + START_ASKII_ENG);

    clock_t  start_time_rabin =  clock();
    vector<int> rabin_karp=rabin_karp_matcher(T,P);
    clock_t  end_time_rabin = clock();
    double  search_time_rabin = (double) (end_time_rabin - start_time_rabin)/CLOCKS_PER_SEC;
    cout << search_time_rabin << endl;

    T.clear();
    P.clear();
}


int main(int argc, char* argv[]){
    //srand(time((NULL)));

    benchmark(2000000,50);
    benchmark(3000000,50);
    benchmark(4000000,50);
    benchmark(5000000,50);




    int d=1, q=1000;
    char T[200000000];
    char P[100000000];
   for (int i=0;i<200000000;i++)
       T[i]='a';
    for (int i=0;i<100000000;i++)
        P[i]='a';
    int indexOf= RabinKarpMatch(T,P,d, q);
    if(indexOf)
        cout<<"Substr found in "<<indexOf<<" position";
    else
        cout<<"Substr not found";

    return 0;
}
