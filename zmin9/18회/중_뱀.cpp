// ���� 3190��
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, int num_apple, vector<vector<int>>& apple, int num_rotation, vector<vector<string>>& rotation) {
	// ������ ���� 0:�ƹ��͵� ���� 1:���� ���� 2:����� ����
	vector<vector<int>> board(N, vector<int>(N, 0));
	queue<pair<int,int>> snake;

	// �� �Ӹ��� ù ��ġ �߰�
	snake.push(pair<int, int>(0, 0));


	// �� �� �� ��
	int direction[][2] = { {0,1},{-1,0},{0,-1},{1,0} };
	int cur_dir = 0;
	
	int time =0;
	int cur_rot = 0;

	for (int i = 0; i < num_apple; i++)
		board[apple[i][0] - 1][apple[i][1] - 1] = 2;
	board[0][0] = 1;

	while (true) {
		time++;
		// ���� �Ӹ��� ���� �̵��� ��ġ
		int i = snake.back().first + direction[cur_dir][0];
		int j = snake.back().second + direction[cur_dir][1];

		if (i < 0 || i == N || j < 0 || j == N)	// ���� �ε��� ���
			break;
		else if (board[i][j] == 0) {	// �� ������ ��� -> queue�� �Ӹ��� �߰��ϰ� ���� ������ �� ��(����)�� ����
			board[i][j] = 1;
			snake.push(pair<int, int>(i, j));
			auto tail = snake.front();
			board[tail.first][tail.second] = 0;
			snake.pop();
		}
		else if (board[i][j] == 1) {	// ���� ���� ���
			break;
		}
		else if (board[i][j] == 2) {	// ����� �ִ� ��� -> �Ӹ��� �߰�
			board[i][j] = 1;
			snake.push(pair<int, int>(i, j));
		}

		// X���� �̵��� ���� �� ���� �Ӹ��� ���ϴ� ����
		if (cur_rot < rotation.size() && stoi(rotation[cur_rot][0]) == time) {
			switch (rotation[cur_rot][1][0])
			{
			case 'L':
				cur_dir = (cur_dir + 1) % 4;
				break;
			case 'D':
				cur_dir = (cur_dir + 3) % 4;
				break;
			}
			cur_rot++;
		}
	}

	return time;
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