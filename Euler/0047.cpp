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
	
	int count2 = 0;
	
	for(int i = 2; i < 1000000; i++){
		int num = i;
		int count = 0;
		for(int j = 2; j <= i; j++){
			bool flag = false;
			while(a[j] && num % j == 0){
				num /= j;
				flag = true;
			}
			if(flag){
				count++;
			}
			if(num == 1){
				break;
			}
		}
		if(count == 4){
			count2++;
		}else{
			count2 = 0;
		}
		if(count2 == 4){
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}

