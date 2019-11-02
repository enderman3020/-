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
	
	int sum = 0;
	int count = 0;
	
	for(int i = 2; i < N; i++){
		if(a[i]){
			count++;
			sum += i;
		}
		if(sum > 1000000){
			sum -= i;
			count--;
			break;
		}
	}
	
	int piyo = 0;
	int sum2 = 0;
	
	for(int i = 7; i < N; i++){
		if(a[i]){
			piyo++;
			sum2 += i;
		}
		if(piyo == 543){
			cout << sum2 << endl;
			break;
		}
	}
	
	bool flag = false;
	
	int counter = 0;
	
	for(int i = count; i > 0; i--){
		int start = 0;
		int final;
		sum = 0;
		counter = 0;
		for(int j = 0; j < 1000000; j++){
			if(a[j]){
				sum += j;
				counter++;
			}
			if(counter == i){
				final = j;
				break;
			}
		}
		while(true){
			if(sum > 1000000){
				break;
			}
			cout << start << " " << final << endl;
			cout << sum << endl;
			if(a[sum]){
				flag = true;
				break;
			}
			while(true){
				start++;
				if(a[start]){
					break;
				}
			}
			while(true){
				final++;
				if(a[final]){
					break;
				}
			}
			sum -= start;
			sum += final;
			cout << start << " " << final << endl;
		}
		if(flag){
			cout << sum << " " << i << endl;
			break;
		}
	}
	
	return 0;
}

