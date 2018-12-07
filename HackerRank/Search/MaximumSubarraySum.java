import java.util.*;
import java.text.*;
import java.math.*;
import java.io.*;
import java.util.regex.*;

public class MaximumSubarraySum{
	private static Long inputArray[] = new Long[100000];
	private static Long bookKeeping[] = new Long[100000];
	private static Integer N = 0;
	private static Long M = Long.valueOf(0);
	private static TreeSet<Long> currentSet = new TreeSet<Long>();
	
	private static Long maximumSubarrayFunction()
	{
		Long ans = Long.valueOf(0);
		bookKeeping[0] = inputArray[0]%M;
		for(Integer index = 1; index < N; index++)
		{
			bookKeeping[index] = (bookKeeping[index - 1] + inputArray[index])%M;
		}
		
		for(Integer index = 0; index < N; index++)
		{
			Long temp = Long.valueOf(0);
			currentSet.add(bookKeeping[index]);
			if(currentSet.higher(bookKeeping[index]) != null)
			{
				temp = M + bookKeeping[index] - currentSet.higher(bookKeeping[index]);
			}
			ans = Math.max( ans, Math.max( bookKeeping[index], temp));
		}
		
		return ans;
	}
	
	public static void main(String[] agrs) throws IOException {
		Scanner in = new Scanner( new FileInputStream("Input.txt"));
		Integer testCases = in.nextInt();
		for(Integer index = 0; index < testCases; index++)
		{
			N = in.nextInt();
			M = in.nextLong();
			currentSet.clear();
			for(Integer arrayIndex = 0; arrayIndex < N; arrayIndex++)
			{
				inputArray[arrayIndex] = in.nextLong();
			}
			
			System.out.println(maximumSubarrayFunction());
		}
		in.close();
	}
}