#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>

long long int INF = 1e18;
using namespace std;

typedef pair<long long int, long long int> P;

int main(){
	
	int n;
	cin >> n;
	
	list<int> lst;
	std::list<int>::iterator itr;
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		if(str[0] == 'i'){
			int num;
			cin >> num;
			lst.push_front(num);
		}else if(str[6] == 'F'){
			lst.pop_front();
		}else if(str[6] == 'L'){
			lst.pop_back();
		}else{
			int num;
			cin >> num;
			for(itr = lst.begin(); itr != lst.end(); ){
				if(*itr == num){
					itr = lst.erase(itr);
				}else{
					itr++;
				}
			}
		}
	}
	
	itr = lst.begin();
	
	if(lst.begin() != lst.end()){
		cout << *itr;
		itr++;
	}
	
	for(; itr != lst.end(); itr++){
		cout << " " << *itr;
	}
	cout << endl;
	
	return 0;
}