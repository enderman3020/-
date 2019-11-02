#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string num_1[20] = {
	"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string num_10[10] = {
	"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string and_str = "and";
string hundred = "hundred";
string thousand = "thousand";

int main(){
	
	int ans = 0;
	
	for(int i = 1; i <= 999; i++){
		if(i >= 100){
			cout << num_1[i / 100] << " " << hundred << " ";
			ans += num_1[i / 100].size() + hundred.size();
			if(i % 100 != 0){
				cout << and_str << " ";
				ans += and_str.size();
			}
		}
		int und = i % 100;
		if(und < 20){
			cout << num_1[und] << " ";
			ans += num_1[und].size();
		}else{
			cout << num_10[und / 10] << " " << num_1[und % 10] << " ";
			ans += num_10[und / 10].size() + num_1[und % 10].size();
		}
		cout << endl;
	}
	
	cout << num_1[1] << " " << thousand << endl;
	ans += num_1[1].size() + thousand.size();
	
	cout << ans << endl;
	
	return 0;
}

