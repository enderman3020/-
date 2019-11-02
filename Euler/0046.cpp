#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int N = 1000000;

bool a[1000000];
bool check[1000000];

int main(){
	
	
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
	
	for(int i = 1; i < 1000000; i++){
		check[i] = false;
	}
	
	for(int i = 1; i < 1000000; i += 2){
		if(!a[i]){
			continue;
		}
		for(int j = 0; j < 10000; j++){
			if(i + 2 * j * j >= 1000000){
				break;
			}
			check[i + 2 * j * j] = true;
		}
	}
	
	for(int i = 1; i < 1000000; i += 2){
		if(!check[i]){
			cout << i << endl;
		}
	}
	
	return 0;
}

