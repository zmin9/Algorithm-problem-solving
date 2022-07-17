import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_1260번_DFS와BFS_DFSBFS {
    /*
     * 문자열을 더할 때, 새 객체를 생성하지 않고 기존의 데이터에 더하는 방식을 사용 -> 속도 빠르고, 부하 적음
     * 긴 문자열을 더하는 상황이 발생할 경우 사용 -> 정답 출력용 문자열로 사용
     */ 
    static StringBuilder ans = new StringBuilder();

    /*
     * 해당 노드를 방문했는지 여부를 체크할 배열
     */
    static boolean[] visited;

    /*
     * 각 노드가 어느 노드와 연결되어 있는지 정보를 받는 이차 배열
     */
    static int[] [] graph;

    static int N, M, V; // N: 정점의 개수, M: 간선의 개수, V: 탐색 시작 정점의 번호

    static Queue<Integer> Q = new LinkedList<>();   // BFS에서 사용할 큐

    public static void main(String[] args) throws IOException {
        /*
         * BufferedReader - 버퍼: 데이터를 한 곳에서 다른 한 곳으로 전송하는 동안 일시적으로 그 데이터를 보관하는 임시 메모
         * 입출력 속도 향상
         * 엔터만 경계로 인식, 받은 데이터가 String으로 고정
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        graph = new int[N+1][N+1];  // 1~N번 노드의 연결 정보
        visited = new boolean[N+1]; // 1~N번 노드의 방문 여부

        // 간선 입력 받기
        for(int i=0; i<M; i++){
            StringTokenizer str = new StringTokenizer(br.readLine());   // readLine한 BufferReader을 자른다 (띄어쓰기)

            int a = Integer.parseInt(str.nextToken());
            int b = Integer.parseInt(str.nextToken());

            graph[a][b] = graph[b][a] = 1;  // a <-> b 간선이 존재
        }

        dfs(V);
        
        ans.append("\n");   // 정답에 한 줄 띄기 추가

        visited = new boolean[N+1];

        bfs(V);

        System.out.println(ans);
    }

    public static void dfs(int start){
        // start 노드 방문 처리
        visited[start] = true;
        ans.append(start+" ");

        for (int i=0; i<=N; i++){
            if(graph[start][i]==1 & visited[i]==false){
                dfs(i);
            }
        }
    }

    public static void bfs(int start){
        Q.add(start);
        visited[start] = true;

        while(!Q.isEmpty()){
            // 첫 노드 큐에 넣기
            start = Q.poll();   //the head of this queue, or null if this queue is empty
            ans.append(start+" ");

            for (int i=1; i<=N; i++){
                if (graph[start][i]==1 && visited[i]==false){
                    // 방문 처리한 노드와 붙어있는 노드를 큐에 넣기
                    Q.add(i);
                    visited[i] = true;
                }
            }
        }
    }
    
}