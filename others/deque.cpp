#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

typedef pair<long long int, bool> P;

// deque<P> v; のとき、
// v.push_back(), v.push_front(), v.pop_back(), v.pop_front() が使える。O(1)。
// v.size(), v[index] も可能。O(1)。

int main(){
	
	while(true){
		long long int n, m, p, q, r;
		cin >> n;
		if(n == 0){
			break;
		}
		cin >> m >> p >> q >> r;
		deque<P> v;
		P pp;
		pp.first = r;
		pp.second = true;
		v.push_back(pp);
		pp.first = n - r;
		pp.second = false;
		v.push_back(pp);
		
		for(int i = 0; i < m; i++){
			
			int x, y;
			cin >> x >> y;
			y = n - y;
			
			deque<P> v1, v2;
			
			while(true){
				x -= v[0].first;
				if(x <= 0){
					P p2;
					p2.first = v[0].first + x;
					p2.second = v[0].second;
					v1.push_back(p2);
					v[0].first = -x;
					break;
				}
				v1.push_back(v[0]);
				v.pop_front();
			}
			
			while(true){
				int sz = v.size();
				y -= v[sz - 1].first;
				if(y <= 0){
					P p2;
					p2.first = v[sz - 1].first + y;
					p2.second = v[sz - 1].second;
					v2.push_back(p2);
					v[sz - 1].first = -y;
					break;
				}
				v2.push_back(v[sz - 1]);
				v.pop_back();
			}
			
			for(int i = 0; i < v1.size(); i++){
				v.push_back(v1[i]);
			}
			
			for(int i = 0; i < v2.size(); i++){
				v.push_front(v2[i]);
			}
		}
		
		long long int ans = 0;
		
		for(int i = 0; i < v.size(); i++){
			q -= v[i].first;
			if(q <= 0){
				if(v[i].second){
					ans += v[i].first + q;
				}
				break;
			}
			if(v[i].second){
				ans += v[i].first;
			}
		}
		
		p--;
		for(int i = 0; i < v.size(); i++){
			p -= v[i].first;
			if(p <= 0){
				if(v[i].second){
					ans -= v[i].first + p;
				}
				break;
			}
			if(v[i].second){
				ans -= v[i].first;
			}
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
}