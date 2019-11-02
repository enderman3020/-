#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long int tri[100000];
long long int pen[100000];
long long int hxa[100000];

int main(){
	
	for(int i = 1; i <= 10000; i++){
		tri[i - 1] = i * (i + 1) / 2;
		pen[i - 1] = i * (3 * i - 1) / 2;
		hxa[i - 1] = i * (2 * i + 1);
	}
	
	for(int i = 0; i < 10000; i++){
		for(int j = i + 1; j < 10000; j++){
			bool flag1 = binary_search_(0, 9999, pent[i] + pent[j]);
			bool flag2 = binary_search_(0, 9999, pent[j] - pent[i]);
			if(flag1 && flag2){
				if(min > pent[j] - pent[i]){
					cout << "find" << endl;
					min = pent[j] - pent[i];
					ans1 = pent[i];
					ans2 = pent[j];
				}
			}
		}
	}
	
	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}

