#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

// 要素の追加がO(logN)であり、要素を取り出すときはO(1)となる

int main(){
	
	priority_queue<int> pque;
	// priority_queue<int, vector<int>, greater<int> > pque のとき、
	// 小さい順に取り出される
	
	pque.push(3);
	pque.push(5);
	pque.push(1);
	
	while(!pque.empty()){
		printf("%d\n", pque.top());
		pque.pop();
	}
	
	return 0;
}
