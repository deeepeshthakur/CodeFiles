import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class KnightLOnAChessBoard {
	static LinkedList<Integer> currentQueue = new LinkedList<Integer>();
	static Integer[][] currentConditionMatrix = new Integer[25][25];

	static void modifiedBFS( Integer a, Integer b, Integer n)
	{
		if(!currentQueue.isEmpty())
		{
			Integer currHead = currentQueue.poll();
			Integer[][] possibleNextStep = new Integer[8][2];
			Integer currX = currHead/n, currY = currHead%n;

			possibleNextStep[0][0] = currX - a;
			possibleNextStep[0][1] = currY - b;
			possibleNextStep[1][0] = currX - a;
			possibleNextStep[1][1] = currY + b;
			possibleNextStep[2][0] = currX + a;
			possibleNextStep[2][1] = currY - b;
			possibleNextStep[3][0] = currX + a;
			possibleNextStep[3][1] = currY + b;
			possibleNextStep[4][0] = currX - b;
			possibleNextStep[4][1] = currY - a;
			possibleNextStep[5][0] = currX - b;
			possibleNextStep[5][1] = currY + a;
			possibleNextStep[6][0] = currX + b;
			possibleNextStep[6][1] = currY - a;
			possibleNextStep[7][0] = currX + b;
			possibleNextStep[7][1] = currY + a;

			for(Integer index = 0; index < 8; index++)
			{
				if((possibleNextStep[index][0] >= 0 && possibleNextStep[index][0] < n)&&(possibleNextStep[index][1] >= 0 && possibleNextStep[index][1] < n))
				{
					if(currentConditionMatrix[possibleNextStep[index][0]][possibleNextStep[index][1]] == -1)
					{
						currentConditionMatrix[possibleNextStep[index][0]][possibleNextStep[index][1]] = currentConditionMatrix[currX][currY] + 1;
						Integer temp = (possibleNextStep[index][0]*n) + possibleNextStep[index][1];
						currentQueue.add(temp);
					}
				}
			}
			modifiedBFS(a, b, n);
		}
	}

	static Integer[][] knightLFunc(Integer n)
	{
		Integer result[][] = new Integer[n - 1][n - 1];
		for(Integer a = 1; a <= result.length; a++)
		{
			for(Integer b = 1; b <= result.length; b++)
			{
				for(Integer indexX = 0; indexX < n; indexX++)
				{
					for(Integer indexY = 0; indexY < n; indexY++)
					{
						currentConditionMatrix[indexX][indexY] = -1;
					}
				}

				currentConditionMatrix[0][0] = 0;
				currentQueue.clear();
				currentQueue.add(0);
				modifiedBFS( a, b, n);
				result[a-1][b-1] = currentConditionMatrix[n-1][n-1];
			}
		}

		return result;
	}

	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner( new FileInputStream("Input.txt"));
		Integer n = in.nextInt();
		Integer result[][] = new Integer[n - 1][n - 1];
		result = knightLFunc( n);
		for(Integer x = 0; x < n - 1; x++)
		{
			for(Integer y = 0; y < n - 1; y++)
			{
				System.out.print(result[x][y] + " ");
			}
			System.out.print("\n");
		}
		 in.close();
	}
}
