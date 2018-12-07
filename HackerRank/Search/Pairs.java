import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class Pairs{
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner( new FileInputStream("Input.txt"));
		Integer N = 0, K = 0;
		N = in.nextInt();
		K = in.nextInt();
		Integer ans = 0;
		Integer[] inputArray = new Integer[N];
		for(Integer index = 0; index < N; index++)
			inputArray[index] = in.nextInt();
		Arrays.sort(inputArray);
		for(Integer index = 0; index < N; index++)
		{
			if(Arrays.binarySearch(inputArray, inputArray[index] + K) >= 0)
			{
				ans++;
			}
		}
		System.out.println(ans);		
		in.close();
	}
}