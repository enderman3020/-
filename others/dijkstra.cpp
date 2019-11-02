#include <iostream>
#include <cstdio>

using namespace std;

#define INF (1 << 28)
#define MAX_E 1000
#define MAX_V 100

int cost[MAX_V][MAX_V];
bool used[MAX_V];
int d[MAX_V];
int V;

// O(V^2)

void shortest_path(int s){
	for(int i = 0; i < V; i++){
		d[i] = INF;
		used[i] = false;
	}
	d[s] = 0;
	while(true){
		
		int add_v = -1;
		
		for(int u = 0; u < V; u++){
			if(!used[u] && (add_v == -1 || d[u] < d[add_v])){
				add_v = u;
			}
		} //
		
		if(add_v == -1){
			break;
		} //
		used[add_v] = true;
		
		for(int u = 0; u < V; u++){
			d[u] = min(d[u], d[add_v] + cost[add_v][u]);
		} //
	}
}

int main(){
	
	V = 3;
	
	cost[0][1] = 4;
	cost[1][0] = 4;
	cost[0][2] = 5;
	cost[2][0] = 5;
	cost[1][2] = 2;
	cost[2][1] = 2;
	cost[0][0] = INF;
	cost[1][1] = INF;
	cost[2][2] = INF;
	
	shortest_path(0);
	printf("%d\n", d[2]);
	
	return 0;
}
