//---generates path from start to goal
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vector<vi> adj_list;
vector<string> cities;

vi visited;
vb dfs_num;

int nxtu, goal, start;
bool gr; // goal reached
void dfs(int u)
{
	//printf("gr:%d:", gr);
	
	dfs_num[u] = true;
	if (u == start) { 
		cout<<cities[u]; 
	}else{
		cout<<"->"<<cities[u]; 
	}
	//printf("%d ", u);
	if(u == goal)
	{
		gr = true;
	}

	if(!gr)
	{
		for(int j=0; j<(int)adj_list[u].size() && !gr; j++)
		{
			nxtu = adj_list[u][j];
			if(!dfs_num[nxtu])
				dfs(nxtu);
		}
	}
	return;

	
}

int main()
{
	
	//goal = 2;
	int V, total_neighbors, id, weight, gc=0;
	string cityName;
	freopen("exer2.in", "r", stdin);
	
	while(scanf("%d", &V) != EOF)
	{
		adj_list.clear();
		cities.clear();
		
		gr = false;	
		adj_list.assign(V, vi());
		
		for(int x = 0; x<V; x++){
			//scanf("%s", &cityName);
			cin>>cityName;
			cities.push_back(cityName);
		}
		
		for(int i = 0; i<V; i++)
		{
			cin>>total_neighbors;
			//scanf("%d", &total_neighbors);
			for(int j=0; j<total_neighbors; j++)
			{
				cin>>cityName;
				vector<string>::iterator it = find(cities.begin(), cities.end(), cityName);
				vector<string>::difference_type index = distance(cities.begin(), it);
				id = index;
				adj_list[i].push_back(id);
//				scanf("%d", &id);
//				adj_list[i].push_back(id); // add the connected node
			}		
				
		}
		cin>>cityName;
		vector<string>::iterator it = find(cities.begin(), cities.end(), cityName);
		vector<string>::difference_type index = distance(cities.begin(), it);
		start = index;
		
		cin>>cityName;
		it = find(cities.begin(), cities.end(), cityName);
		index = distance(cities.begin(), it);
		goal = index;
		
		//printf("Traversing Graph %d\n", ++gc);
		dfs_num.assign(V, false); //unvisited
		//for(int i=0; i<V; i++)
			 if(!dfs_num[0]) // start at index 0
				(dfs(start)), printf("\n\n");
	
	}
		return 0;
}
