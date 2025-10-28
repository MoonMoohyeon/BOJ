import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    static int[][] grid;
    public static int findWinner(int r, int c, int size) {
        if (size == 1) {
            return grid[r][c];
        }
        
        int newSize = size / 2;
        
        int winner1 = findWinner(r, c, newSize);
        int winner2 = findWinner(r, c + newSize, newSize);
        int winner3 = findWinner(r + newSize, c, newSize);
        int winner4 = findWinner(r + newSize, c + newSize, newSize);
        
        int[] winners = {winner1, winner2, winner3, winner4};
        Arrays.sort(winners);
        
        return winners[1];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        
        grid = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        int finalWinner = findWinner(0, 0, N);
        
        System.out.println(finalWinner);
    }
}