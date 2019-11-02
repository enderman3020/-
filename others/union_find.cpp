#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

#define MAX_N 200000

int par[MAX_N];
int rnk[MAX_N];
long long int sz[MAX_N];

// 初期化
void init(){
	for(int i = 0; i < MAX_N; i++){
		par[i] = i;
		rnk[i] = 0;
		sz[i] = 1;
	}
}

// x の親を返す
int find(int x){
	if(par[x] == x){
		return x;
	}
	return par[x] = find(par[x]);
}

// x と y を併合する
void unite(int x, int y){
	int x_par = find(x);
	int y_par = find(y);
	if(x_par == y_par){
		return;
	}
	
	if(rnk[x_par] < rnk[y_par]){
		sz[y_par] = sz[x_par] + sz[y_par];
		par[x_par] = y_par;
	}else{
		sz[x_par] = sz[x_par] + sz[y_par];
		par[y_par] = x_par;
		if(rnk[x_par] == rnk[y_par]){
			rnk[x_par]++;
		}
	}
}

// x, y が同じグループか判定
bool same(int x, int y){
	return (find(x) == find(y));
}

int main(){
	
	int n = 10;
	
	init(10);
	
	unite(1, 2);
	unite(3, 4);
	unite(5, 6);
	unite(4, 6);
	
	for(int i = 0; i < n; i++){
		cout << par[i] << " " << rank[i] << endl;
	}
	
	return 0;
}
