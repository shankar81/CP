#include<iostream>

using namespace std;

long long myHash(int c) {
	return (long long) pow(c, 2);
}

void rabin_karp(string &s, string &sub) {
	int n = s.size(), m = sub.size(), matched = 1, i = 0;
	long long rollingHash = 0, subHash = 0;

	for (i = 0; i < m; i++) {
		rollingHash += myHash(s[i]);
		subHash += myHash(sub[i]);
		if (s[i] != sub[i]) matched = 0;
	}

	if (matched) cout << 0 << " ";

	for (; i < n; i++) {
		rollingHash += myHash(s[i]);
		rollingHash -= myHash(s[i - m]);
		if (rollingHash == subHash) {
			int start = i, j = m - 1;
			matched = 1;
			while (j >= 0) {
				if (s[start] != sub[j]) {
					matched = 0;
					break;
				}
				start--;
				j--;
			}

			if (matched) cout << (start + 1) << " ";
		}
	}
}

int main() {
	string s = "abcdabcdabcd";
	string find = "abc";

	rabin_karp(s, find);
	return 0;
}