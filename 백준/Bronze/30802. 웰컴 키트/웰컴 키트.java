import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        long N = Long.parseLong(br.readLine());

        long[] size = new long[6];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++) {
            size[i] = Long.parseLong(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        long T = Long.parseLong(st.nextToken());
        long P = Long.parseLong(st.nextToken());
        
        long sum = 0;

        for (long sizeCount : size) {
            sum += (sizeCount + T - 1) / T;
        }

        long bundles = N / P;
        long single = N % P;
        
        System.out.println(sum);
        System.out.println(bundles + " " + single);
    }
}