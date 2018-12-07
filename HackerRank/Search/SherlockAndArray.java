import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class SherlockAndArray{
	private static Integer sumOfAll = Integer.valueOf(0);
	private static Integer n = 0;
	private static Integer inputArray[] = new Integer[100000];
	
	static Boolean sherlockFunction() {
		Boolean result = false;
		Integer sumOfLeft = Integer.valueOf(0), sumOfRight = sumOfAll - sumOfLeft;
		Boolean flag = false;
		for(Integer index = 0; index < n && (!flag); index++)
		{
			sumOfRight -= inputArray[index];
			if(sumOfLeft.equals(sumOfRight))
			{
				flag = true;
				result = true;
			}
			else {
				sumOfLeft += inputArray[index];
				sumOfRight = sumOfAll - sumOfLeft;
			}
		}
		return result;	
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileInputStream("Input.txt"));
		Integer testCases = in.nextInt();
		for(Integer index = 0; index < testCases; index++)
		{
			n = in.nextInt();
			sumOfAll = Integer.valueOf(0);
			for(Integer inputIndex = 0; inputIndex < n; inputIndex++)
			{
				inputArray[inputIndex] = in.nextInt();
				sumOfAll += inputArray[inputIndex];
			}
			
			if(sherlockFunction())
			{
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
		in.close();
	}
}