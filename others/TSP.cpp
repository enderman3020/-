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

int main(){
	
	long long int V, E;
	cin >> V >> E;
	
	long long int cost[V][V];
	
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			cost[i][j] = INF;
		}
	}
	
	for(int i = 0; i < E; i++){
		int u, v, c;
		cin >> u >> v >> c;
		cost[u][v] = c;
	}
	
	long long int DP[V][(1 << V)];
	
	for(int i = 0; i < V; i++){
		for(int j = 0; j < (1 << V); j++){
			DP[i][j] = INF;
		}
	}
	DP[0][0] = 0;
	
	for(int i = 0; i < (1 << V); i++){
		for(int j = 0; j < V; j++){
			if(i & (1 << j)){
				for(int k = 0; k < V; k++){
					DP[j][i] = min(DP[j][i], DP[k][i - (1 << j)] + cost[k][j]);
				}
			}
		}
	}
	
	long long int ans = DP[0][(1 << V) - 1];
	if(ans == INF){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
	
	return 0;
}