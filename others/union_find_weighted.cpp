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
long long int MOD = 1000000007;

#define MAX_N 210000

using namespace std;

int par[MAX_N];
int rnk[MAX_N];
long long int diff[MAX_N]; // {親の値} = {頂点iの値} + diff[i]

// 初期化
void init(){
	for(int i = 0; i < MAX_N; i++){
		par[i] = i;
		rnk[i] = 0;
		diff[i] = 0;
	}
}

// x の親と、親までの diff の合計値を返す
P find(int x){
	P p;
	if(par[x] == x){
		p.first = x;
		p.second = 0;
		return p;
	}
	p = find(par[x]);
	diff[x] += p.second;
	p.second = diff[x];
	par[x] = p.first;
	return p;
}

// x と y を併合する、 y - x == z
void unite(int x, int y, int z){
	P px = find(x);
	P py = find(y);
	int x_par = px.first;
	int y_par = py.first;
	if(x_par == y_par){
		return;
	}
	
	if(rnk[x_par] < rnk[y_par]){
		par[x_par] = y_par;
		diff[x_par] = diff[y_par] - px.second + py.second + z;
	}else{
		par[y_par] = x_par;
		diff[y_par] = diff[x_par] + px.second - py.second - z;
		if(rnk[x_par] == rnk[y_par]){
			rnk[x_par]++;
		}
	}
}

// x, y が同じグループか判定
bool same(int x, int y){
	P px = find(x);
	P py = find(y);
	int x_par = px.first;
	int y_par = py.first;
	return (x_par == y_par);
}

int main(){
	
	int n, q;
	cin >> n >> q;
	
	init();
	
	for(int i = 0; i < q; i++){
		int num, a, b, c;
		cin >> num >> a >> b;
		if(num == 0){
			cin >> c;
			unite(a, b, c);
		}else{
			if(!same(a, b)){
				cout << "?" << endl;
			}else{
				cout << diff[a] - diff[b] << endl;
			}
		}
		/*
		for(int j = 0; j < n; j++){
			cout << par[j] << " ";
		}
		cout << endl;
		for(int j = 0; j < n; j++){
			cout << diff[j] << " ";
		}
		cout << endl;
		*/
	}
	
	return 0;
}