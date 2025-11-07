#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define ll long long

void split(string &input, int arr[]) {
	istringstream s(input);

	string t;
	int i=0;
	while (getline(s, t, ',')) {
		arr[i++] = stoi(t);
	}
}

// dp is current lowest packed index
// (should always be higher than highest unpacked)
int dp=0, t=0;
int pr=-1;
bool p[10000];
void solve(int boxes[]) {
	int i=0, j=0;
	bool found;

	//find first unpacked that fits
	if(p[dp]) {
		while(boxes[j++]) {
			if(p[j]) continue;
			dp=j;
			if(boxes[pr]>boxes[dp]) {
				found=true;
				break;
			}
		}
		if(!found) {
			return;
		}
	}

	// set dp to index of highest unpacked box
	while(boxes[i++]) {
		if(p[i]) continue;

		if(boxes[i]>boxes[dp]) {
			if(pr==-1)
				dp=i;
			else if(boxes[pr]>boxes[i])
				dp=i;
		}
	}

	p[dp]=true;
	pr=dp;
	t+=boxes[dp];
	solve(boxes);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	int boxes[10000];

	split(input, boxes);

	solve(boxes);

	cout << t << endl;

	/*
	 * get all possible ways to pack inside one another and store them
	 * then return the largest one, here, 29
	 * 10 > 8 > 5 > 3 > 2 > 1   the sum of the sizes: 10 + 8 + 5 + 3 + 2 + 1 = 29
	 * 10 > 8 > 5 > 2 > 1       the sum of the sizes: 10 + 8 + 5 + 2 + 1 = 26
	 * 10 > 5 > 3 > 2           the sum of the sizes: 10 + 5 + 3 + 2 = 20
	 * 10 > 5 > 2               the sum of the sizes: 10 + 5 + 2 = 17
	 *
	 * find the highest value, and mark it as packed, then iterate again
	 * and mark the highest non-packed as packed
	*/

}
