#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF (1 << 20)
#define MAX_V 200

int path[MAX_V];
int cost[MAX_V][MAX_V];
bool used[MAX_V];
int d[MAX_V];

// O(V^2)

void shortest_path(int s, int V){ // Vは頂点数
	for(int i = 0; i < V; i++){
		d[i] = INF;
		used[i] = false;
	}
	d[s] = 0;
	path[s] = -1;
	
	while(true){
		
		int add_v = -1;
		
		for(int u = 0; u < V; u++){
			if(!used[u] && (add_v == -1 || d[u] < d[add_v])){
				add_v = u;
			}
		} // 更新する頂点を決定
		//cout << add_v << " ";
		if(add_v == -1){
			break;
		} // 更新する頂点がない場合、終了
		used[add_v] = true;
		
		for(int u = 0; u < V; u++){
			if(d[add_v] + cost[add_v][u] < d[u]){
				d[u] = d[add_v] + cost[add_v][u];
				path[u] = add_v;
			}
		} // 集合の外の頂点への最小コストを更新
	}
}

void path_track(int num){
	if(num == -1){
		cout << endl;
		return;
	}
	path_track(path[num]);
	cout << num + 1 << endl;
}

int main(){
	
	int V, m;
	
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
	
	s = 0;
	g = 2;
	
	shortest_path(s, V);
	
	path_track(g);
	
	return 0;
}
