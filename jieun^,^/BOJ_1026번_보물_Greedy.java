import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ_1026번_보물_Greedy {

    static int N;
    static Integer A[];
    static Integer B[];
    static int ans;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        A = new Integer [N];
        B = new Integer [N];
        
        // A 입력 받기
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        for (int n=0; n<N; n++){
            A[n] = Integer.parseInt(st1.nextToken());
        }
        // B 입력 받기
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        for (int n=0; n<N; n++){
            B[n] = Integer.parseInt(st2.nextToken());
        }

        //System.out.println(A); -> A라는 변수가 가리키고 있는 배열의 메모리의 주소값
        System.out.println(Arrays.toString(A));   // 반복문으로 출력하거나 toString 메서드

        Arrays.sort(A);
        Arrays.sort(B, Collections.reverseOrder());
        
        ans = 0;
        for(int n=0; n<N; n++){
            ans += A[n] * B[n];
        }

        System.out.println(ans);
    }
}
