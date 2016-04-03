#include <bits/stdc++.h>
#include <string>
using namespace std;


void callfunction(int round,int& flag,int page1,int page2,int no_pages,int rounds,int buc,string tempstr)
{
	if(round>rounds || round+1>no_pages-1)
	{flag=0;
		return;

	}

int no1=0;int no2=0;int value;
	int vec[round+1];string line;int final1[round+1];int final2[round+1];
	for(int i=0;i<=round;i++)
		{vec[i]=0;final1[i]=0;}
	fstream f;
	fstream inter;
	
cout<<"Reading relation rel1.round"<<round-1<<".bucket"<<buc<<"\n";
stringstream rr;rr<<round-1;

   stringstream ss; ss<< buc;string g="rel1.round"+rr.str()+".bucket"+ss.str();
    //cout<<"opening "<<g.c_str()<<"\n";
f.open(g.c_str());
while(getline(f,line))
{no1++;
	
value=atoi(line.c_str());
int bucket=value%(round+1);
if(vec[bucket]==0)
final1[bucket]++;
vec[bucket]++;
stringstream rr;rr<<round;
cout<<value<<" mapped to bucket "<<bucket<<"\n";
    if(vec[bucket]==page1)
    {cout<<"Page for bucket "<<bucket<<" full.Flushed to secondary storage.\n";
	vec[bucket]=0;
	
    }
   stringstream ss; ss<< bucket;string g="rel1.round"+rr.str()+".bucket"+ss.str();
    //std::cout << ss.str() << std::endl;
  // cout<<"opening "<<g.c_str()<<"\n";
inter.open(g.c_str(),fstream::out|fstream::app);
inter<<value<<"\n";
inter.close();



}
f.close();
cout<<"Done with relation rel1.round"<<round-1<<".bucket"<<buc<<".Created the following files :\n";
for(int i=0;i<round+1;i++)
{cout<<"rel1.round"<<round<<".bucket"<<i<<" : "<<final1[i]<<" pages.\n";

}

	for(int i=0;i<=round;i++)
		{vec[i]=0;final2[i]=0;}

	cout<<"Reading relation rel2.round"<<round-1<<".bucket"<<buc<<"\n";
stringstream rr2;rr2<<round-1;

   stringstream ss2; ss2<< buc; g="rel2.round"+rr2.str()+".bucket"+ss2.str();
   // cout<<"opening "<<g<<"\n";
f.open(g.c_str());
while(getline(f,line))
{no2++;
	
value=atoi(line.c_str());
int bucket=value%(round+1);
if(vec[bucket]==0)
final2[bucket]++;
vec[bucket]++;
 stringstream rr;rr<<round;
cout<<value<<" mapped to bucket "<<bucket<<"\n";
    if(vec[bucket]==page2)
    {cout<<"Page for bucket "<<bucket<<" full.Flushed to secondary storage.\n";
	vec[bucket]=0;
	
    }
stringstream ss; ss<< bucket;string g="rel2.round"+rr.str()+".bucket"+ss.str();
inter.open(g.c_str(),fstream::out|fstream::app);
inter<<value<<"\n";
inter.close();



}
f.close();
cout<<"Done with relation rel2.round"<<round-1<<".bucket"<<buc<<".Created the following files :\n";
for(int i=0;i<round+1;i++)
{cout<<"rel2.round"<<round<<".bucket"<<i<<" : "<<final2[i]<<" pages.\n";

}
fstream temp;

for(int i=0;i<=round;i++)
{cout<<"Bucket "<<i<<" .Total size is "<<final1[i]+final2[i]<<" pages.\n";
	if(final1[i]+final2[i]>no_pages-1)
	{cout<<"Cannot perform in memory join as no of pages available are "<<no_pages<<".\n";
if(round+1>rounds)
{flag=0;return;
}
	cout<<"Performing "<<round+1<<" round of hashing on round"<<round<<".bucket"<<i<<".\n";
	stringstream temp2;temp2<<i;
	tempstr=tempstr+"."+temp2.str();
	stringstream temps;temps<<i;
	stringstream temps2;temps2<<round+1;
	ifstream tempt;
	fstream temptempt;string line3;int value3;
	for(int h=0;h<=round+1;h++)
	{stringstream temph;temph<<h;
		string g="rel1.round"+temps2.str()+".bucket"+temph.str();
		ifstream ifile(g.c_str());
		
		//cout<<"Dfg\n";
		if(ifile)
		{   /*
				tempt.open(g.c_str());
				
				string f="rel1.temp."+temph.str();
				temptempt.open(f.c_str(),fstream::out|fstream::app);
				while(getline(tempt,line3))
				{value3=atoi(line3.c_str());
					temptempt<<value<<"\n";

				}
				temptempt.close();
				tempt.close();
			*/
			remove(g.c_str());
			
		}

	}
	for(int h=0;h<=round+1;h++)
	{stringstream temph;temph<<h;
		string g="rel2.round"+temps2.str()+".bucket"+temph.str();
		ifstream ifile(g.c_str());
		
		if(ifile)
		{	/*
				tempt.open(g.c_str());
				string f="rel2.temp."+temph.str();
				temptempt.open(f.c_str(),fstream::out|fstream::app);
				while(getline(tempt,line3))
				{value3=atoi(line3.c_str());
					temptempt<<value<<"\n";

				}
				temptempt.close();
			*/
			remove(g.c_str());
		}

	}
	callfunction(round+1,flag,page1,page2,no_pages,rounds,i,tempstr);
	if(flag==0)
		return;

	}
	else{cout<<"Matching pairs are : \n";
		string line2;int value2;
		fstream one;fstream two;
		stringstream rr;rr<<round;
		stringstream ss; ss<< i;string g="rel1.round"+rr.str()+".bucket"+ss.str();
    	one.open(g.c_str());
    	g="rel2.round"+rr.str()+".bucket"+ss.str();
    	
    	while(getline(one,line))
    	{value=atoi(line.c_str());
    		two.open(g.c_str());
    		while(getline(two,line2))
    		{value2=atoi(line2.c_str());
    			if(value==value2)
    			{cout<<"\n"<<value<<"\n";

    			}

    		}
    		two.close();

    	}
    	one.close();
    	cout<<"-------------------------------------------------------------------------------\n";
	}
	

}

}



