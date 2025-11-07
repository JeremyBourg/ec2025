#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<double> g;
	int input;
	while(cin >> input){
		g.push_back(input);
	}

	double t=1;
	for(int i=1;i<g.size();i++){
		double mul=g[i-1]/g[i];
		t*=mul;
	}

	int r=t*2025;

	cout << r << '\n';
	return 0;
}
