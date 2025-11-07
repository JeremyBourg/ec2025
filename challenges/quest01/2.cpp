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

	int pos=0;
	for(int i=0; i<icnt; i++) {
		char dir=insts[i][0];
		int steps=stoi(insts[i].substr(1));

		if(dir=='R') {
			pos+=steps;
		}
		else {
			pos-=steps;

		}
		pos=pos%ncnt;
		if(pos<0)
			pos=ncnt+pos;
	}

	cout << names[pos] << endl;

	return 0;
}
