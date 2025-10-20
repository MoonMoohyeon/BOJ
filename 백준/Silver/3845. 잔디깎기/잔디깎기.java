import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int nx = sc.nextInt();
            int ny = sc.nextInt();
            double w = sc.nextDouble();

            if (nx == 0 && ny == 0 && w == 0.0) {
                break;
            }

            List<Double> xPositions = new ArrayList<>();
            List<Double> yPositions = new ArrayList<>();

            for (int i = 0; i < nx; ++i) {
                xPositions.add(sc.nextDouble());
            }
            for (int i = 0; i < ny; ++i) {
                yPositions.add(sc.nextDouble());
            }

            boolean isY = isCovered(xPositions, 75.0, w);
            boolean isX = isCovered(yPositions, 100.0, w);

            if (isY && isX) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        sc.close();
    }

    public static boolean isCovered(List<Double> positions, double totalLength, double width) {
        Collections.sort(positions);
        // 깎이는 범위의 반
        double halfWidth = width / 2;

        double covered = positions.get(0) + halfWidth; // 현재까지 덮인 범위
        for (int i = 1; i < positions.size(); ++i) {
            double pos = positions.get(i);
            double currentStart = pos - halfWidth; // 현재 길의 시작

            if (currentStart > covered) { // 현재 시작점이 최대 범위보다 크면 빈 틈
                return false;
            }

            covered = Math.max(covered, pos + halfWidth);
        }

        if (covered < totalLength) {
            return false;
        }

        return true;
    }
}