#define _USE_MATH_DEFINES
 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
 
using namespace std;
 
typedef pair<int, int> P;
 
vector<int> G[1000000];
vector<P> bridge;
vector<int> articulation;
int ord[1000000], low[1000000];
bool vis[1000000];
 
void dfs(int v, int p, int &k)
{
	vis[v] = true;
	
	ord[v] = k++;
	low[v] = ord[v];
	
	bool isArticulation = false;
	int ct = 0;
	
	for (int i = 0; i < G[v].size(); i++){
		if (!vis[G[v][i]]){
			ct++;
			dfs(G[v][i], v, k);
			low[v] = min(low[v], low[G[v][i]]);
			if (~p && ord[v] <= low[G[v][i]]) isArticulation = true;
			if (ord[v] < low[G[v][i]]) bridge.push_back(make_pair(min(v, G[v][i]), max(v, G[v][i])));
		}
		else if (G[v][i] != p){
			low[v] = min(low[v], ord[G[v][i]]);
		}
	}
	
	if (p == -1 && ct > 1) isArticulation = true;
	if (isArticulation) articulation.push_back(v);
}

int main(){
	
	int V, E;
	cin >> V >> E;
	
	for(int i = 0; i < E; i++){
		int v1, v2;
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	
	int k = 0;
	for (int i = 0; i < V; i++){
		if (!vis[i]) dfs(i, -1, k);
	}
	
	sort(bridge.begin(), bridge.end());
	sort(articulation.begin(), articulation.end());
	/*
	for (int i = 0; i < articulation.size(); i++){
		cout << articulation[i] << endl;
	}
	
	//cout << endl;
	*/
	for (int i = 0; i < bridge.size(); i++){
		cout << bridge[i].first << " " << bridge[i].second << endl;
	}
	
	return 0;
}