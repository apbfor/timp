//
// Created by apbfor on 26.03.19.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;


#define tonum(c) (c >= 'A' && c <= 'Z' ? c - 'A' : c - 'a' + 26)

int mod(int a,int p,int m)
{
    if (p == 0)
        return 1;
    int sqr = mod(a,p/2,m) % m;

    if (p & 1)
        return ((a % m) * sqr) % m;
    else
        return sqr;
}

int RabinKarpMatch(char *T,char *P,int d,int q)
{
    int i,j,p,t,n,m,h,found;
    n = strlen(T);
    m = strlen(P);
    h = mod(d,m-1,q);
    p = t = 0;

    for (i=0; i<m; i++)
    {
        p = (d*p + tonum(P[i])) % q;
        t = (d*t + tonum(T[i])) % q;
    }

    for (i=0; i<=n; i++)
    {
        if (p == t)
        {
            found = 1;
            for (j=0; j<m; j++)
                if (P[j] != T[i+j])
                {
                    found = 0;
                    break;
                }
            if (found)
                return i+1;
        }
        else
        {
            t = (d*(t - ((tonum(T[i])*h) % q)) + tonum(T[i+m])) % q;
        }
    }
    return -1;
}

int main(int argc, char* argv[]){

    int d=1, q=1000;
    char T[200];
    char P[100];
    cout<<"Enter string"<<endl;
    cin >> T;
    cout<<"Enter substring"<<endl;
    cin >> P;
    int indexOf= RabinKarpMatch(T,P,d, q);
    if(indexOf)
        cout<<"Substr found in "<<indexOf<<" position";
    else
        cout<<"Substr not found";
    return 0;
}