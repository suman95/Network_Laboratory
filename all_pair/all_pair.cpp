#include<bits/stdc++.h>

#define ll long int
#define in(X) scanf("%ld", &X)
#define INF 99999999

using namespace std;

ll n,e,a[1000][1000];

void AllPairShortestPath()
{
	ll i,j,k;
	for(i = 0 ; i< n ; i++ )
	{
		for(j = 0; j < n ; j++)
		{
			for(k = 0 ; k<n ; k++)
			{
				if(a[i][k] + a[k][j] < a[i][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
}

void disp()
{
	ll i,j;
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(a[i][j] == INF)
				cout<<"INF ";
			else
				cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
}

int main()
{
	ll i,j,x,y,c;
	//cout<<"Enter the number of nodes : ";
	in(n);
	//cout<<"Enter number edges :";
	in(e);
	
	//initialization 
	for(i = 0 ; i< n ; i++)
		for(j = 0; j<n; j++)
			if(i == j)
				a[i][j] = 0;
			else
				a[i][j] = INF;
	
	//cout<<"Enter the edges \n";
	for(i= 0 ; i < n ; i++)
	{
	//	cout<<"> ";
		in(x);
		in(y);
		in(c);
		a[x-1][y-1] = c;
	}
	cout<<"Given graph :\n";
	disp();
	AllPairShortestPath();
	cout<<"Final All pair Shortest Path :\n";
	disp();	
	return 0;
}
