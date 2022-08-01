import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_10026번_적록색약_DFS {

    static String ans;

    static int N;   // NxN 크기의 그림
    static String Line; // graph에 들어갈 줄을 받기 위해
    static char[][] graph;   // 그림
    static boolean[][] visited; // 방문 여부
    // 이동방향
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};
    static int cnt; // 구역 수를 카운트

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   // 입력받을 버퍼
        
        N = Integer.parseInt(br.readLine());

        graph = new char[N+1][N+1];     // 0~N-1
        visited = new boolean[N+1][N+1];
        
        for(boolean[] v: visited){
            Arrays.fill(v, false);
        }

        for (int i=0; i<N; i++){
            Line = br.readLine();   // RRRBB
            for (int j=0; j<N; j++){
                graph[i][j] = Line.charAt(j);   // Line에서 index j에 위치한 char을 graph에 넣기
            }
        }

        cnt = 0;
        // 정상인
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (!visited[i][j]){
                    cnt += 1;
                    DFS(i, j);
                }
            }
        }
        ans = Integer.toString(cnt);
        ans += " ";



        // 색약
        // graph의 G->R로 바꿈
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (graph[i][j]=='G'){
                    graph[i][j] = 'R';
                }
            }
        }
        for(boolean[] v: visited){
            Arrays.fill(v, false);
        }
        cnt = 0;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (!visited[i][j]){
                    cnt += 1;
                    DFS(i, j);
                }
            }
        }
        ans += Integer.toString(cnt);

        System.out.println(ans);

    }

    public static void DFS(int x, int y) {
        // 이번 좌표 방문 처리
        visited[x][y] = true;
        
        // 이번 좌표의 색
        char tmpColor = graph[x][y];

        // 다음 좌표 탐색
        for(int i=0; i<4; i++){
            // 다음 좌표
            int new_x = x+dx[i];
            int new_y = y+dy[i];

            // 범위 바깥? -> 패스
            if (new_x<0 || new_x>=N || new_y<0 || new_y>=N){continue;}

            if (visited[new_x][new_y]==false && graph[new_x][new_y]==tmpColor){DFS(new_x, new_y);}

        }

        
    }

}