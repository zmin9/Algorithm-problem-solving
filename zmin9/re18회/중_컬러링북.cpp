// 프로그래머스 1829번
#include <vector>
using namespace std;

// 각 칸의 방문 여부를 저장할 벡터 전역으로 설정
vector<vector<bool>> visited;

// 상 하 좌 우 탐색을 위한 배열
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

// dfs로 주변 타일을 탐색한다
void dfs(int row, int col, int m, int n, int* count, vector<vector<int>> picture) {
    // 만약 방문한 적이 있는 타일일 경우 return
    if (visited[row][col])
        return;

    // 방문 여부를 변경하고 타일 개수를 증가시킴
    visited[row][col] = true;
    (*count)++;

    // 상하좌우에 대해 같은 색이면 dfs를 진행한다.
    for (int k = 0; k < 4; k++)
        if (row + di[k] >= 0 && col + dj[k] >= 0 && row + di[k] < m && col + dj[k] < n)
            if (picture[row][col] == picture[row + di[k]][col + dj[k]])
                dfs(row + di[k], col + dj[k], m, n, count, picture);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    visited.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 빈 공간이 아니고 방문한 적이 없는 칸이라면 dfs
            if (picture[i][j] != 0 && !visited[i][j]) {
                number_of_area++;
                int size_of_this_area = 0;
                dfs(i, j, m, n, &size_of_this_area, picture);
                // 만약 이번에 탐색한 칸의 갯수가 클 경우 저장한다
                if (size_of_this_area > max_size_of_one_area)
                    max_size_of_one_area = size_of_this_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}