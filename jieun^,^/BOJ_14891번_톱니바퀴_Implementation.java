import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_14891번_톱니바퀴_Implementation {
    static char[][] gear = new char[4][8];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 톱니 바퀴의 상태 입력 받기
        for (int i=0; i<4; i++){
            String Line = br.readLine();
            for (int j=0; j<8; j++){
                gear[i][j]=Line.charAt(j);
            }
        }

        int K = Integer.parseInt(br.readLine());    // 회전 횟수
        StringTokenizer st;
        for (int k=0; k<K; k++){
            st = new StringTokenizer(br.readLine());
            int g = Integer.parseInt(st.nextToken());   // 몇 번째 톱니바퀴를 회전시킬지
            int dir = Integer.parseInt(st.nextToken()); // 어느 방향으로 회전시킬지

            // 한번 회전시킬 때마다 한 톱니바퀴는 최대 한 번만 회전해야함
            // 그것을 체크하기 위한 boolean 배열
            boolean checked[] = new boolean[4]; 
            Arrays.fill(checked, false);
            
            // K번 회전
            rotation(gear, g-1, dir, checked);
        }

        //for (int i=0; i<4; i++){System.out.println(Arrays.toString(gear[i]));}

        System.out.println(cal(gear));

    }

    public static void turn(char[][] gear, int g, int dir){
        char[] tmp = Arrays.copyOf(gear[g], gear[g].length);

        if (dir==1){    // 시계 방향
            for(int i=0; i<8; i++){ 
                if (i==0){gear[g][i]=tmp[7];}
                else{gear[g][i]=tmp[i-1];}
            }
        }else if(dir==-1){  // 반시계 방향
            for(int i=0; i<8; i++){
                if(i==7){gear[g][i]=tmp[0];}
                else{gear[g][i]=tmp[i+1];}
            }
        }

    }

    public static void rotation(char[][] gear, int g, int dir, boolean[] checked){
        char[] before = Arrays.copyOf(gear[g], gear[g].length);
        
        turn(gear, g, dir);
        checked[g]=true;    // g번째 톱니바퀴 회전시켰다고 체크해두기

        // 인접 톱니바퀴 체크
        // 오른쪽 톱니바퀴 체크
        if (g!=3){
            if (before[2]!=gear[g+1][6]){
                if (checked[g+1]==false){
                    rotation(gear, g+1, -dir, checked); // 오른쪽 톱니바퀴를 반대 방향으로 회전
                }
            }
        }

        // 왼쪽 톱니바퀴 체크
        if (g!=0){
            if (before[6]!=gear[g-1][2]){
                if (checked[g-1]==false){
                    rotation(gear, g-1, -dir, checked);
                }
            }
        }
    }

    public static int cal(char[][] gear){
        int ans=0;
        if (gear[0][0]=='1'){ans += 1;}
        if (gear[1][0]=='1'){ans += 2;}
        if (gear[2][0]=='1'){ans += 4;}
        if (gear[3][0]=='1'){ans += 8;}
        
        return ans;
    }
}
