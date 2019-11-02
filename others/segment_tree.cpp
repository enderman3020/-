#define _USE_MATH_DEFINES

#include <iostream>
#include <functional>

using namespace std;

typedef pair<long long int, long long int> P2;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int const TREE_SIZE = (1 << 20);

class SegTree{
	public:
	// コンストラクタ
	SegTree(std::function<long long int(long long int, long long int)> monoidFunc_, long long int invalidValue_){
		monoidFunc = monoidFunc_;
		invalidValue = invalidValue_;
	}
	// 値の初期化
	void init(long long int initValue){
		for(int i = 0; i < TREE_SIZE; i++){
			segTree[i] = initValue;
		}
	}
	// a番目(0-indexed)をwに変更する O(log N)
	void change(int a, long long int w){
		change_(a + 1, w);
	}
	// 区間 [a, b] (0-indexed)の値を求める O(log N)
	long long int query(int a, int b){
		return query_(a + 1, b + 2, 1, 0, TREE_SIZE / 2);
	}
	private:
	function<long long int(long long int, long long int)> monoidFunc;
	long long int invalidValue;
	long long int segTree[TREE_SIZE]; // 1-indexed

	// a番目をwに変更する O(log N)
	void change_(int a, long long int w){
		a += TREE_SIZE / 2;
		segTree[a] = w;
		for(int x = a / 2; x > 0; x /= 2){
			segTree[x] = monoidFunc(segTree[2 * x], segTree[2 * x + 1]);
		}
	}
	// 区間 [a, b) の値を求める O(log N)
	// query(a, b, 1, 0, TREE_SIZE / 2) のように呼ぶ
	long long int query_(int a, int b, int index, int l, int r){
		if(r <= a || b <= l){
			return invalidValue;
		}
		if(a <= l && r <= b){
			return segTree[index];
		}
		return monoidFunc(query_(a, b, index * 2, l, (l + r) / 2), query_(a, b, index * 2 + 1, (l + r) / 2, r));
	}
};

long long int func(long long int a, long long int b){
	return min(a, b);
}
SegTree segTree(func, INF);

int main(){
	segTree.init(INF);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		long long int tp, a, b;
		cin >> tp >> a >> b;
		if(tp == 0){
			segTree.change(a, b);
		}else{
			cout << segTree.query(a, b) << endl;
		}
	}
	return 0;
}