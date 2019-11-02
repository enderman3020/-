#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;

#define MAX_V 11000

int V;
vector<int> G[MAX_V]; // グラフの隣接リスト表現
vector<int> rG[MAX_V];// 辺の向きを逆にしたグラフ
vector<int> vs;       // 帰りがけ順の並び
bool used[MAX_V];     // すでに調べたか
int cmp[MAX_V];       // 属する強連結成分のトポロジカル順序

// from から to への辺を張る関数
void add_edge(int from, int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v){
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]){
			dfs(G[v][i]);
		}
	}
	vs.push_back(v);
}

void rdfs(int v, int k){
	used[v] = true;
	cmp[v] = k;
	for(int i = 0; i < rG[v].size(); i++){
		if(!used[rG[v][i]]){
			rdfs(rG[v][i], k);
		}
	}
}

// 強連結成分分解を行う関数、返り値は強連結成分の個数
int scc(){
	memset(used, 0, sizeof(used));
	vs.clear();
	for(int v = 0; v < V; v++){
		if(!used[v]){
			dfs(v);
		}
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for(int i = vs.size() - 1; i >= 0; i--){
		if(!used[vs[i]]){
			rdfs(vs[i], k++);
		}
	}
	return k;
}

int main(){
	
	int E, Q;
	
	cin >> V >> E;
	
	// s から t への有向辺を張る
	for(int i = 0; i < E; i++){
		int s, t;
		cin >> s >> t;
		add_edge(s, t);
	}
	
	scc();
	
	/*
	// トポロジカル順序を出力
	for(int i = 0; i < V; i++){
		cout << cmp[i] << " ";
	}
	*/
	
	// 同じ強連結成分に属するか判定
	cin >> Q;
	for(int i = 0; i < Q; i++){
		int u, v;
		cin >> u >> v;
		cout << (cmp[u] == cmp[v]) << endl;
	}
	
	return 0;
}