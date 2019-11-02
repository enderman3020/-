#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	for(int i = 1; i <= 1000; i++){
		for(int j = i; j <= 1000; j++){
			int k = 1000 - i - j;
			if(i * i + j * j == k * k){
				cout << i << " " << j << " " << k;
			}
		}
	}
	
	return 0;
}

