// O(N + M)

#include<iostream>
#include<vector>

using namespace std;

vector<int> computePrefix(string &pat) {
	int n = pat.size();
	vector<int> arr(n, 0);

	int i = 1, j = 0;

	while (i < n) {
		if (pat[i] == pat[j]) {
			arr[i] = j + 1;
			i++;j++;
		} else {
			if (j != 0) j = arr[j - 1];
			else i++;
		}
	}

	return arr;
}

int findIndex(string s, string pat) {
	int n = s.size();
	vector<int> arr = computePrefix(pat);

	int i = 0, j = 0;

	while (i < n) {
		if (s[i] == pat[j]) {
			i++;j++;
			if (j == pat.size()) return i - j;
		} else {
			if (j != 0) j = arr[j - 1];
			else i++;
		}
	}

	return -1;
}

int main() {
	cout << findIndex("abxabcabcaby", "abcaby");

	return 0;
}