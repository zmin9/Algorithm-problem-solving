// 백준 2638번
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상 하 좌 우
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

// 외부공간 표시에 이용할 DFS
void dfs(int row, int col, vector<vector<int>> &board) {
	// 만약 빈공간이 아니라면 == 치즈가 있다면 탐색X
	if (board[row][col] != 0)
		return;

	board[row][col] = -1;

	for (int i = 0; i < 4; i++)
		if (row + di[i] >= 0 && row + di[i] < board.size() && col + dj[i] >= 0 && col + dj[i] < board[0].size())
			dfs(row + di[i], col + dj[i], board);
}

void melt_cheese(int n, int m, vector<vector<int>>& board) {
	// 녹을 치즈의 위치를 저장할 큐
	// 바로 녹이지 않는 이유는 동일 시간 다른 치즈를 탐색하여 녹음 여부를 확인할 때 영향을 줄 수 있기 때문
	queue<pair<int, int>> melt_queue;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 만약 치즈가 있는 칸이라면
			if (board[i][j] == 1) {
				int count = 0;
				// 상하좌우에 대해 외부공간과 인접한 면의 갯수를 셈
				for (int d = 0; d < 4; d++)
					if (board[i + di[d]][j + dj[d]] == -1)
						count++;
				// 2개 이상 인접한 경우 녹을치즈큐 에 push
				if (count >= 2)
					melt_queue.push(pair<int, int>(i, j));
			}
		}
	}

	// 녹을 치즈들을 전부 발견 했으므로 이들을 다시 꺼내서 실제 녹이는 작업
	while (!melt_queue.empty()) {
		pair<int, int> cheese = melt_queue.front();
		melt_queue.pop();
		// 녹은 치즈의 칸은 외부공간이 됨
		board[cheese.first][cheese.second] = -1;

		// 만약 녹은 치즈의 주변에 내부공간이 있었다면 이 부분을 외부공간으로 바꾸어주어야 함
		for (int i = 0; i < 4; i++)
			if (board[cheese.first + di[i]][cheese.second + dj[i]] == 0)
				dfs(cheese.first + di[i], cheese.second + dj[i], board);
	}
}

int solution(int n, int m, vector<vector<int>> &board) {
	int timer = 0;
	bool isCheese;	// 남아있는 치즈가 있는지 판단할 변수
	
	// 외부공간 표시
	dfs(0, 0, board);

	do {
		// 치즈를 녹임
		isCheese = false;
		melt_cheese(n, m, board);
		timer++;

		// 남아있는 치즈가 있는지 확인함
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