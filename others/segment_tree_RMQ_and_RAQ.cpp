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
	return min(a, b);
}
// 親から伝搬した値が diff、子のカバーする区間幅が len のときに、子に加算する値
long long int nodeUpdateFunc(long long int diff, long long int len){
	return diff;
}
LazySegTreeAdd segTree(monoidFunc, nodeUpdateFunc, INF);

int main(){
	segTree.init(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		long long int tp, a, b;
		cin >> tp >> a >> b;
		if(tp == 0){
			long long int x;
			cin >> x;
			segTree.add(a, b, x);
		}else{
			cout << segTree.query(a, b) << endl;
		}
	}
	return 0;
}