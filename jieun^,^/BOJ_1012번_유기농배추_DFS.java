import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1012번_유기농배추_DFS{
    
    static int T;   // 테스트 케이스의 개수
    static int M, N, K;    // 배추밭의 가로 (M), 세로 (N), 배추가 심어진 위치의 개수 (K)
    static int[][] graph;   // 배추밭
    static boolean[][] visited; // 방문 여부
    
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};

    static int next_x, next_y;
    static int cnt;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder ans = new StringBuilder();
    
        int T = Integer.parseInt(br.readLine());

        for (int t=0; t<T; t++){

            StringTokenizer st1 = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st1.nextToken());
            N = Integer.parseInt(st1.nextToken());
            K = Integer.parseInt(st1.nextToken());

            // 크기에 맞는 배열 생성
            graph = new int[N][M];  // 0 ~ N-1, 0 ~ M-1
            visited = new boolean[N][M];

            // graph를 0으로 초기화
            for (int[] g: graph){
                Arrays.fill(g, 0);  
            }
            // visited를 false로 초기화
            for (boolean[] v: visited){
                Arrays.fill(v, false);  
            }

            // 배추의 위치 입력 받기
            for (int k=0; k < K; k++){
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st2.nextToken());
                int y = Integer.parseInt(st2.nextToken());

                // 배추 있음 = 1
                graph[y][x] = 1;
            }

            cnt = 0;
            for (int i=0; i<N; i++){
                for (int j=0; j<M; j++){
                    if (graph[i][j]==1 && visited[i][j]==false){
                        cnt++;
                        DFS(j, i);
                    }
                }
            }  
            ans.append(cnt).append('\n');
        }

        System.out.println(ans);
    }

    public static void DFS(int x, int y){   // x: 가로(M), y: 세로(N) -> graph[y][x]

        visited[y][x] = true;

        for (int d=0; d < 4; d++){
            next_x = x + dx[d];
            next_y = y + dy[d];

            // 범위에 들고
            // 아직 방문 X
            // 배추가 존재
            if (next_x < M && next_x >= 0 && next_y < N && next_y >= 0){

                if ( !visited[next_y][next_x] && graph[next_y][next_x]==1 ){
                    DFS(next_x, next_y);
                }
            }
        }
    }

}