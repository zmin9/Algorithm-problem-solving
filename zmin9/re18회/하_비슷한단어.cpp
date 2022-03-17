// 백준 2607번
#include <iostream>
#include <vector>

using namespace std;

// 문제를 이해하고 조건을 명확히 정리할 수 있어야함

// 알파벳이 대문자로만 주어지므로 알파벳을 인덱스로 고려할 수 있음
// 을 바탕으로 해당 단어에 알파벳이 몇 개씩 들어있는지 셈
void count_alphabet(string words, vector<int>& count) {
	for (int i = 0; i < words.size(); i++)
		count[words[i] - 'A']++;
}

int solution(int n, vector<string> words) {
	int answer = 0;

	vector<int> first_words(26, 0);

	count_alphabet(words[0], first_words);

	for (int i = 1; i < n; i++) {
		vector<int> cur_words(26, 0);
		count_alphabet(words[i], cur_words);

		int count = 0;
		/*각 알파벳에 대해 갯수 차이 총합을 구한다
		* 한 알파벳의 갯수가 같은 경우 = 동일한 갯수만큼 있음
		* 한 알파벳의 갯수가 하나 차이 나는 경우 = 해당 문자가 한 번 더해졌거나 빠졌음
		* 한 알파벳의 갯수가 두 개 이상 차이 나는 경우 = 다른 단어
		*/
		for (int j = 0; j < 26; j++)
			count += abs(first_words[j] - cur_words[j]);

		/*차이를 모두 더한 값을 생각했을 때
		* 0 - 1 인 경우 : 위와 같이 완전 같거나 한 문자가 추가/제외 된 경우
		* 2인 경우 : 한 문자는 더해졌고, 한 문자는 제외된 경우 --> 단어의 총 길이는 같아야함
		* 그 이상 : 다른 단어
		*/
		if (count == 0 || count == 1 || (count == 2 && words[0].size() == words[i].size()))
			answer++;
	}

	return answer;
}

int main() {
	int n;
	cin >> n;

	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	int answer = solution(n, words);
	cout << answer;
	return 0;
}