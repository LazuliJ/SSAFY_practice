#include <iostream>
#include <string>

using namespace std;

int main() {
	string wrong;
	string ans;
	cin >> wrong;

	wrong += "0";
	if (wrong.length() != 1) {
		for (int i = 1; i < wrong.length(); i++) {
			if (wrong[i - 1] != wrong[i]) ans += wrong[i - 1];
		}
	}
	else ans = wrong;

	cout << ans;
}
