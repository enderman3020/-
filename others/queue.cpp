#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
	
	queue<int> qu;
	
	qu.push(3);
	qu.push(5);
	qu.push(1);
	
	while(!qu.empty()){
		printf("%d\n", qu.front());
		qu.pop();
	}
	
	return 0;
}