void main_function(int round,int& flag,int page1,int page2,int no_pages,int rounds)
{if(round>rounds || round+1>no_pages-1)
	{flag=0;
		return;

	}
	int no1=0;int no2=0;int value;
	int vec[round+1];string line;int final1[round+1];int final2[round+1];
	for(int i=0;i<=round;i++)
		{vec[i]=0;final1[i]=0;}
	fstream f;
	fstream inter;
	cout<<"Hashing Round "<<round<<":\n";
cout<<"Reading relation 1:\n";
f.open("rel1.txt");
while(getline(f,line))
{no1++;
	
value=atoi(line.c_str());
int bucket=value%(round+1);
if(vec[bucket]==0)
final1[bucket]++;
vec[bucket]++;
stringstream rr;rr<<round;
cout<<value<<" mapped to bucket "<<bucket<<"\n";
    if(vec[bucket]==page1)
    {cout<<"Page for bucket "<<bucket<<" full.Flushed to secondary storage.\n";
	vec[bucket]=0;
	
    }
   stringstream ss; ss<< bucket;string g="rel1.round"+rr.str()+".bucket"+ss.str();
    //std::cout << ss.str() << std::endl;
inter.open(g.c_str(),fstream::out|fstream::app);
inter<<value<<"\n";
inter.close();



}
f.close();
cout<<"Done with relation 1.Created the following files :\n";
for(int i=0;i<round+1;i++)
{cout<<"rel1.round"<<round<<".bucket"<<i<<" : "<<final1[i]<<" pages.\n";

}

	for(int i=0;i<=round;i++)
		{vec[i]=0;final2[i]=0;}
	cout<<"\nReading relation 2:\n";
f.open("rel2.txt");
while(getline(f,line))
{no2++;
	
value=atoi(line.c_str());
int bucket=value%(round+1);
if(vec[bucket]==0)
final2[bucket]++;
vec[bucket]++;
 stringstream rr;rr<<round;
cout<<value<<" mapped to bucket "<<bucket<<"\n";
    if(vec[bucket]==page2)
    {cout<<"Page for bucket "<<bucket<<" full.Flushed to secondary storage.\n";
	vec[bucket]=0;
	
    }
stringstream ss; ss<< bucket;string g="rel2.round"+rr.str()+".bucket"+ss.str();
inter.open(g.c_str(),fstream::out|fstream::app);
inter<<value<<"\n";
inter.close();



}
f.close();
cout<<"Done with relation 2.Created the following files :\n";
for(int i=0;i<round+1;i++)
{cout<<"rel2.round"<<round<<".bucket"<<i<<" : "<<final2[i]<<" pages.\n";

}

for(int i=0;i<=round;i++)
{cout<<"Bucket "<<i<<" .Total size is "<<final1[i]+final2[i]<<" pages.\n";
	if(final1[i]+final2[i]>no_pages-1)
	{cout<<"Cannot perform in memory join as no of pages available are "<<no_pages<<".\n";
if(round+1>rounds)
{flag=0;return;

}
	cout<<"Performing "<<round+1<<" round of hashing on round"<<round<<".bucket"<<i<<".\n";
	stringstream temps;temps<<i;
	stringstream temps2;temps2<<round+1;
	ifstream tempt;
	fstream temptempt;string line3;int value3;
	for(int h=0;h<=round+1;h++)
	{stringstream temph;temph<<h;
		string g="rel1.round"+temps2.str()+".bucket"+temph.str();
		ifstream ifile(g.c_str());
		
		//cout<<"Dfg\n";
		if(ifile)
		{   /*
				tempt.open(g.c_str());
				
				string f="rel1.temp."+temph.str();
				temptempt.open(f.c_str(),fstream::out|fstream::app);
				while(getline(tempt,line3))
				{value3=atoi(line3.c_str());
					temptempt<<value<<"\n";

				}
				temptempt.close();
				tempt.close();
			*/
			remove(g.c_str());
			
		}

	}
	for(int h=0;h<=round+1;h++)
	{stringstream temph;temph<<h;
		string g="rel2.round"+temps2.str()+".bucket"+temph.str();
		ifstream ifile(g.c_str());
		
		if(ifile)
		{	/*
				tempt.open(g.c_str());
				string f="rel2.temp."+temph.str();
				temptempt.open(f.c_str(),fstream::out|fstream::app);
				while(getline(tempt,line3))
				{value3=atoi(line3.c_str());
					temptempt<<value<<"\n";

				}
				temptempt.close();
			*/
			remove(g.c_str());
		}

	}
	callfunction(round+1,flag,page1,page2,no_pages,rounds,i,temps.str());
	if(flag==0)
		return;

	}
	else{cout<<"Matching pairs are : \n";
		string line2;int value2;
		fstream one;fstream two;
		stringstream rr;rr<<round;
		stringstream ss; ss<< i;string g="rel1.round"+rr.str()+".bucket"+ss.str();
    	one.open(g.c_str());
    	g="rel2.round"+rr.str()+".bucket"+ss.str();
    	
    	while(getline(one,line))
    	{value=atoi(line.c_str());
    		two.open(g.c_str());
    		while(getline(two,line2))
    		{value2=atoi(line2.c_str());
    			if(value==value2)
    			{cout<<"\n"<<value<<"\n";

    			}

    		}
    		two.close();

    	}
    	one.close();
    	cout<<"-------------------------------------------------------------------------------\n";
	}
	

}


}

