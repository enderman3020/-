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

typedef pair<long long int, long long int> P2;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int const TREE_SIZE = (1 << 20);

class LazySegTreeUpdate{
	public:
	// コンストラクタ
	LazySegTreeUpdate(function<long long int(long long int, long long int)> monoidFunc_, 
		function<long long int(long long int, long long int)> nodeUpdateFunc_, 
		function<long long int(long long int, long long int, long long int)> resultFunc_, long long int invalidValue_){
		monoidFunc = monoidFunc_;
		nodeUpdateFunc = nodeUpdateFunc_;
		resultFunc = resultFunc_;
		invalidValue = invalidValue_;
	}
	// 値の初期化
	void init(long long int initValue){
		for(int i = 0; i < TREE_SIZE; i++){
			segTree[i] = initValue;
			isAssigned[i] = false;
		}
	}
	// 区間 [a, b] (0-indexed)を w に変更する O(log N)
	void update(int a, int b, long long int w){
		update_(a + 1, b + 2, 1, w, 0, TREE_SIZE / 2);
	}
	// 区間 [a, b] (0-indexed)の値を求める O(log N)
	long long int query(int a, int b){
		return query_(a + 1, b + 2, 1, 0, TREE_SIZE / 2);
	}
	private:
	function<long long int(long long int, long long int)> monoidFunc;
	function<long long int(long long int, long long int)> nodeUpdateFunc;
	function<long long int(long long int, long long int, long long int)> resultFunc;
	long long int invalidValue;
	long long int segTree[TREE_SIZE]; // 1-indexed
	bool isAssigned[TREE_SIZE]; // 値か代入されたかどうか、1-indexed

	// [a, b) を num に変更する
	long long int update_(int a, int b, int index, long long int num, int l, int r){
		if(r <= a || b <= l){
			return segTree[index];
		}
		if(a <= l && r <= b){
			segTree[index] = nodeUpdateFunc(num, r - l);
			isAssigned[index] = true;
			return segTree[index];
		}
		if(isAssigned[index]){
			isAssigned[index * 2] = isAssigned[index * 2 + 1] = true;
			segTree[index * 2] = segTree[index * 2 + 1] = resultFunc(segTree[index], r - l, (r - l) / 2);
			isAssigned[index] = false;
		}
		return segTree[index] = monoidFunc(
			update_(a, b, index * 2, num, l, (l + r) / 2),
			update_(a, b, index * 2 + 1, num, (l + r) / 2, r)
		);
	}
	// 区間 [a, b) の値を求める O(log N)
	long long int query_(int a, int b, int index, int l, int r){
		if(r <= a || b <= l){
			return invalidValue;
		}
		if(a <= l && r <= b){
			return segTree[index];
		}
		if(isAssigned[index]){
			return resultFunc(segTree[index], (r - l), min(r, b) - max(l, a));
		}
		return monoidFunc(
			query_(a, b, index * 2, l, (l + r) / 2), 
			query_(a, b, index * 2 + 1, (l + r) / 2, r)
		);
	}
};

long long int monoidFunc(long long int a, long long int b){
	return min(a, b);
}
// 各要素に代入された値が num、区間幅が len のときの、区間の値
long long int nodeUpdateFunc(long long int num, long long int len){
	return num;
}
// 頂点の区間の値が num、頂点の区間幅が len であり、区間の要素は全て同じ値であるとする。
// このとき頂点の区間に含まれる、区間幅が len1 である区間の値
long long int resultFunc(long long int num, long long int len, long long int len1){
	return num;
}
LazySegTreeUpdate segTree(monoidFunc, nodeUpdateFunc, resultFunc, INF);

int main(){
	segTree.init(INF);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		long long int tp, a, b;
		cin >> tp >> a >> b;
		if(tp == 0){
			long long int x;
			cin >> x;
			segTree.update(a, b, x);
		}else{
			cout << segTree.query(a, b) << endl;
		}
	}
	return 0;
}