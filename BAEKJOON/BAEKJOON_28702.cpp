#include <iostream>
#include <string>

using namespace std;

// 백준 28702번 FizzBuzz

int main() {
	int ans;
	for (int i = 3; i >= 1; i--) {
		string inp;
		cin >> inp;
		if ('0' <= inp[0] and '9' >= inp[0]) {
			ans = stoi(inp) + i;
		}
	}
	if (ans % 3 == 0 and ans % 5 == 0) cout << "FizzBuzz" << "\n";
	else if (ans % 3 == 0) cout << "Fizz" << "\n";
	else if (ans % 5 == 0) cout << "Buzz" << "\n";
	else cout << ans << "\n";
}
