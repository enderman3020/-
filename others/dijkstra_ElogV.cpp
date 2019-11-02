#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef pair<long long int, int> P;
long long int INF = 1e18;

#define MAX_V 200000

struct edge{
	int to;
	long long int cost;
    edge(int to_, long long int cost_){
        to = to_;
        cost = cost_;
    }
};

vector<edge> G[MAX_V];
long long int d[MAX_V];

// O(ElogV)

void shortest_path(int s, int V){
	
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
			}
		}
	}
}

int main(){
	
	int V, E;
	cin >> V >> E;
	
	for(int i = 0; i < E; i++){
		int u, v, cost;
		cin >> u >> v >> cost;
		
		edge e;
		e.cost = cost;
		e.to = u;
		G[v].push_back(e);
		e.to = v;
		G[u].push_back(e);
	}
	
	shortest_path(0, V);
	
	return 0;
}
