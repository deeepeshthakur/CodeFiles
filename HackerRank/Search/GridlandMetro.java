import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class GridlandMetro{

  static BigInteger gridLandMetro( Long n, Long m, Integer k, Long[] rows, Long[] col1, Long[] col2)
  {
    BigInteger ans = BigInteger.valueOf(0);
    for(Integer x = 0; x < k; x++)
    {
      ans = ans.add(BigInteger.valueOf(col2[x] - col1[x] + 1));
      //System.out.println(x + " ");
        for(Integer y = x + 1; y < k; y++)
        {
          if(rows[y] == rows[x])
          {
              if(!(col2[x] < col1[y] || col2[y] < col1[x]))
              {
                Long commonCol1;
                if(col1[x] >= col1[y])
                  {
                    commonCol1 = col1[x];
                  }
                else{
                  commonCol1 = col1[y];
                }
                Long commonCol2;
                if(col2[x] <= col2[y])
                  {
                    commonCol2 = col2[x];
                  }
                else
                  commonCol2 = col2[y];
                //System.out.println(rows[x] + " " + y + " " + commonCol1 + " " + commonCol2);
                ans = ans.subtract(BigInteger.valueOf(commonCol2 - commonCol1 + 1));
              }
          }
        }
    }
    BigInteger total = BigInteger.valueOf(n);
    total = total.multiply(BigInteger.valueOf(m));
    ans = total.subtract(ans);
    return ans;
  }

  public static void main(String[] args) throws IOException{
    Scanner in = new Scanner( new FileInputStream("/home/deepesh/Input.txt"));
    Long n = in.nextLong();
    Long m = in.nextLong();
    Integer k = in.nextInt();
    Long Rows[] = new Long[k];
    Long Col1[] = new Long[k];
    Long Col2[] = new Long[k];
    for(Integer index = 0; index < k; index++)
    {
      Rows[index] = in.nextLong();
      Col1[index] = in.nextLong();
      Col2[index] = in.nextLong();
    }

    BigInteger result = gridLandMetro( n, m, k, Rows, Col1, Col2);
    System.out.println(result);
    in.close();
    }
}
