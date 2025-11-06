#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define ll long long

void split(string &input, string arr[], int& cnt){
	istringstream stream(input);

	string token;

	while (getline(stream, token, ',')) {
		arr[cnt++] = token;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string nameline, instline;
	string names[100000];
	string insts[100000];
	cin >> nameline;
	cin >> instline;

	int ncnt=0;
	int icnt=0;

	split(nameline, names, ncnt);
	split(instline, insts, icnt);

	for(int i=0; i<icnt; ++i) {
		char dir=insts[i][0];
		int pos=stoi(insts[i].substr(1));
		string t;

		pos=pos%ncnt;
		if(!pos) {
			continue;
		}

		if(dir=='R') {
			t=names[pos];
			names[pos] = names[0];
		}
		else {
			t=names[ncnt-pos];
			names[ncnt-pos] = names[0];
		}

		names[0] = t;
	}

	cout << names[0] << endl;

	return 0;
}
