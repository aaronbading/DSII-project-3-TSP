#include <iostream>
#include <string>
#include "brute.h"

Brute::Brute(int n)
{
 rowlimit= n-1;
 collimit=n-1;
}
double Brute::force(double s[][20])
{

Permutation p(rowlimit);
//p.initS(length);
     int total = fact(rowlimit); // really passiong in number of cities
     int* ptr =p.getS();
     double newcost,mincost=0;

     for(int i = 0; i < total; i++)
     {			
	//compute cost the current permuatation...
	
	//computing city 0 (start point) to position 1 manually here
	newcost=s[0][ptr[0]];	
	for(int j=1; j<=rowlimit ;j++)
	{
		int prev = ptr[j-1],next=ptr[j];
		newcost=newcost+s[prev][next];
		 if(j==rowlimit)
                        {prev=rowlimit;
                        next=0;}		
	}
	if(mincost>newcost)
	{mincost=newcost;}
		
	//if its the first iteration initialize mincost to the first 
	if(i==0)
	{mincost=newcost;}

      // p.printS();
       p.perm1();
       ptr=p.getS();
     }

return mincost;
}
int Brute::fact(int n)
{
     int tot = 1;
     for(int i = 2; i <=n; i++)
        tot*=i;
     return tot;
}
