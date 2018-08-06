//---generates path from start to goal
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

typedef vector<int> vectormagtanggol;

int V, E, a, b, start, goal, u;
bool gr; //goal reached
vector<vectormagtanggol> adj_list;
vectormagtanggol parent;
vector<string> magtanggol;

void printPath(int u) 
{   
	if (u == start) 
	{ 
		//printf("%s", magtanggol[u]); return; 
		cout<<magtanggol[u]; return; 
	}
	printPath(parent[u]);   
  	//printf(" %s", magtanggol[u]); 
  	cout<<"->"<<magtanggol[u]; return; 
}

int main()
{
	int total_neighbors, id, gc=0, c3=0;
	int numberOfCities;
	string cityName;
	freopen("exer1.in", "r", stdin);
	//goal = 2; // goal node is 7
	while(scanf("%d", &numberOfCities) != EOF)
	//while(!stdin.eof())
	{
		adj_list.clear();
		magtanggol.clear();
		//cin>>numberOfCities;
		//magtanggol.assign(numberOfCities, "");
		adj_list.assign(numberOfCities, vectormagtanggol());
		for(int x = 0; x<numberOfCities; x++){
			//scanf("%s", &cityName);
			cin>>cityName;
			magtanggol.push_back(cityName);
		}
		
		for(int i = 0; i<numberOfCities; i++)
		{
			//scanf("%d", &total_neighbors);
			cin>>total_neighbors;
			for(int j=0; j<total_neighbors; j++)
			{
				//scanf("%s", &cityName);
				cin>>cityName;
				vector<string>::iterator it = find(magtanggol.begin(), magtanggol.end(), cityName);
				vector<string>::difference_type index = distance(magtanggol.begin(), it);
				id = index;
				//scanf("%d", &id);
				adj_list[i].push_back(id); // add the connected node
			}		
				
		}
		//printf("Traversing Graph %d\n", ++gc);
		//scanf("%s", &cityName);
		cin>>cityName;
		vector<string>::iterator it = find(magtanggol.begin(), magtanggol.end(), cityName);
		vector<string>::difference_type index = distance(magtanggol.begin(), it);
		start = index;// start at the 0
		
		//scanf("%s", &cityName);
		cin>>cityName;
		it = find(magtanggol.begin(), magtanggol.end(), cityName);
		index = distance(magtanggol.begin(), it);
		goal = index;
		
		vectormagtanggol dist(numberOfCities, 1000000000); 
		dist[start] = 0;
		queue<int> q; q.push(start);
		parent.assign(numberOfCities, -1);
		int layer = -1;
		gr = false;

		while(!q.empty())
		{
			u = q.front(); q.pop();
 			
			layer = dist[u];
			if(u == goal)
			{
				gr = true;
				while(!q.empty())
					q.pop();		
			}			
			for(int j = 0; j<(int)adj_list[u].size() && !gr; j++)
			{
				int v = adj_list[u][j];
				if(dist[v] == 1000000000)
				{
					dist[v] = dist[u]+1; 
					parent[v] = u; //
					q.push(v); //node to visit
				}
			}
			
		}
		printPath(goal);
		printf("\n\n");
		//cin>>numberOfCities;
	}
		return 0;
}
