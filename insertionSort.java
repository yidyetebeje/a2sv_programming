import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'insertionSort1' function below.
     *
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. INTEGER_ARRAY arr
     */

  public static void insertionSort1(int n, List<Integer> arr) {
        // Write your code here
        int j = arr.size() - 1;
        int temp = arr.get(j);
        for(; j >= 0; j--){
            if(j == 0){
                arr.set(j  , temp);
                for(int k = 0; k <= arr.size() - 1; k++){
                    if (k != arr.size() - 1) {
                        System.out.print(arr.get(k) + " ");
                    } else {
                        System.out.println(arr.get(k));
                    }
                }
                break;
            }
            else if(temp < arr.get(j - 1)){
                arr.set(j, arr.get(j - 1));
                for(int k = 0; k < arr.size(); k++){
                    if (k != arr.size() - 1) {
                        System.out.print(arr.get(k) + " ");
                    } else {
                        System.out.println(arr.get(k));
                    }
                }
            }else {
                arr.set(j  , temp);
                for(int k = 0; k <= arr.size() - 1; k++){
                    if (k != arr.size() - 1) {
                        System.out.print(arr.get(k) + " ");
                    } else {
                        System.out.println(arr.get(k));
                    }
                }
                break;
            }
        }

    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.insertionSort1(n, arr);

        bufferedReader.close();
    }
}
