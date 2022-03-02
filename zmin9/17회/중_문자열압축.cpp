// 15회 E-PPER 5번
#include <iostream>

using namespace std;

string solution(string input) {
	string answer = "";
	// 첫 문자가 1이면 가장 앞에 1을 붙여줌
	if (input[0] == '1')
		answer += '1';

	int count = 0;
	char temp;

	// 현재 인덱스와 이전 인덱스의 문자를 비교해서 같은 경우 count를 초기화하고 answer에 알파벳 추가
	// 아스키코드 이용
	for (int i = 1; i < input.size(); i++)
	{
		if (input[i - 1] != input[i]) {
			temp = count + 'A';
			answer += temp;
			count = 0;
			continue;
		}
		count++;
	}

	temp = count + 'A';
	answer += temp;

	return answer;
}


int main() {
	string input;
	cin >> input;
	cout << solution(input) << endl;
	return 0;
}