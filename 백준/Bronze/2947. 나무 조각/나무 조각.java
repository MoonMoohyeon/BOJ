import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static void print(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    private static boolean isSorted(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != i + 1) {
                return false;
            }
        }
        return true;
    }

    public static void swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] pieces = new int[5];
        for (int i = 0; i < 5; i++) {
            pieces[i] = Integer.parseInt(st.nextToken());
        }

        // 버블 정렬
        while (!isSorted(pieces)) {
            for (int i = 0; i < 4; i++) {
                if (pieces[i] > pieces[i + 1]) {
                    swap(pieces, i, i + 1);
                    print(pieces);
                }
            }
        }
    }
}