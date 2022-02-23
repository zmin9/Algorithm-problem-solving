// ���� 2638��
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �� �� �� ��
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

void dfs(vector<vector<int>>& info, int i, int j, int area) {
	if (info[i][j] != 0) {
		return;
	}

	info[i][j] = area;

	for (int n = 0; n < 4; n++) {
		if (i + di[n] >= 0 && i + di[n] < info.size() && j + dj[n] >= 0 && j + dj[n] < info[0].size())
			dfs(info, i + di[n], j + dj[n], area);
	}
}

void melt_cheese(int* t, int n, int m, vector<vector<int>>& board) {
	queue<pair<int, int>> cheeze;

	// ���� ġ�� ã��
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			if (board[i][j] == 1) {
				int num = 0;
				for (int x = 0; x < 4; x++)
					if (board[i + di[x]][j + dj[x]] == 9) num++;
				if (num >= 2)
					cheeze.push(pair<int, int>(i, j));
			}
		}
	}

	// ���� ġ� ���ٸ� �� ���� ��
	if (cheeze.empty()) return;

	// ġ�� ���̱�
	while (!cheeze.empty()) {
		pair<int,int> m = cheeze.front();
		cheeze.pop();
		// ���� ġ���� ��ġ�� �ܺ� ������ ��
		board[m.first][m.second] = 9;
		// ���� ����ġ�� �����¿� �� 0�� ĭ(���ΰ���)�� �ִٸ� �ܺΰ������� ����
		for (int x = 0; x < 4; x++)
			if (board[m.first + di[x]][m.second + dj[x]] == 0)
				dfs(board, m.first + di[x], m.second + dj[x], 9);
	}
	(*t)++;

	melt_cheese(t, n, m, board);

}

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
int solution(int n, int m, vector<vector<int>>& board) {
	int result = 0;
	// �ܺΰ��� 9
	dfs(board, 0, 0, 9);

	melt_cheese(&result, n, m, board);

	return result;
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