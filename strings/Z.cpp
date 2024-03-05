// https://youtu.be/CpZh4eF8QBw?si=XqB8UDoWeTwR_O4B
// Z Algorithm to check if there is a substring
// which is also a prefix of a string
#include<iostream>

using namespace std;

vector<int> ZAlgo(string s) {
	vector<int> Z(s.size(), 0);
	int left, right, k, n = s.size();
	left = right = 0;

	for (k = 1; k < n; k++) {
		if (k > right) {
			// There is no Z box yet
			left = right = k;
			while (right < n && s[right] == s[right - left]) right++;
			Z[k] = right - left;
			right--;
		} else {
			// We are operating in Z box
			int k1 = k - left;

			// Check if Z value is not touching right boundary
			if (Z[k1] < right - k + 1) Z[k] = Z[k1];
			else {
				// Check for prefix again and increase window
				left = k;
				while (right < n && s[right] == s[right - left]) right++;
				Z[k] = right - left;
				right--;
			}
		}
	}

	return Z;
}


int main() {
	string s = "ababa";

	vector<int> Z = ZAlgo(s);

	for (auto x : Z) cout << x << " ";
	cout << "\n";

	return 0;
}