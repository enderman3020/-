#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int main(){
	
	long long int DP[10][300];
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 300; j++){
			DP[i][j] = 0;
		}
	}
	
	DP[0][0] = 1;
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 300; j++){
			long long int sum = 0;
			for(int k = j; k >= 0; k -= coin[i]){
				sum += DP[i][k];
			}
			DP[i + 1][j] = sum;
		}
	}
	
	cout << DP[8][200] << endl;
	
	return 0;
}

