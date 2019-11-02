#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	int count[3001];
	
	for(int i = 0; i < 3001; i++){
		count[i] = 0;
	}
	
	for(int i = 1; i <= 1000; i++){
		for(int j = i + 1; j <= 1000; j++){
			for(int k = j + 1; k <= 1000; k++){
				if(i * i + j * j == k * k){
					count[i + j + k]++;
				}
			}
		}
	}
	
	int ans = 0;
	int max = 0;
	
	for(int i = 1; i < 1000; i++){
		if(max < count[i]){
			max = count[i];
			ans = i;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

