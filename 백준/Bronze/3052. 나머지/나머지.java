import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] remainders = new boolean[42];
        int cnt = 0;

        for (int i = 0; i < 10; i++) {
            int num = Integer.parseInt(br.readLine());

            int remainder = num % 42;
            if (!remainders[remainder]) {
                remainders[remainder] = true;

                cnt++;
            }
        }

        System.out.println(cnt);
    }
}