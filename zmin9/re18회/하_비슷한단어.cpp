// ���� 2607��
#include <iostream>
#include <vector>

using namespace std;

// ������ �����ϰ� ������ ��Ȯ�� ������ �� �־����

// ���ĺ��� �빮�ڷθ� �־����Ƿ� ���ĺ��� �ε����� ����� �� ����
// �� �������� �ش� �ܾ ���ĺ��� �� ���� ����ִ��� ��
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
		/*�� ���ĺ��� ���� ���� ���� ������ ���Ѵ�
		* �� ���ĺ��� ������ ���� ��� = ������ ������ŭ ����
		* �� ���ĺ��� ������ �ϳ� ���� ���� ��� = �ش� ���ڰ� �� �� �������ų� ������
		* �� ���ĺ��� ������ �� �� �̻� ���� ���� ��� = �ٸ� �ܾ�
		*/
		for (int j = 0; j < 26; j++)
			count += abs(first_words[j] - cur_words[j]);

		/*���̸� ��� ���� ���� �������� ��
		* 0 - 1 �� ��� : ���� ���� ���� ���ų� �� ���ڰ� �߰�/���� �� ���
		* 2�� ��� : �� ���ڴ� ��������, �� ���ڴ� ���ܵ� ��� --> �ܾ��� �� ���̴� ���ƾ���
		* �� �̻� : �ٸ� �ܾ�
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