#ifndef Genetic_H
#define Genetic_H

#include <iostream>
#include <string>
#include <vector>
#include "permutation.h"
using namespace std;

class Genetic
{
public:
Genetic(int cities, int toursgen,int genrun,double percentmut);
double geneticalg(double s[][20]);
void mutateadd(double s[][20], int* elite1 , int* elite2 , int amount);
void scanforelite(double s[][20]); //scans the vector for the two best paths and sets firstindex and second index to the location of these tours1gt
int* swapcopy(int i, int j, int* elite);
private:

int firstindex , secondindex;
Permutation p;
vector <int*> myvector; //vecotr that holds tours of each generation
int tourspergen; // this will tell how big the container will be 
int gentorun; // this dictates how many times the loop will generate another generation and evaluate it
int rowlimit; //this is the amout of cities -1 to generate the needed permutations
int numbermut; // this is the actual number percentmut*100*toursgen
int numberperm; // this is the number of permutations which will be toursgen-numbermut-2
int numberelite; // this is 2
double solution;
};
#endif

