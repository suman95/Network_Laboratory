//dijikstra's algorithm - sigle source shortest path
#include<bits/stdc++.h>

#define ll long int
#define in(X) scanf("%ld", &X)
#define INF 99999999

using namespace std; 

ll n,e,a[1000][1000];
ll table[1000];
void SingleSourceShortestPath(int s)
{
	ll i,v1;
	bool visited[n];
	for(i = 0 ; i <  n ; i++)
		visited[i] = false;
	queue<int> q;
	q.push(s);
	while(q.empty())
	{
		v1 = q.front();
		q.pop();
		for(i = 0 ; i < n ; i++)
		{
			if(a[v1][i] != INF && visited[i] == false)
			{
				visited[i] = true;
				q.push(i);
			}
		}
		if(a[s][v1] != INF)
		{
			table[v1] = s;
		}
		for(i = 0 ; i < n ; i++)
		{
			if(a[s][i] + a[i][v1] < a[s][v1])
			{
				a[s][v1] = a[s][i] + a[i][v1];
				table[v1] = i;
			}
		}	
	}
}

//display
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


//display of path
void path(int s,int i)
{
	int k;
	k = table[i];
	do
	{
		cout<<k<<"<-";
		k = table[k];
		
	}while(k != s && k!=99);
}
		

int main()
{
	ll i,j,x,y,c,s;
	//cout<<"Enter the number of nodes : ";
	in(n);
	//cout<<"Enter number edges :";
	in(e);
	
	//initialization
	 
	for(i = 0 ; i< n ; i++)
	{	for(j = 0; j<n; j++)
			if(i == j)
				a[i][j] = 0;
			else
				a[i][j] = INF;
		table[i] = 99;
	}
	
	//cout<<"Enter the edges \n";
	for(i= 0 ; i < n ; i++)
	{
	//	cout<<"> ";
		in(x);
		in(y);
		in(c);
		a[x][y] = c;
	}
	cout<<"Given graph :\n";
	disp();
	cout<<"Enter the source ";
	in(s);
	SingleSourceShortestPath(s);
	for(i = 0 ; i < n ; i++)
	{
		cout<<"\nPath :"<<s<<" -> "<<i<<" \n";
		path(s,i);
		cout<<"\nCost : "<<a[s][i]<<"\n";
	}
	return 0;
}
