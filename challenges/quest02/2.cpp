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
	int a[2];
	int o[2];

	split(input, a);

	int size = 101;
	int cnt = size*size;

	int inc=1000/(size-1);

	for(int i=0; i<size; i++) {
		for(int j=0; j<size;j++) {
			int p[2] = {a[0]+j*inc, a[1]+i*inc};
			ll k[2] = {0, 0};
			int t = 100;
			while(t--) {
				// multiply by itself
				ll k1 = k[0] * k[0] - k[1] * k[1];
				ll k2 = 2 * k[0] * k[1];

				// divide by [100000, 100000]
				k1/=100000;
				k2/=100000;

				// add P
				k1+=p[0];
				k2+=p[1];

				k[0] = k1;
				k[1] = k2;

				if(abs(k[0]) > 1000000|| abs(k[1]) > 1000000) {
					cnt--;
					break;
				}
			}
		}
	}

	cout << cnt << endl;
}
