// 백준 3190번
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, int K, vector<vector<int>>& apple, int L, vector<vector<string>>& rotation) {
	vector<vector<int>> board(N, vector<int>(N, 0));
	// 아무것도 없음:0, 뱀이 존재하는 칸:1, 사과가 존재하는 칸:2
	// 사과 위치 표시
	// 문제에서 주어진건 왼쪽 위 구석을 1,1 로 생각하는 위치이기 때문에 실제 값에 적용하려면 -1을 해주는 것을 잊으면 안된다
	for (int i = 0; i < K; i++)
		board[apple[i][0] - 1][apple[i][1] - 1] = 2;

	// 뱀의 시작 위치 표시
	board[0][0] = 1;
	queue<pair<int, int>> snake;
	snake.push(pair<int, int>(0, 0));

	int timer = 0;
	// 현재 방향
	int d_idx = 0;
	// 현재 참조할 회전 정보
	int r_idx = 0;

	// D(시계방향)이 인덱스+1, L(반시계방향)이 인덱스-1
	int d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	while (true) {
		timer++;
		int next_i = snake.back().first + d[d_idx][0];
		int next_j = snake.back().second + d[d_idx][1];

		// board를 벗어나는 경우
		if (next_i >= N || next_j >= N || next_i < 0 || next_j < 0)
			break;

		// 뱀의 몸이 있는 자리라면
		if (board[next_i][next_j] == 1)
			break;

		// 만약 빈칸이라면 (사과가 없다면) 꼬리칸을 비워줌
		if (board[next_i][next_j] == 0) {
			board[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}

		// 머리 이동
		snake.push(pair<int, int>(next_i, next_j));
		board[next_i][next_j] = 1;

		// 방향 전환
		// 이동이 끝난 뒤 방향을 전환
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