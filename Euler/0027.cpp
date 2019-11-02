#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime[1000000];

int main(){
	
	int N = 1000000;
	
	for(int i = 0; i < N; i++){
		is_prime[i] = true;
	}
	
	is_prime[0] = false;
	is_prime[1] = false;
	
	for(int i = 2; i < N; i++){
		if(is_prime[i]){
			for(int j = i * 2; j < N; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	int max = 0;
	int max_a = 0;
	int max_b = 0;
	
	for(int a = -1000; a <= 1000; a++){
		for(int b = 1; b <= 1000; b++){
			for(int n = 0; n <= 100; n++){
				int num = n * n + a * n + b;
				if(num < 0 || !is_prime[num]){
					if(max < n){
						max = n;
						max_a = a;
						max_b = b;
					}
					break;
				}
			}
		}
	}
	
	cout << max_a << " " << max_b << endl;
	
	int a = -61;
	int b = 971;
	
	/*
	for(int i = 0; i < 100; i++){
		int num = i * i + a * i + b;
		cout << num << " ";
		if(is_prime[num]){
			cout << "prime" << endl;
		}else{
			cout << "not_prime" << endl;
		}
	}
	*/
	
	return 0;
}

