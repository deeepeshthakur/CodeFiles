import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class MissingNumbers{
	private static Integer rawListOne[] = new Integer[202];
	private static Integer rawListTwo[] = new Integer[202];
	private static Integer listOne[] = new Integer[101];
	private static Integer listTwo[] = new Integer[101];
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner( new FileInputStream("Input.txt"));
		for(Integer index = 0; index < 202; index++)
		{
			rawListOne[index] = 0;
			rawListTwo[index] = 0;
			if(index < 101)
			{
				listOne[index] = 0;
				listTwo[index] = 0;
			}
		}
		Integer N = in.nextInt();
		Integer midValue = in.nextInt();
		rawListOne[101]++;
		
		for(Integer index = 1; index < N; index++)
		{
			Integer temp = in.nextInt();
			rawListOne[101 - midValue + temp]++;			
		}
		
		Integer M = in.nextInt();
		for(Integer index = 0; index < M; index++)
		{
			Integer temp = in.nextInt();
			rawListTwo[101 + temp - midValue]++;
		}
		
		Boolean flag = true;
		Integer counter = 0;
		while(flag)
		{
			if(rawListTwo[counter] == Integer.valueOf(0))
			{
				counter++;
			}
			else {
				flag = false;
			}			
		}
		Integer minValue = midValue - 101 + counter;
		for(Integer index = 0; index < 101; index++)
		{
			listOne[index] = rawListOne[index + counter];
			listTwo[index] = rawListTwo[index + counter];
		}
		
		for(Integer index = 0; index < 101; index++)
		{
			if(!listOne[index].equals(listTwo[index]))
			{
				System.out.print((minValue + index) + " ");
			}
		}
		
		
		in.close();
	}
}