#include <iostream>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<double> gears;
	int input;
	while(cin >> input){
		gears.push_back(input);
	}

	ll ans=ceil(10000000000000 * gears[gears.size()-1] / gears[0]);
	cout << ans << '\n';
	return 0;
}
