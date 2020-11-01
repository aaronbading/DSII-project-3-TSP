#ifndef Permutation_H
#define Permutation_H

#include <iostream>
#include <vector>
using namespace std;

class Permutation
{
public:
Permutation();
Permutation(int length);
    void initS(int length);
    void printS();
    double computeCost();
    void perm1();
    void swap(int i, int j); 
    int* getS();
   int* mkcp(int length);
private:
static const int MAX = 20;  // twenty cities max
    int nfact = 1;
    int n;
    int count = 1;
    int s[MAX];
};
#endif

