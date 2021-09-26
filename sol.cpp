#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	vector<vector<char>> s(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> s[i][j];
		}
	}
	// to get an answer of "No", then check if at least one sheep is adjacent to a wolf
	bool checker = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (s[i][j] == 'S') {
				if (i - 1 >= 0) {
					checker |= (s[i - 1][j] == 'W');
				}
				if (i + 1 < r) {
					checker |= (s[i + 1][j] == 'W');
				}
				if (j - 1 >= 0) {
					checker |= (s[i][j - 1] == 'W');
				}
				if (j + 1 < c) {
					checker |= (s[i][j + 1] == 'W');
				}
			}
			if (checker) {
				break;
			}
		}
		if (checker) {
			break;
		}
	}
	if (checker) {
		cout << "No" << '\n';
		return 0;
	}
	// otherwise, output "Yes" and fill all the empty cells with 'D' (dog)
	cout << "Yes" << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (s[i][j] == '.') {
				cout << 'D';
			} else {
				cout << s[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}
