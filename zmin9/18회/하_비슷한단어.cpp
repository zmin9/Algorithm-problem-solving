// 백준 2607번
#include <iostream>
#include <vector>

using namespace std;

// solution 함수로 return값 낼 수 있도록 작성
int solution(vector<string> words) {
	int result = 0;

	// 같은 구성이거나, 한글자를 추가||제외||변경 하여 같은 구성을 만들 수 있으면 비슷한단어
	vector<int>alphabet (26, 0);
	
	for (int i = 0; i < words[0].size(); i++)
		alphabet[words[0][i] - 'A']++;

	for (int i = 1; i < words.size(); i++) {
		vector<int>temp(26, 0);

		for (int j = 0; j < words[i].size(); j++)
			temp[words[i][j] - 'A']++;

		int count = 0;

		for (int j = 0; j < 26; j++)
			count += abs(alphabet[j] - temp[j]);

		// 0: 같은 구성, 1: 한 글자를 추가하거나 빼면 같은 구성, 2: 한 글자를 다른 글자로 변경하면 같은 구성(절대값을 더했기 때문에 2)
		if (count == 0 || count == 1 || (count == 2 && words[0].size() == words[i].size()))
			result++;
	}
	return result;
}

int main() {
	int T;
	cin >> T;

	vector<string> words(T);

	for (int i = 0; i < T; i++)
		cin >> words[i];

	cout << solution(words) << endl;
}