int main()
{vector<int> v; 
string file1;string file2;int record1_size;int record2_size;int page_size;int no_pages;int rounds;int round_no=1;
int no1=0;int no2=0;int value;
cin>>record1_size>>record2_size>>page_size>>no_pages>>rounds;
int page1=floor((float)page_size/(float)record1_size);
int page2=floor((float)page_size/(float)record2_size);
//cout<<page1<<" "<<page2<<"dfg\n";
fstream f;
fstream inter;
f.open("rel1.txt");
string line;
while(getline(f,line))
{no1++;
	

}
f.close();
f.open("rel2.txt");
 line;
while(getline(f,line))
{no2++;
}
f.close();
cout<<"Size of relation 1: "<<ceil((float)(no1*record1_size)/(float)page_size)<<" pages\n";
cout<<"Size of relation 2: "<<ceil((float)(no2*record2_size)/(float)page_size)<<" pages\n";
cout<<"Total number of available pages: "<<no_pages<<"\n";
cout<<"Number of buckets in hash table: 2\n";


int flag=1;
if(rounds==0)
cout<<"Cannot perform in memory hash join with the given specification.\n";
else
{
main_function(1,flag,page1,page2,no_pages,rounds);
if(flag==0)
	cout<<"Cannot perform in memory hash join with the given specification.\n";

else cout<<"Done!!!\n";


}



	
}