import java.util.*;
import java.io.*;
public class GrayCode 
{
    int len; 
    int[] gc;

    public static void main(String[] args) {

    }

    public GrayCode(int num_var) {
        len = (int)Math.pow(2, num_var);
        gc = new int[len];
        gc[0] = 0;
        gc[1] = 1;
        int index = 1;
        for(int i = 1; i < num_var; ++i) {
            index *= 2;
            for(int j = index; j < 2 * index; ++j) {
                gc[j] = gc[index - 1 - (j - index)] + index;
            }
        }
    }
}
