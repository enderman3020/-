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

#define MAX_V 1000

struct edge{
	long long int to, cap, cost, rev; // 
};

vector<edge> G[MAX_V] = {};
long long int dist[MAX_V]; // 
int prevv[MAX_V], preve[MAX_V]; // 

// 
void add_edge(long long int from, long long int to, long long int cap, long long int cost){
	G[from].push_back((edge){to, cap, cost, (long long int)G[to].size()});
	G[to].push_back((edge){from, 0, -cost, (long long int)G[from].size() - 1}); // 
}

// 
long long int min_cost_flow(int s, int t, int f, int V){
	
	long long int res = 0;
	
	while(f > 0){
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while(update){
			update = false;
			for(int v = 0; v < V; v++){
				if(dist[v] == INF){
					continue;
				}
				for(int i = 0; i < G[v].size(); i++){
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}
		if(dist[t] == INF){
			return INF;
		}
		
		long long int d = f;
		for(int v = t; v != s; v = prevv[v]){
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d * dist[t];
		for(int v = t; v != s; v = prevv[v]){
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

int main(){
	
	int V, E, F;
	cin >> V >> E >> F;
	
	for(int i = 0; i < E; i++){
		int num1, num2, cap, cost;
		cin >> num1 >> num2 >> cap >> cost;
		add_edge(num1, num2, cap, cost);
	}
	
	cout << min_cost_flow(0, V - 1, F, V) << endl;
	
	return 0;
}