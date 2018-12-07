import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class IcecreamParlour {

  static Integer[] iceCreamParlour( Integer m, Integer[] arrOriginal)
  {
    Integer result[] = new Integer[2];
    Integer arr[] = arrOriginal.clone();
    Arrays.sort(arr);
    Boolean flag = true;
    for(Integer index = 0; index < arr.length - 1 && flag; index++)
    {
      Integer key = m - arr[index];
      Integer keyIndex = Arrays.binarySearch( arr, index + 1, arr.length, key);
      if(keyIndex >= 0)
      {
        flag = false;
        result[0] = arr[index];
        result[1] = key;
      }
    }
    Boolean flag0 = true;
    Boolean flag1 = true;
    for(Integer index = 0; index < arrOriginal.length; index++)
    {
      if(arrOriginal[index].equals(result[0]) && flag0)
      {
        flag0 = false;
        result[0] = index + 1;
        arrOriginal[index] = -1;
      } else if(arrOriginal[index].equals(result[1]) && flag1){
        flag1 = false;
        result[1] = index + 1;
        arrOriginal[index] = -1;
      }
    }
    Arrays.sort(result);
    return result;
  }

  public static void main(String[] agrs) throws IOException, NullPointerException{
    Scanner in = new Scanner( new FileInputStream("Input.txt"));
    Integer testCases = in.nextInt();
    for(Integer tCases = 0; tCases < testCases; tCases++)
    {
      Integer m = in.nextInt();
      Integer n = in.nextInt();
      Integer arr[] = new Integer[n];
      for(Integer index = 0; index < n; index++)
      {
        arr[index] = in.nextInt();
      }

      Integer[] result = iceCreamParlour( m, arr);
      System.out.println(result[0] + " " + result[1]);
    }
    in.close();
  }
}
