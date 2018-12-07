import java.util.*;
import java.math.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;

public class ShortPalindrome{
	
	private static Integer modul = Integer.valueOf(1000000007);
	private static Integer N = Integer.valueOf(0);
	private static String inputString = new String();
	private static Long leftXY[][][] = new Long[1000000][26][26];
	private static Long rightXY[][][] = new Long[1000000][26][26];
	private static Long rightDashXY[][][] = new Long[1000000][26][26];
	private static Integer modifiedInput[][] = new Integer[26][1000000];
	private static Integer lastElement[] = new Integer[26];
	
	static void fillTableLeftXY()
	{
		for(Integer index = 0; index < N; index++)
		{
			for(Integer y = 0; y < 26; y++)
			{
				Integer yValue = Integer.valueOf('a') + y;
				if((Integer.valueOf(inputString.charAt(index))).equals(yValue))
				{
					for(Integer x = 0; x < 26; x++)
					{
						Integer insertPoint = Arrays.binarySearch( modifiedInput[x], 0, lastElement[x], index);
						if(insertPoint < 0)
						{
							insertPoint = (insertPoint*Integer.valueOf(-1)) - 1;
						}
						else {
							insertPoint -= Integer.valueOf(-1);
						}
						
						if(insertPoint > Integer.valueOf(0))
						{
							leftXY[index][y][x] = Long.valueOf(insertPoint + 1);
						}
						else {
							leftXY[index][y][x] = Long.valueOf(0); 
						}
					}
				}
				else {
					for(Integer x = 0; x < 26; x++)
					{
						leftXY[index][y][x] = Long.valueOf(0);
					}
				}
			}
		}
	}
	
	static void fillTableRightDashXY() {
		
		for(Integer index = 0; index < N; index++)
		{
			for(Integer y = 0; y < 26; y++)
			{
				Integer yValue = Integer.valueOf('a') + y;
				if(index < N - 1)
				{
					if((Integer.valueOf(inputString.charAt(index + 1))).equals(yValue)) {
						for(Integer x = 0; x < 26; x++)
						{
							Integer insertPoint = Arrays.binarySearch(modifiedInput[x], 0, lastElement[x], index + 1);
							if(insertPoint >= Integer.valueOf(0))
							{
								insertPoint = lastElement[x] - insertPoint;
							}
							else {
								insertPoint = Integer.valueOf(-1)*(insertPoint + 1);
								insertPoint = lastElement[x] - insertPoint + 1;
							}
							
							rightDashXY[index][y][x] = Long.valueOf(insertPoint);
						}
					}
					else {
						for(Integer x = 0; x < 26; x++)
						{
							rightDashXY[index][y][x] = Long.valueOf(0);
						}
					}
				}
				else {
					for(Integer x = 0; x < 26; x++)
					{
						rightDashXY[index][y][x] = Long.valueOf(0);
					}
				}
			}
		}
	}
	
	static void fillTableRightXY() {
		for(Integer y = 0; y < 26; y++)
		{
			for(Integer x = 0; x < 26; x++)
			{
				rightXY[N-1][y][x] = Long.valueOf(0);
			}
		}
		
		for(Integer index = N - 2; index >= Integer.valueOf(0); index--)
		{
			for(Integer y = 0; y < 26; y++)
			{
				for(Integer x = 0; x < 26; x++)
				{
					rightXY[index][y][x] = (rightDashXY[index][y][x] + rightXY[index][y][x])%modul;
				}
			}
		}
		
	}
	
	static Long calculateAns() {
		Long ans = Long.valueOf(0);
		for(Integer index = 0; index < N; index++) {
			for(Integer y = 0; y < 26; y++)
			{
				for(Integer x = 0; x < 26; x++) {
					ans = (ans + Long.valueOf(leftXY[index][y][x]*rightDashXY[index][y][x]))%modul;
				}
			}
		}
		return ans;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner( new FileInputStream("Input.txt"));
		for(Integer index = 0; index < 26; index++)
		{
			lastElement[index] = Integer.valueOf(0);
		}
		
		inputString = in.next();
		N = inputString.length();
		Integer aValue = Integer.valueOf('a');
		for(Integer index = 0; index < N; index++)
		{
			Integer temp = Integer.valueOf(inputString.charAt(index));
			modifiedInput[temp - aValue][lastElement[temp - aValue]++] = index;			
		}
		
		fillTableLeftXY();
		fillTableRightDashXY();
		fillTableRightXY();
		
		Long ans = calculateAns();
		System.out.println(ans + "glsflsflsj");		
		in.close();
	}
}