#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define INF (1 << 20)
#define MAX_V 12000

struct edge{
	int to;
	int cost;
};

typedef pair<int, int> P; // firstは最短距離、secondは頂点の番号

int path[MAX_V];
vector<edge> G[MAX_V];
int d[MAX_V];

// 速さはO(|E|log|V|)

void shortest_path(int s, int V){ // Vは頂点数
	
	priority_queue<P, vector<P>, greater<P> > que;
	
	for(int i = 0; i < V; i++){
		d[i] = INF;
	}
	d[s] = 0;
	
	que.push(P(0, s));
	
	while(!que.empty()){
		
		P p = que.top();
		que.pop();
		
		int v = p.second;
		
		if(d[v] < p.first){
			continue;
		}
		
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to] > e.cost + d[v]){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
				path[e.to] = v;
			}
		} // 頂点への最小コストを更新
	}
}

int main(){
	
	return 0;
}
