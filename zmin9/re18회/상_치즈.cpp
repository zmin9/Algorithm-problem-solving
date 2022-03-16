// ���� 2638��
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �� �� �� ��
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

// �ܺΰ��� ǥ�ÿ� �̿��� DFS
void dfs(int row, int col, vector<vector<int>> &board) {
	// ���� ������� �ƴ϶�� == ġ� �ִٸ� Ž��X
	if (board[row][col] != 0)
		return;

	board[row][col] = -1;

	for (int i = 0; i < 4; i++)
		if (row + di[i] >= 0 && row + di[i] < board.size() && col + dj[i] >= 0 && col + dj[i] < board[0].size())
			dfs(row + di[i], col + dj[i], board);
}

void melt_cheese(int n, int m, vector<vector<int>>& board) {
	// ���� ġ���� ��ġ�� ������ ť
	// �ٷ� ������ �ʴ� ������ ���� �ð� �ٸ� ġ� Ž���Ͽ� ���� ���θ� Ȯ���� �� ������ �� �� �ֱ� ����
	queue<pair<int, int>> melt_queue;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ġ� �ִ� ĭ�̶��
			if (board[i][j] == 1) {
				int count = 0;
				// �����¿쿡 ���� �ܺΰ����� ������ ���� ������ ��
				for (int d = 0; d < 4; d++)
					if (board[i + di[d]][j + dj[d]] == -1)
						count++;
				// 2�� �̻� ������ ��� ����ġ��ť �� push
				if (count >= 2)
					melt_queue.push(pair<int, int>(i, j));
			}
		}
	}

	// ���� ġ����� ���� �߰� �����Ƿ� �̵��� �ٽ� ������ ���� ���̴� �۾�
	while (!melt_queue.empty()) {
		pair<int, int> cheese = melt_queue.front();
		melt_queue.pop();
		// ���� ġ���� ĭ�� �ܺΰ����� ��
		board[cheese.first][cheese.second] = -1;

		// ���� ���� ġ���� �ֺ��� ���ΰ����� �־��ٸ� �� �κ��� �ܺΰ������� �ٲپ��־�� ��
		for (int i = 0; i < 4; i++)
			if (board[cheese.first + di[i]][cheese.second + dj[i]] == 0)
				dfs(cheese.first + di[i], cheese.second + dj[i], board);
	}
}

int solution(int n, int m, vector<vector<int>> &board) {
	int timer = 0;
	bool isCheese;	// �����ִ� ġ� �ִ��� �Ǵ��� ����
	
	// �ܺΰ��� ǥ��
	dfs(0, 0, board);

	do {
		// ġ� ����
		isCheese = false;
		melt_cheese(n, m, board);
		timer++;

		// �����ִ� ġ� �ִ��� Ȯ����
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
				if (board[i][j] == 1)
					isCheese = true;

	} while (isCheese);

	return timer;
}

int main() {
	int n, m, answer;

	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	answer = solution(n, m, board);
	cout << answer;
	return 0;
}