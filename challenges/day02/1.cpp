#include <iostream>
#include <sstream>
#include <string>

#define ll long long

using namespace std;

void split(string &input, int (&arr)[2]) {
	string s = input.substr(input.find('[') + 1, input.find(']') - 1);
	istringstream stream(s);

	string t;
	int i=0;
	while (getline(stream, t, ',')) {
		arr[i++] = stoi(t);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	int c[2];

	split(input, c);

	int res[2] = {0, 0};
	int t = 3;

	while(t--) {
		int k1;
		int k2;
		// multiply
		k1 = res[0] * res[0] - res[1] * res[1];
		k2 = res[0] * res[1] + res[1] * res[0];
		res[0]=k1;
		res[1]=k2;

		// divide by [10, 10]
		k1 = res[0]/10;
		k2 = res[1]/10;
		res[0]=k1;
		res[1]=k2;

		// add A
		k1 = res[0]+c[0];
		k2 = res[1]+c[1];
		res[0]=k1;
		res[1]=k2;
	}

	cout << '[' << res[0] << ',' << res[1] << ']' << endl;
}
