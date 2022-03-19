// 백준 2580번
#include <iostream>
#include <vector>

using namespace std;
/*
* <백트래킹>
* 여러 선택지가 있을 때 한 가지 경우가 적절한 답이라고 가정하여 계속 진행하다가 틀린 경우 다시 돌아와서 다른 경우를 선택하는 알고리즘
* 브루트포스 알고리즘과 비슷하지만 답이 아닌 경우를 제외할 수 있음
*/

// 비어있는 칸의 좌표를 저장할 벡터
vector<pair<int, int>> blank;

// 각 행, 열, 박스에 1-9의 숫자가 있는지 확인할 배열(스도쿠 규칙을 나타낸 것)
bool row[9][10] = { false, };
bool col[9][10] = { false, };
bool box[9][10] = { false, };

bool backtracking(int idx, vector<vector<int>>& answer) {
	// 현재 호출한 인덱스가 blank의 크기와 같다면 모든 빈칸을 채웠다는 말
	if (idx == blank.size())
		return true;

	int r = blank[idx].first, c = blank[idx].second;

	for (int n = 1; n < 10; n++) {
		// 1-9까지 모두 탐색하며 각 행, 열, 박스에 없는 숫자를 찾아냄
		if (!row[r][n] && !col[c][n] && !box[3 * (r / 3) + (c / 3)][n]) {
			row[r][n] = true;
			col[c][n] = true;
			box[3 * (r / 3) + (c / 3)][n] = true;
			
			// 해당 칸을 n으로 채우고 다음 칸 채우기 시도
			// 만약 다음칸도 적절하게 채워진다면 return true
			if (backtracking(idx + 1, answer)) {
				answer[r][c] = n;
				return true;
			}
			else {
				// 만약 도중에 잘못된 값이었다면 다시 원래대로 돌려둬야함
				row[r][n] = false;
				col[c][n] = false;
				box[3 * (r / 3) + (c / 3)][n] = false;
				// 그리고 다음 n탐색
			}
		}
	}
	// 적절하게 들어갈 n이 없는 경우
	return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku) {
	vector<vector<int>> answer = sudoku;

	// 주어진 스도쿠를 탐색하며 비어있는 칸은 따로 모아두고
	// 각 행, 렬, 박스에 숫자의 존재 여부를 표시한다
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0)
				blank.push_back(pair<int, int>(i, j));
			else {
				row[i][sudoku[i][j]] = true;
				col[j][sudoku[i][j]] = true;
				box[3 * (i / 3) + (j / 3)][sudoku[i][j]] = true;
			}
		}
	}

	backtracking(0, answer);

	return answer;
}


int main() {
	vector<vector<int>> sudoku(9, vector<int>(9));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];

	auto result = solution(sudoku);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << result[i][j] << ' ';
		cout << '\n';
	}
}