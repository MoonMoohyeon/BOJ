import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String strA = sc.next();
        String strB = sc.next();
        String strC = sc.next();
        
        sc.close();
        
        int numA = Integer.parseInt(strA);
        int numB = Integer.parseInt(strB);
        int numC = Integer.parseInt(strC);
        
        int resnumber = numA + numB - numC;
        System.out.println(resnumber);
        
        String concatAB = strA + strB;
        int numConcatAB = Integer.parseInt(concatAB);

        int resstring = numConcatAB - numC;
        System.out.println(resstring);
    }
}