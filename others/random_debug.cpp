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

long long int a[210000];

// 配列 a にランダムな値を代入するプログラム

int main(){
	
	while(1){
		
		int N;
		N = 20;
		
		for(int i = 0; i < N; i++){
			a[i] = rand() % 100 + 1;
		}
		
		/* 処理 */
		
		// 合っていない場合、デバッグ出力すると良い
		
	}
	return 0;
}