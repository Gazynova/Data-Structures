#include<iostream>

using namespace std;

class matrix
{
	public:
		
		int time,fuel,nc,adj[10][10],k,l;
		string city[10];
		string cityname,arrcity,depcity;
		int i,j,per;
		
		matrix()
		{
			cout<<"constructor called \n";
			cout<<"enter the no of cities :\t";
			cin>>nc;
			for(i=0;i<nc;i++)
			{
				for(j=0;j<nc;j++)
				{
					adj[i][j] = 0;
				}
			}	
		}
		
		int create()
		{
			cout<<"enter the number of cities :\t";
			cin>>nc;
			for(i=0;i<nc;i++)
			{
				cout<<"enter the "<<i<<"th city name :\t";
				cin>>cityname;
				city[i] = cityname;
				
			}

			do
			{
				cout<<"enter the flight details \n";
				cout<<"enter the flight arrival :\t";
				cin>>arrcity;
				cout<<"enter the flight departure :\t";
				cin>>depcity;
				for( i = 0;i<nc;i++)
				{
					if(city[i] == arrcity)
					{	
						k = i;
						//exit;
					}
				}
				for(j =0;j<nc;j++)
				{
					if(city[j] == depcity)
					{
						l = j;
						//exit;
					}
				}
				if(adj[k][l] == 0)
				{
					adj[k][l] = 1;
					cout<<"is there reverse flight is also available(1/0) :\t";
					cin>>per;
					if(per == 1)
					{
						adj[l][k] = 1;
					}
					per == 0;
				}
				else
				{
					cout<<"There is already flight from arrival to departure please choose another \n";
				}
				cout<<"do you want to add more flights :\t";
				cin>>per;
			}while(per);
		}
		
		void display()
		{
			for( i=0; i<nc;i++)
			{
				cout<<"\t"<<city[i];
			}
			cout<<"\n";
			for(i=0;i<nc;i++)
			{
				cout<<city[i]<<"\t";
				for(j=0;j<nc;j++)
				{
					cout<<adj[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
				
			
			
			
};


int main()
{
	matrix ele;
	ele.create();
	ele.display();
	return 0;
	
}
				
			
				
							

