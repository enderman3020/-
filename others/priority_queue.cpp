#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

// �v�f�̒ǉ���O(logN)�ł���A�v�f�����o���Ƃ���O(1)�ƂȂ�

int main(){
	
	priority_queue<int> pque;
	// priority_queue<int, vector<int>, greater<int> > pque �̂Ƃ��A
	// ���������Ɏ��o�����
	
	pque.push(3);
	pque.push(5);
	pque.push(1);
	
	while(!pque.empty()){
		printf("%d\n", pque.top());
		pque.pop();
	}
	
	return 0;
}
