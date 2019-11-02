#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
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

typedef vector<long long int> vec;
typedef vector<vec> mat;
// A[i][j] は、i 行 j 列を意味する

long long int M; // 行列演算で余りを取るときの法

// A*B 
mat mul(mat &A, mat &B){
	mat C(A.size(), vec(B[0].size()));
	for(int i = 0; i < A.size(); i++){
		for(int k = 0; k < B.size(); k++){
			for(int j = 0; j < B[0].size(); j++){
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return C;
}

// A^n 
mat pow(mat A, long long int n){
	mat B(A.size(), vec(A.size()));
	for(int i = 0; i < A.size(); i++){
		B[i][i] = 1;
	}
	while(n > 0){
		if(n & 1){
			B = mul(B, A);
		}
		A = mul(A, A);
		n /= 2;
	}
	return B;
}

int main(){
	
	while(true){
		long long int n, a, b, c, T;
		cin >> n >> M >> a >> b >> c >> T;
		
		if(n == 0){
			break;
		}
		
		mat S(n + 2, vec(1));
		
		for(int i = 0; i < n; i++){
			cin >> S[i + 1][0];
		}
		
		mat P(n + 2, vec(n + 2));
		
		for(int i = 0; i < n; i++){
			P[i + 1][i] = a;
			P[i + 1][i + 1] = b;
			P[i + 1][i + 2] = c;
		}
		
		// ans = (P^T)S
		
		P = pow(P, T);
		
		mat ans = mul(P, S);
		
		for(int i = 1; i <= n; i++){
			printf("%d%c", ans[i][0], (i == n) ? '\n' : ' ');
		}
	}
	
	return 0;
}