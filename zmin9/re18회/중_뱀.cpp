// ���� 3190��
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, int K, vector<vector<int>>& apple, int L, vector<vector<string>>& rotation) {
	vector<vector<int>> board(N, vector<int>(N, 0));
	// �ƹ��͵� ����:0, ���� �����ϴ� ĭ:1, ����� �����ϴ� ĭ:2
	// ��� ��ġ ǥ��
	// �������� �־����� ���� �� ������ 1,1 �� �����ϴ� ��ġ�̱� ������ ���� ���� �����Ϸ��� -1�� ���ִ� ���� ������ �ȵȴ�
	for (int i = 0; i < K; i++)
		board[apple[i][0] - 1][apple[i][1] - 1] = 2;

	// ���� ���� ��ġ ǥ��
	board[0][0] = 1;
	queue<pair<int, int>> snake;
	snake.push(pair<int, int>(0, 0));

	int timer = 0;
	// ���� ����
	int d_idx = 0;
	// ���� ������ ȸ�� ����
	int r_idx = 0;

	// D(�ð����)�� �ε���+1, L(�ݽð����)�� �ε���-1
	int d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	while (true) {
		timer++;
		int next_i = snake.back().first + d[d_idx][0];
		int next_j = snake.back().second + d[d_idx][1];

		// board�� ����� ���
		if (next_i >= N || next_j >= N || next_i < 0 || next_j < 0)
			break;

		// ���� ���� �ִ� �ڸ����
		if (board[next_i][next_j] == 1)
			break;

		// ���� ��ĭ�̶�� (����� ���ٸ�) ����ĭ�� �����
		if (board[next_i][next_j] == 0) {
			board[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}

		// �Ӹ� �̵�
		snake.push(pair<int, int>(next_i, next_j));
		board[next_i][next_j] = 1;

		// ���� ��ȯ
		// �̵��� ���� �� ������ ��ȯ
		if (r_idx < L && stoi(rotation[r_idx][0]) == timer) {
			if (rotation[r_idx][1] == "D")
				d_idx = (d_idx + 1) % 4;
			else
				d_idx = (d_idx + 3) % 4;
			r_idx++;
		}

	}
	return timer;
}

int main() {
	int N, K, L;
	cin >> N >> K;
	vector<vector<int>> apple(K, vector<int>(2));
	for (int i = 0; i < K; i++)
		cin >> apple[i][0] >> apple[i][1];
	cin >> L;
	vector<vector<string>> rotation(L, vector<string>(2));
	for (int i = 0; i < L; i++)
		cin >> rotation[i][0] >> rotation[i][1];

	cout << solution(N, K, apple, L, rotation);
}