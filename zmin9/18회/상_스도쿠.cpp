// 백준 2580번
// 실행시간이 3배 정도 더 걸림..
#include <iostream>
#include <vector>

using namespace std;

// 각 숫자의 존재 여부, 행, 열, 박스
bool num_state[3][9][10] = { false, };
// 스도쿠에서 비어있는 칸 저장할 벡터
vector<pair<int, int>> blank;

// 백트래킹
// 임의로 하나의 숫자를 정해서 쭉 대입해보다가 아닌 경우 다시 되돌아와서 다른 숫자를 대입해보는 방식
bool fillSudoku(int index, vector<vector<int>>& sudoku) {
	// index는 blank의 인덱스. blank.size()와 같다는 것은 전부 채웠다는 것 -> true 반환
	if (index == blank.size())
		return true;

	for (int num = 1; num <= 9;num++) {
		int i = blank[index].first, j = blank[index].second;
		// 빈칸과 동일한 행, 렬, 박스 내에 정해지지 않는 num에 대해 백트래킹 실시
		if (!num_state[0][i][num] && !num_state[1][j][num] && !num_state[2][int(i / 3) * 3 + int(j / 3)][num]) {
			
			num_state[0][i][num] = true;
			num_state[1][j][num] = true;
			num_state[2][int(i / 3) * 3 + int(j / 3)][num] = true;

			// 만약 백트래킹 도중 잘못된 것을 알았다면 다시 원래대로 돌려놓고 다음 num 대입
			if (!fillSudoku(index + 1, sudoku)) {
				num_state[0][i][num] = false;
				num_state[1][j][num] = false;
				num_state[2][int(i / 3) * 3 + int(j / 3)][num] = false;
			}
			else {
				// 끝까지 가서 18줄의 true를 받은 경우 연쇄적으로 true 발생
				sudoku[i][j] = num;
				return true;
			}
		}
	}

	// 알맞은 num이 없는 경우 false 반환 -> 그런 경우는 입력으로 주어지지 않음
	return false;
}

// solution 함수로 return값 낼 수 있도록 작성
vector<vector<int>> solution(vector<vector<int>> sudoku) {

	vector<vector<int>> result = sudoku;

	// 모든 칸 돌면서 빈칸이면 blank벡터에 추가하고 아닐 경우 상태를 true로 바꿈
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0)
				blank.push_back(pair<int, int>(i, j));
			else {
				num_state[0][i][sudoku[i][j]] = true;
				num_state[1][j][sudoku[i][j]] = true;
				num_state[2][int(i / 3) * 3 + int(j / 3)][sudoku[i][j]] = true;
			}
		}
	}
			
	fillSudoku(0, result);
	
	return result;
}

int main() {
	vector<vector<int>> sudoku(9, vector<int>(9));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];

	auto result = solution(sudoku);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << result[i][j]<<' ';
		cout << '\n';
	}
}