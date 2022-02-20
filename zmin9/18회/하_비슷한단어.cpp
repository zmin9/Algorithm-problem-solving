// ���� 2607��
#include <iostream>
#include <vector>

using namespace std;

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
int solution(vector<string> words) {
	int result = 0;

	// ���� �����̰ų�, �ѱ��ڸ� �߰�||����||���� �Ͽ� ���� ������ ���� �� ������ ����Ѵܾ�
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

		// 0: ���� ����, 1: �� ���ڸ� �߰��ϰų� ���� ���� ����, 2: �� ���ڸ� �ٸ� ���ڷ� �����ϸ� ���� ����(���밪�� ���߱� ������ 2)
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