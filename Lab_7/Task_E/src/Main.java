import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

//Ew Ob Ad 47 71778163784 g.SRB, ul.Uzmeuxmxm, d.618
public class Main {
    public static void main(String[] args) {
        Pattern pattern = Pattern.compile(
                "[A-Z][a-z]* [A-Z][a-z]* [A-Z][a-z]* \\d\\d (\\+7|7|8)\\(?\\d\\d\\d\\)?-?\\d\\d\\d-?\\d\\d-?\\d\\d g\\.[A-Z]{3}, ul\\.[A-Z][a-z]*, d\\.\\d+");

        //Pattern pattern1 = Pattern.compile("[A-Z][a-z]* [A-Z][a-z]* [A-Z][a-z]* \\d\\d");

        int M;
        String string;
        try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in))){
            M = Integer.parseInt(bufferedReader.readLine());
            for (int i = 0; i < M; i++) {
                string = bufferedReader.readLine();
                Matcher matcher = pattern.matcher(string);
                if (matcher.find()){
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }


        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}