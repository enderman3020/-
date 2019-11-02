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

typedef pair<long long int, long long int> P;
long long int INF = 1e18;

#define MAX_V 110000
#define MAX_LOG_V 20

vector<int> G[MAX_V];

int parent[MAX_LOG_V][MAX_V]; // 2^k th parent
int depth[MAX_V]; // distance from root
int root = 0;
 
void dfs(int v, int p, int d){
	parent[0][v] = p;
	depth[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] != p){
			dfs(G[v][i], v, d + 1);
		}
	}
}
 
void init(int V){
	dfs(root, -1, 0);
	for(int k = 0; k < MAX_LOG_V - 1; k++){
		for(int v = 0; v < V; v++){
			if(parent[k][v] < 0){
				parent[k + 1][v] = -1;
			}else{
				parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
}

int lca(int u, int v){
	if(depth[u] > depth[v]){
		swap(u, v);
	}
	for(int k = 0; k < MAX_LOG_V; k++){
		if((depth[v] - depth[u]) >> k & 1){
			v = parent[k][v];
		}
	}
	if(u == v){
		return u;
	}
	for(int k = MAX_LOG_V - 1; k >= 0; k--){
		if(parent[k][u] != parent[k][v]){
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}
 
int main(){
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			G[x].push_back(i);
			G[i].push_back(x);
		}
	}
	
	init(N);
	
	int Q;
	cin >> Q;
	
	for(int i = 0; i < Q; i++){
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << endl;
	}
	
	return 0;
}