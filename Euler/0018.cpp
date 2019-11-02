#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
	
	ifstream fs("0018.txt");
	int a[15][15];
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			a[i][j] = 0;
		}
	}
	
	for(int i = 0; i < 15; i++){
		for(int j = 0; j <= i; j++){
			fs >> a[i][j];
		}
	}
	
	for(int i = 13; i >= 0; i--){
		for(int j = 0; j <= i; j++){
			a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
		}
	}
	
	cout << a[0][0] << endl;
	
	return 0;
}

