#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	
	int N = 100000;
	
	bool a[100000];
	
	for(int i = 0; i < N; i++){
		a[i] = true;
	}
	
	a[0] = false;
	a[1] = false;
	
	for(int i = 2; i < N; i++){
		if(a[i]){
			for(int j = i * 2; j < N; j += i){
				a[j] = false;
			}
		}
	}
	
	for(int i = 0; i < 100; i++){
		if(a[i]){
			printf("%d ", i);
		}
	}
	
	return 0;
}
