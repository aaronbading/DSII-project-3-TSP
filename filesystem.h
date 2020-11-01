#ifndef Filesystem_H
#define Filesystem_H

#include <iostream>
#include "brute.h"
#include "genetic.h"
#include <vector>
#include<fstream>
#include<string>
using namespace std;

class FileSystem
{
public:
FileSystem();
void Run();

private:
double s[20][20];
ifstream file;
};
#endif


