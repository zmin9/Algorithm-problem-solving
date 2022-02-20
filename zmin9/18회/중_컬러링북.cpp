// 프로그래머스 1829번
#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, int j, int& size_of_this_area, vector<vector<int>>picture, vector<vector<bool>>& visited) {
    // 방문했던 타일인 경우 return
    if (visited[i][j])
        return;

    size_of_this_area++;
    visited[i][j] = true;

    // 상하좌우에 대해 색이 같다면 재귀함수 호출함
    if (i - 1 >= 0 && picture[i][j] == picture[i - 1][j])
        dfs(i - 1, j, size_of_this_area, picture, visited);
    if (i + 1 < picture.size() && picture[i][j] == picture[i + 1][j])
        dfs(i + 1, j, size_of_this_area, picture, visited);
    if (j - 1 >= 0 && picture[i][j] == picture[i][j - 1])
        dfs(i, j - 1, size_of_this_area, picture, visited);
    if (j + 1 < picture[0].size() && picture[i][j] == picture[i][j + 1])
        dfs(i, j + 1, size_of_this_area, picture, visited);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 칠하지 않는 부분을 제외하고 방문하지 않은 타일에 대하여 dfs
            if (picture[i][j] != 0 && !visited[i][j]) {
                number_of_area++;
                int size_of_this_area = 0;
                dfs(i, j, size_of_this_area, picture, visited);
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

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> picture(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> picture[i][j];
    auto answer = solution(m, n, picture);
    cout << answer[0] << ' ' << answer[1];
    return;
}