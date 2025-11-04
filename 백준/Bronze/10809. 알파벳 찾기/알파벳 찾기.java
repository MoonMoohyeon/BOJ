import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        int[] alpha = new int[26];
        Arrays.fill(alpha, -1);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();

        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);

            int idx = c - 'a';

            if (alpha[idx] == -1) {
                alpha[idx] = i;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int pos : alpha) {
            sb.append(pos).append(" ");
        }
        System.out.println(sb.toString().trim());
    }
}