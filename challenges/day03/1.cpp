#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define ll long long

void split(string &input, int arr[]) {
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
	int nums[10000];

	split(input, nums);

	/*
	 * get all possible ways to pack inside one another and store them
	 * then return the largest one, here, 29
	 * 10 > 8 > 5 > 3 > 2 > 1   the sum of the sizes: 10 + 8 + 5 + 3 + 2 + 1 = 29
	 * 10 > 8 > 5 > 2 > 1       the sum of the sizes: 10 + 8 + 5 + 2 + 1 = 26
	 * 10 > 5 > 3 > 2           the sum of the sizes: 10 + 5 + 3 + 2 = 20
	 * 10 > 5 > 2               the sum of the sizes: 10 + 5 + 2 = 17
	 *
	 * so, i need a max heap (tree), and dfs my way to the largest answer
	*/

}
