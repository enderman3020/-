#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map> 
#include <unordered_set>
#include <functional>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

/*

訪問順（行きがけ順）をもとに、セグ木に各頂点を割り振る。

・頂点 u は、in[u] 番目に割り振られる。

・頂点 u の部分木は、区間 [in[u], out[u]) に割り振られる。

・頂点 u から根までのパスは、区間[in[nxt[u]], in[u]] を、
　u = par[nxt[u]] と代入しながら根まで処理すれば良い。計算量は O(X * log(n))

*/

int sz[210000]; // 部分木の大きさ
vector<int> g[210000]; // 親から子への辺
int par[210000]; // 子から親への辺
int nxt[210000]; // HL分解後の、各パスの終点
int in[210000]; // 訪問順（行きがけ順）
int out[210000]; // 部分木に含まれる訪問順（行きがけ順）の最大値
int t = 0; // 

void dfs_sz(int v) {
	sz[v] = 1;
	for(int &u: g[v]) {
		dfs_sz(u);
		sz[v] += sz[u];
		if(sz[u] > sz[g[v][0]]) {
			swap(u, g[v][0]);
		}
	}
}

void dfs_hld(int v) {
	in[v] = t++;
	for(int u: g[v]) {
		nxt[u] = (u == g[v][0] ? nxt[v] : u);
		dfs_hld(u);
	}
	out[v] = t;
}

int const TREE_SIZE = (1 << 20);

// Add が通用するのは、min, max, sum のいずれかに限りそう
class LazySegTreeAdd{
	public:
	// コンストラクタ
	LazySegTreeAdd(function<long long int(long long int, long long int)> monoidFunc_, 
		function<long long int(long long int, long long int)> nodeUpdateFunc_, long long int invalidValue_){
		monoidFunc = monoidFunc_;
		nodeUpdateFunc = nodeUpdateFunc_;
		invalidValue = invalidValue_;
	}
	// 値の初期化
	void init(long long int initValue){
		for(int i = 0; i < TREE_SIZE; i++){
			segTree[i] = initValue;
			beforeProp[i] = 0;
		}
	}
	// 区間 [a, b] (0-indexed)にwを足す O(log N)
	void add(int a, int b, long long int w){
		add_(a + 1, b + 2, 1, w, 0, 0, TREE_SIZE / 2);
	}
	// 区間 [a, b] (0-indexed)の値を求める O(log N)
	long long int query(int a, int b){
		return query_(a + 1, b + 2, 1, 0, 0, TREE_SIZE / 2);
	}
	private:
	function<long long int(long long int, long long int)> monoidFunc;
	function<long long int(long long int, long long int)> nodeUpdateFunc;
	long long int invalidValue;
	long long int segTree[TREE_SIZE]; // 1-indexed
	long long int beforeProp[TREE_SIZE]; // 子に伝搬してない値、1-indexed

	// [a, b) に num を足す
	long long int add_(int a, int b, int index, long long int num, long long int diff, int l, int r){
		segTree[index] += nodeUpdateFunc(diff, r - l);
		beforeProp[index] += diff;
		if(r <= a || b <= l){
			return segTree[index];
		}
		if(a <= l && r <= b){
			segTree[index] += nodeUpdateFunc(num, r - l);
			beforeProp[index] += num;
			return segTree[index];
		}
			
		long long int ret = monoidFunc(
			add_(a, b, index * 2, num, beforeProp[index], l, (l + r) / 2),
			add_(a, b, index * 2 + 1, num, beforeProp[index], (l + r) / 2, r)
		);
		beforeProp[index] = 0;
		return segTree[index] = ret;
	}
	// 区間 [a, b) の値を求める O(log N)
	long long int query_(int a, int b, int index, long long int diff, int l, int r){
		segTree[index] += nodeUpdateFunc(diff, r - l);
		beforeProp[index] += diff;
		if(r <= a || b <= l){
			return invalidValue;
		}
		if(a <= l && r <= b){
			return segTree[index];
		}
		long long int ret = monoidFunc(
			query_(a, b, index * 2, beforeProp[index], l, (l + r) / 2), 
			query_(a, b, index * 2 + 1, beforeProp[index], (l + r) / 2, r)
		);
		beforeProp[index] = 0;
		return ret;
	}
};

long long int monoidFunc(long long int a, long long int b){
	return a + b;
}
// 親から伝搬した値が diff、子のカバーする区間幅が len のときに、子に加算する値
long long int nodeUpdateFunc(long long int diff, long long int len){
	return diff * len;
}
LazySegTreeAdd segTree(monoidFunc, nodeUpdateFunc, 0);

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		for(int loop = 0; loop < k; loop++){
			int c;
			cin >> c;
			g[i].push_back(c);
			par[c] = i;
		}
	}
	par[0] = -1;
	dfs_sz(0);
	dfs_hld(0);
	/*
	cout << "in : ";
	for(int i = 0; i < n; i++){
		cout << in[i] << " ";
	}
	cout << endl;
	cout << "out : ";
	for(int i = 0; i < n; i++){
		cout << out[i] << " ";
	}
	cout << endl;
	cout << "sz : ";
	for(int i = 0; i < n; i++){
		cout << sz[i] << " ";
	}
	cout << endl;
	cout << "nxt : ";
	for(int i = 0; i < n; i++){
		cout << nxt[i] << " ";
	}
	cout << endl;
	cout << "par : ";
	for(int i = 0; i < n; i++){
		cout << par[i] << " ";
	}
	cout << endl;
	*/
	segTree.init(0);
	int q;
	cin >> q;
	for(int loop = 0; loop < q; loop++){
		int tp;
		cin >> tp;
		if(tp == 0){
			long long int v, w;
			cin >> v >> w;
			while(v != -1){
				segTree.add(in[nxt[v]], in[v], w);
				v = par[nxt[v]];
			}
			segTree.add(in[0], in[0], -w);
		}else{
			int u;
			cin >> u;
			long long int ans = 0;
			while(u != -1){
				ans += segTree.query(in[nxt[u]], in[u]);
				u = par[nxt[u]];
			}
			cout << ans << endl;
		}
	}
	return 0;
}