#include <iostream>
#include <string>

#define ll long long

using namespace std;

void split(string &input, int &x, int &y) {
	sscanf(input.c_str() + input.find('[')+1, "%d,%d", &x, &y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	int a[2];
	split(input, a[0], a[1]);

	constexpr int size = 1001;
	int cnt = size*size;

	#pragma omp parallel for reduction(-:cnt) collapse(2)
	for(int i=0; i<size; i++) {
		for(int j=0; j<size;j++) {
			int p[2] = {a[0]+j, a[1]+i};
			ll k[2] = {0, 0};
			int t = 100;
			while(t--) {
				// multiply by itself
				ll k1 = k[0] * k[0] - k[1] * k[1];
				ll k2 = k[0] * k[1] + k[1] * k[0];

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
