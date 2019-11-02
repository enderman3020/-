#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool flag[10000];

int main(){
	
	for(int i = 0; i < 10000; i++){
		flag[i] = false;
	}
	
	int ans = 0;
	int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	do{
		for(int j = 0; j < 8; j++){
			for(int k = j + 1; k < 8; k++){
				int index = 0;
				int a = 0;
				int b = 0;
				int c = 0;
				for(int i = index; i < 9; i++){
					a *= 10;
					a += num[i];
					if(i == j){
						index = i + 1;
						break;
					}
				}
				for(int i = index; i < 9; i++){
					b *= 10;
					b += num[i];
					if(i == k){
						index = i + 1;
						break;
					}
				}
				for(int i = index; i < 9; i++){
					c *= 10;
					c += num[i];
				}
				if(a * b == c){
					cout << a << " " << b << " " << c << endl;
					if(!flag[c]){
						flag[c] = true;
						ans += c;
					}
				}
			}
		}
	}while(next_permutation(num, num + 9));
	
	cout << ans << endl;
	
	return 0;
}

