#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int count = 1;
	
	do{
		if(count == 1000000){
			break;
		}
		count++;
	}while(next_permutation(a, a + 10));
	
	for(int i = 0; i < 10; i++){
		cout << a[i];
	}
	cout << endl;
	
	return 0;
}

