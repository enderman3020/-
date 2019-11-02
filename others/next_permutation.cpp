#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define DATA_SIZE 4

int main(){
	int a[DATA_SIZE];
	while(true){
		
		bool flag = true;
		
		for(int i = 0; i < DATA_SIZE; i++){
			cin >> a[i];
			if(a[i] != 0){
				flag = false;
			}
		}
		if(flag){
			break;
		}
		
		sort(a, a + DATA_SIZE); // è∏èáÇ…É\Å[Ég
		
		do{
			for(int i = 0; i < DATA_SIZE; i++){
				cout << a[i];
			}
			cout << endl;
		}while(next_permutation(a, a + DATA_SIZE));
	}
	
	return 0;
}

