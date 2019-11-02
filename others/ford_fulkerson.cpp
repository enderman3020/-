#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

long long int INF = 1e18;

#define MAX_V 1000

struct edge{
	long long int to, cap, rev; // 
};

vector<edge> G[MAX_V] = {};
bool used[MAX_V];

// 
void add_edge(long long int from, long long int to, long long int cap){
	G[from].push_back((edge){to, cap, (long long int)G[to].size()});
	G[to].push_back((edge){from, 0, (long long int)G[from].size() - 1}); // 
	// G[to].push_back((edge){from, cap, (long long int)G[from].size() - 1}); // 
}

// 
long long int dfs(int v, int t, long long int f){
	if(v == t){
		return f;
	}
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		edge &e = G[v][i];
		if(!used[e.to] && e.cap > 0){
			long long int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

// 
long long int max_flow(int s, int t){
	long long int flow = 0;
	while(true){
		fill(used, used + MAX_V, 0);
		long long int f = dfs(s, t, INF);
		if(f == 0){
			return flow;
		}
		flow += f;
	}
}

int main(){
	
	int N, G, E;
	cin >> N >> G >> E;
	
	for(int i = 0; i < G; i++){
		int num;
		cin >> num;
		add_edge(num, N, 1);
	}
	
	for(int i = 0; i < E; i++){
		int num1, num2;
		cin >> num1 >> num2;
		add_edge(num1, num2, 1);
	}
	
	cout << max_flow(0, N) << endl;
	
	return 0;
}