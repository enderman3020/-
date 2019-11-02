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
long long int MOD = 1e9 + 7;

const double EPS = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;

// 計算量は O(|b|^3)
// Ax = b を解く A は正方行列
// 解がないか、一意でない場合は長さ０の配列を返す
vec gauss_jordan(const mat& A, const vec& b){
	int n = A.size();
	mat B(n, vec(n + 1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			B[i][j] = A[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		B[i][n] = b[i];
	}
	// 掃き出し法
	for(int i = 0; i < n; i++){
		// 注目している変数の係数の絶対値が大きい式をｉ番目に持ってくる
		int pos = i;
		for(int j = i; j < n; j++){
			if(abs(B[j][i]) > abs(B[pos][i])){
				pos = j;
			}
		}
		swap(B[i], B[pos]);

		// 解がないか、一意でない
		if(abs(B[i][i]) < EPS){
			return vec();
		}

		// 注目している変数の係数を１にする
		for(int j = i + 1; j <= n; j++){
			B[i][j] /= B[i][i];
		}
		for(int j = 0; j < n; j++){
			if(i != j){
				// ｊ番目の式からｉ番目の変数を消去
				for(int k = i + 1; k <= n; k++){
					B[j][k] -= B[j][i] * B[i][k];
				}
			}
		}
	}
	vec x(n);
	// 後ろに並べたｂが解になる
	for(int i = 0; i < n; i++){
		x[i] = B[i][n];
	}
	return x;
}

int main(){

	return 0;
}