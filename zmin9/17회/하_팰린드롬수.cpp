// น้มุ 1259น๘
#include <iostream>

using namespace std;

bool solution(int input) {
	int temp = input;
	int oppo = 0;
	while (input != 0) {
		oppo = oppo * 10 + input % 10;
		input = input / 10;
	}
	return temp == oppo;
}

int main() {
	int input;
	while (true) {
		cin >> input;
		if (input == 0)
			return 0;
		cout << (solution(input) ? "yes" : "no") << endl;
	}
	return 0;
}