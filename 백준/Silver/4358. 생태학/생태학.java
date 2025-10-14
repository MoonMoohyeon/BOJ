import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Map<String, Integer> treeCounts = new TreeMap<>();
        int totalCount = 0;
        String tree;

        // tree.isEmpty() 체크는 빈 줄 입력을 무시
        while ((tree = br.readLine()) != null && !tree.isEmpty()) {
            // getOrDefault: tree가 맵에 있으면 해당 값을, 없으면 기본값(0)을 반환
            treeCounts.put(tree, treeCounts.getOrDefault(tree, 0) + 1);
            totalCount++;
        }

        // 이미 정렬되어 있음
        for (Map.Entry<String, Integer> entry : treeCounts.entrySet()) {
            String species = entry.getKey();
            int count = entry.getValue();
            double percentage = ((double) count / totalCount) * 100.0;

            System.out.printf("%s %.4f\n", species, percentage);
        }

        br.close();
    }
}