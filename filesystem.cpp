#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "filesystem.h"

FileSystem::FileSystem()
{
file.open("distances.txt");
if(file.fail())
{cout <<"Fail";
exit(1);}
//extraction
int max=20;
double entry;
for(int i=0; i<max ; i++)
{
	for(int j=0; j<max; j++)
	{
	if(i==j)
	{s[i][j]=0;}
	else
	{
	file>>entry;
	s[i][j]=entry;
	}
	}
}
file.close();
}

void FileSystem::Run()
{

 /* clock_t clock(void) returns the number of clock ticks
       elapsed since the program was launched.To get the number
       of seconds used by the CPU, you will need to divide by
       CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical
       32 bit system.  */

	
    clock_t start, end;

//start getting the input 
int cities, toursgen, genrun;
double percentmut;


 cout << " Input the number of cities to run ( 2-13 )" << endl << endl;
 cin >> cities;
 cout << "Input how many individual tours are given in a generation " << endl <<endl;
cin >> toursgen;
cout << "Input how many generations to run " << endl << endl;
cin >> genrun;
cout << "Input what percentage of generation should be comprised of mutations" << endl << endl;
cin >> percentmut;
cout << endl << endl;
//,number of cities to run .. tours per generation... how many generations to run ... and percentage of generation comprised of mutations (0<=percent<=1)
cout << " Amount of cities we are evaluating :  " << cities << endl << endl;
Brute object2(cities);

 start = clock();
double forcesol=object2.force(s);
cout << "The BRUTE FORCE Solution:  " << forcesol << endl;

//end timer and display..
 end = clock();
 double time_taken2 = double(end - start) / double(CLOCKS_PER_SEC);
 cout << "Time taken by BRUTE FORCE program is : " << fixed << time_taken2 << setprecision(5);
 cout << " sec " << endl << endl;

//,number of cities to run .. tours per generation... how many generations to run ... and percentage of generation comprised of mutations (0<=percent<=1)
Genetic object1(cities, toursgen,genrun,percentmut);
//start clock
start = clock();
double gasol=object1.geneticalg(s);
cout << "GA solution :  " << gasol<<  endl;
end=clock();
double time_taken1 = double(end - start) / double(CLOCKS_PER_SEC);
cout << "Time taken by GA program is : " << fixed << time_taken1 << setprecision(5);
cout << " sec " << endl << endl;


cout << "Percent optimal for " << cities << "  cities is " << fixed << (gasol/forcesol)*100 <<setprecision(2) <<" % " <<  endl;
}
