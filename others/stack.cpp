#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
	
	stack<int> sta;
	
	sta.push(3);
	sta.push(5);
	sta.push(1);
	
	while(!sta.empty()){
		printf("%d\n", sta.top());
		sta.pop();
	}
	
	return 0;
}
