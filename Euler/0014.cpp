#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	int ans = 0;
	int max_step = 0;
	
	for(int i = 1; i <= 1000000; i++){
		if(i % 1000 == 0){
			cout << i << endl;
		}
		long long int hoge = i;
		int count = 0;
		while(hoge != 1){
			count++;
			if(hoge % 2 == 0){
				hoge /= 2;
			}else{
				hoge = 3 * hoge + 1;
			}
		}
		if(count > max_step){
			max_step = count;
			ans = i;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

