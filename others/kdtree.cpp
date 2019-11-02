#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>

using namespace std;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

struct Point{
	int x, y;
	int num;
};

struct Node{
	int l, r;
	int location;
};

bool sortByX(const Point &left, const Point &right){
	return left.x < right.x;
}

bool sortByY(const Point &left, const Point &right){
	return left.y < right.y;
}

#define MAX_N 510000
#define NIL (-1)

Point P[MAX_N];
Node T[MAX_N];
int np;

int make2DTree(int l, int r, int depth){
	if(l >= r){
		return NIL;
	}
	int mid = (l + r) / 2;
	int t = np++;
	
	if(depth % 2 == 0){
		sort(P + l, P + r, sortByX);
	}else {
		sort(P + l, P + r, sortByY);
	}
	
	T[t].location = mid;
	T[t].l = make2DTree(l, mid, depth + 1);
	T[t].r = make2DTree(mid + 1, r, depth + 1);
	
	return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, vector<int> &ans){
	Point p = P[T[v].location];
	int x = p.x;
	int y = p.y;
	int num = p.num;
	
	if(sx <= x && x <= tx && sy <= y && y <= ty){
		ans.push_back(num);
	}
	
	if(depth % 2 == 0){
		if(T[v].l != NIL && sx <= x){
			find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
		}
		if(T[v].r != NIL && x <= tx){
			find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
		}
	}
	else {
		if(T[v].l != NIL && sy <= y){ 
			find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
		}
		if(T[v].r != NIL && y <= ty){
			find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
		}
	}
}

int main(){
	
	int n, q;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		scanf("%d %d", &P[i].x, &P[i].y);
		P[i].num = i;
		T[i].l = T[i].r = T[i].location = NIL;
	}
	
	np = 0;
	int root = make2DTree(0, n, 0);
	
	cin >> q;
	
	for(int i = 0; i < q; i++){
		int sx, tx, sy, ty;
		scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
		
		vector<int> ans;
		find(root, sx, tx, sy, ty, 0, ans);
		
		sort(ans.begin(), ans.end());
		
		for(int j = 0; j < ans.size(); j++){
			printf("%d\n", ans[j]);
		}
		printf("\n");
	}
	
	return 0;
}
