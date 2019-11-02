#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <iterator>

using namespace std;

int main(){
	
	long long int N, Q;
	
	cin >> N >> Q;
	
	vector<long long int> v;
	
	for(int i = 0; i < N; i++){
		long long int num;
		cin >> num;
		v.push_back(num);
	}
	
	for(int i = 0; i < Q; i++){
		long long int num;
		cin >> num;
		
		int index = distance(v.begin(), lower_bound(v.begin(), v.end(), num));
		cout << index << endl;
	}
	
	return 0;
}
