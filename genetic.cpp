#include <iostream>
#include <string>
#include "genetic.h"


Genetic::Genetic(int cities,int toursgen,int genrun,double percentmut)
{
rowlimit=cities-1;	
tourspergen=toursgen;
gentorun=genrun;

 numbermut = (percentmut/100)*toursgen;
 numberperm =toursgen-numbermut-2;// this is the number of permutations which will be toursgen-numbermut-2
 numberelite=2 ;// this is 2

 //fill up vector with first set of permutations.
Permutation object(rowlimit);
p=object;
//p.initS(length);
//
int* ptr =p.mkcp(rowlimit);
     for(int i = 0; i < toursgen; i++)
     {
      // p.printS();
       myvector.insert(myvector.begin(),ptr);
       p.perm1();
       ptr=p.mkcp(rowlimit);
     }

}

double Genetic::geneticalg(double s[][20])
{

//intiially check all of the permutations in our vector
//keep track of the two best orders
	scanforelite(s);

	int* copy1 = myvector.at(firstindex);
	int* copy2 =myvector.at(secondindex);
myvector.clear(); // we clear the vector because we have our two best tours from the first gen 
int* ptr =p.mkcp(rowlimit);
     for(int i = 0; i < gentorun; i++)
     {

	// insert two elites
	myvector.insert(myvector.begin(),copy1);
	myvector.insert(myvector.begin(),copy2);

	// j look adds the additional number of permutations to generation
	for(int j=0; j< numberperm; j++)
	{	
     //  p.printS();
       myvector.insert(myvector.begin(),ptr);
       p.perm1();
       ptr=p.mkcp(rowlimit);
	}
	
	//this will add numbermut mutations to the vector and the utations are generated with the elites..
	mutateadd(s,copy1,copy2, numbermut);
	// now after everything is added again to the generation we can scan it and pick out are two elites and repeat the process
	scanforelite(s);

	copy1=myvector.at(firstindex);
	copy2=myvector.at(secondindex);
	myvector.clear();

     }

return solution; 

	//now firstindex and secondindex are the the two elite orders and we will perform mutations on these
}

void Genetic::scanforelite(double s[][20])
{
 int firstindex , secondindex;
       int* ptr;
        double newcost=0, mincost1,mincost2;
        for(int i=0; i < myvector.size();i++)
        {
	
		
                 ptr=myvector.at(i);

                 newcost=s[0][ptr[0]];
                for(int j=1; j<=rowlimit ;j++)
                 {
                  int prev = ptr[j-1],next=ptr[j];
                        if(j==rowlimit)
                        {next=0;}

                  newcost=newcost+s[prev][next];
                 }
                 if(mincost1>newcost)
                {mincost1=newcost;
                firstindex=i;
		solution=mincost1;
		 }
                 else
                {        if(mincost2>newcost)
                        {mincost2=newcost;
                        secondindex=i;
                        }
                }

                 //if its the first iteration initialize mincost to the first
                if(i==0)
                {mincost1=newcost;
                mincost2=newcost;
                firstindex=i;
                secondindex=i;
                }

        }
this->firstindex=firstindex;
this->secondindex=secondindex;

}

void Genetic::mutateadd(double s[][20], int* elite1 , int* elite2 , int amount)
{
	//this function swaps and adds basically making mutations ... 
	//so this needs to be adjusted to get better approixmations at larger numbers of cities 
for(int i=0 ; i<amount/2 ; i++)
{
myvector.insert(myvector.begin(),swapcopy(i%rowlimit,(3*i)%rowlimit,elite1));

myvector.insert(myvector.begin(),swapcopy(i%rowlimit,(3*i)%rowlimit,elite2));

}

}

int*  Genetic::swapcopy(int i, int j, int* elite)
{
	int* temp=new int[20];
for(int i=0; i<rowlimit ; i++)
{
        temp[i]=elite[i];
}


         int c = temp[i];
         temp[i] = temp[j];
         temp[j] = c;
	return temp;
}



