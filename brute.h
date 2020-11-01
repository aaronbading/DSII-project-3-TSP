#ifndef Brute_H
#define Brute_H

#include <iostream>
#include <string>
#include <vector>
#include "permutation.h"
using namespace std;

class Brute
{
public:
Brute(int n);
double force(double s[][20]); //returns brute force solution
int fact(int n);

private:
int rowlimit;
int collimit;
};
#endif

