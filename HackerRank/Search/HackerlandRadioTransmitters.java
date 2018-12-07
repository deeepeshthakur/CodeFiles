import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class HackerlandRadioTransmitters {

  static int hackerlandRadioTransmitters( int[] x, int k){
    int n = x.length;
    Arrays.sort(x);
    Boolean flag = true;
    int curr_start = x[0], counter = 0, station_counter = 0;
    while(flag)
    {
      station_counter++;
      while(flag && counter < n && x[counter] - curr_start <= k)
      {
        counter++;
      }
      if(counter < n){
        counter--;
        curr_start = x[counter];
      }
      else
        flag = false;
      while(flag && counter < n && x[counter] - curr_start <= k)
      {
        counter++;
      }
      if(counter < n){
        curr_start = x[counter];
      }
      else
        flag = false;
    }
    return station_counter;
  }

  public static void main(String[] args) throws IOException{
    Scanner in = new Scanner(new FileInputStream("/home/deepesh/Input.txt"));
    int n = in.nextInt();
    int k = in.nextInt();
    int[] x = new int[n];
    for( int index = 0; index < n; index++)
    {
      x[index] = in.nextInt();
    }
    int result = hackerlandRadioTransmitters( x, k);
    System.out.println(result);
    in.close();
  }
}
