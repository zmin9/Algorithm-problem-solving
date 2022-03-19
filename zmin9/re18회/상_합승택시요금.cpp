// 프로그래머스 72413번
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    // 거리를 저장할 그래프 선언 -> 양방향 그래프이므로 dp[a][b]==dp[b][a]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 20000000));
    for (int i = 0; i < fares.size(); i++) {
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    // 자신 -> 자신 의 가중치는 0이다
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    /*
    * <플로이드 워셜 알고리즘>
    * 모든 지점에 대해 각 지점 사이의 최소 가중치를 구하는 알고리즘
    * 유의해야 할 것은 시작점과 끝점을 정해두고 그 사이의 경유하는 지점을 변화시키는 형태가 아니라
    * 경유지점을 고정하고 시작점과 끝점을 바꿔가며 값을 입력하는 형태
    * 
    * 주어진 입력이 그렇게 크지 않아 적절하게 사용할 수 있음
    * 
    * 시간복잡도 : n^3
    */
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 기존에 입력해두었던 값보다 새로운 경유지를 거치는 가중치가 더 작다면 그것을 저장
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }

    int answer = 20000000;

    // 모든 지점 사이의 최단 경로를 구했으니 합승구간+각자 이동하는 구간의 합이 최소일 때의 그 합을 구함
    for (int i = 1; i <= n; i++)
        answer = min(answer, dp[s][i] + dp[a][i] + dp[b][i]);

    return answer;
}