#include <iostream>
#include <cstdio>

using namespace std;

long long int INF = 1e18;

#define MAX_V 1000

long long int d[MAX_V][MAX_V];

void warshall_floyd(int n){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main(){
	
	int N = 3;
	
	// 対角成分が 0 であることは、保証しなくても大丈夫
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			d[i][j] = INF;
		}
	}
	
	d[0][1] = min(d[0][1], 4);
	d[0][2] = 5;
	d[2][0] = 8;
	d[1][2] = 2;
	
	warshall_floyd(N);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
