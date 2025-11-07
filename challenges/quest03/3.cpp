#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void split(string &input, vector<int> &arr) {
	istringstream s(input);

	string t;
	while (getline(s, t, ',')) {
		arr.push_back(stoi(t));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	vector<int> boxes;

	split(input, boxes);

	int m=0;
	for(int num : boxes) {
		int cnt = count(boxes.begin(), boxes.end(), num);
		if(cnt>m)
			m = cnt;
	}

	cout << m << '\n';

	return 0;
}
