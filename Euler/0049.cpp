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
	
	int count[10], count2[10], count3[10];
	
	
	for(int i = 1000; i < 10000; i++){
		if(!a[i]){
			continue;
		}
		int num = i;
		for(int loop = 0; loop < 10; loop++){
			count[loop] = 0;
		}
		for(int loop = 0; loop < 4; loop++){
			count[num % 10]++;
			num /= 10;
		}
		for(int j = 1; j < 10000; j++){
			if(i + 2 * j >= 10000){
				break;
			}
			if(!a[i + j] || !a[i + j * 2]){
				continue;
			}
			int num1 = i + j;
			for(int k = 0; k < 10; k++){
				count2[k] = 0;
			}
			for(int loop = 0; loop < 4; loop++){
				count2[num1 % 10]++;
				num1 /= 10;
			}
			bool flag = true;
			for(int loop = 0; loop < 10; loop++){
				if(count[loop] != count2[loop]){
					flag = false;
					break;
				}
			}
			if(!flag){
				continue;
			}
			int num2 = i + 2 * j;
			for(int k = 0; k < 10; k++){
				count2[k] = 0;
			}
			for(int loop = 0; loop < 4; loop++){
				count2[num2 % 10]++;
				num2 /= 10;
			}
			flag = true;
			for(int loop = 0; loop < 10; loop++){
				if(count[loop] != count2[loop]){
					flag = false;
					break;
				}
			}
			if(!flag){
				continue;
			}
			cout << i << " " << i + j << " " << i + 2 * j << endl;
		}
	}
	
	return 0;
}

