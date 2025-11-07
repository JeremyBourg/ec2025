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
	int t=0;

	split(input, boxes);

	sort(boxes.begin(), boxes.end(), greater<int>());
	boxes.erase(unique(boxes.begin(), boxes.end()), boxes.end());
	for(int i=0; i<20; i++) {
		t+=boxes.back();
		boxes.pop_back();
	}
	cout << t << '\n';

	return 0;
}
