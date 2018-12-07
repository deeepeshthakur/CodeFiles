import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class MinimumLoss {
	private static Integer N = 0;
	private static Long[] pricesOfHouses = new Long[200000];
	private static TreeSet<Long> currentSet = new TreeSet<Long>();
	
	static Long minimumLoss()
	{
		Long result = Long.MIN_VALUE;
		currentSet.add(pricesOfHouses[0]);
		currentSet.add(pricesOfHouses[1]);
		if(pricesOfHouses[1] - pricesOfHouses[0] < 0)
		{
			if(pricesOfHouses[1] - pricesOfHouses[0] > result)
				result = pricesOfHouses[1] - pricesOfHouses[0];
		}
		for(Integer index = 2; index < N; index++)
		{
			currentSet.add(pricesOfHouses[index]);
			if(currentSet.higher(pricesOfHouses[index]) != null)
			{
				Long temp = currentSet.higher(pricesOfHouses[index]);
				if(pricesOfHouses[index] - temp < 0)
				{
					if(pricesOfHouses[index] - temp > result)
						result = pricesOfHouses[index] - temp;
				}
			}
		}
		result = result * Long.valueOf(-1);
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner( new FileInputStream("Input.txt"));
		N = in.nextInt();
		for(Integer index = 0; index < N; index++)
		{
			pricesOfHouses[index] = in.nextLong();
		}
		
		Long ans = minimumLoss();
		System.out.println(ans);
		in.close();
	}
}