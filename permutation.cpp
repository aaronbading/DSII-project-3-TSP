#include <iostream>
#include <string>
#include "permutation.h"



Permutation::Permutation()
{
}
Permutation::Permutation(int length)
{
n = length;
initS(length);
}

void Permutation::initS(int length)
{
int i;
for(i = 0; i < length; i++)
s[i] = i+1;
s[i] = 0;
n = length;
}

void Permutation::perm1()
{
 int m, k, p , q;

//for(i = 1; i <= howmany; i++)
	
		 m = n - 1;
		 while(s[m]>s[m+1])
          	 {
			 m = m - 1;
		 }
          	 k = n-1;
		 while(s[m] > s[k])
		 k = k - 1;
	       	 swap(m,k);
		 p = m + 1;
		 q = n-1;
		while( p < q)
		{
		swap(p,q);
		p++;
		q--;
	      	}
	      
}

void Permutation::printS()
 {
 for(int i = 0; i < n; i++)
 cout << s[i] << " ";
 cout << endl;
 }

int* Permutation:: mkcp(int length)
{
int* scopy=new int[20];
for(int i=0; i<length ; i++)
{
	scopy[i]=s[i];
}
return scopy;
}


double Permutation::computeCost()
{
 double sum;
 for(int i = 0; i < n; i++)
 {
  sum=sum+s[i];
}
return sum;
}

void Permutation::swap(int i, int j)
{
         int c = s[i];
         s[i] = s[j];
         s[j] = c;
}

int* Permutation::getS()
{
     return s;
}

