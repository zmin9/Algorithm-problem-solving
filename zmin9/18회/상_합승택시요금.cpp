// 프로그래머스 72413번
#include <vector>
#define MAX 2000000

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    int answer = MAX;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, MAX));

    // 양방향
    for (int i = 0; i < fares.size(); i++) {
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    // 해당 위치에서 해당 위치까지 가는 비용은 0이라고 생각
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // 플로이드 워셜
    // 모든 시작점-끝점에 대한 가중치 최솟값을 구함
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // 합승은 s->i 까지 이루어지고 i부터 각자의 집으로 가는 비용을 다 더한 값 중 최솟값을 찾음
    for (int i = 1; i <= n; i++)
        answer = min(answer, dp[s][i] + dp[a][i] + dp[b][i]);

    return answer;
}