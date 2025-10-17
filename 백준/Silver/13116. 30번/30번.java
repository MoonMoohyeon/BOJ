import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            // a와 b가 같아질 때까지 반복
            while (a != b) {
                // 더 큰 쪽의 값을 부모 노드(값 / 2)로 변경
                if (a > b) {
                    a /= 2;
                } else {
                    b /= 2;
                }
            }

            sb.append(a * 10).append("\n");
        }
        
        System.out.print(sb);
    }
}