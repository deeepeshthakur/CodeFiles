import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class ConnectedCellsInAGrid{
	private static Integer inputGrid[][] = new Integer[10][10];
	private static Integer cellsCounter = 0;
	private static Integer N = Integer.valueOf(0), M = Integer.valueOf(0);	
	
	static void DFS(Integer x, Integer y) {
		cellsCounter++;
		inputGrid[x][y] = -1;
		Integer potentialNextStep[][] = new Integer[8][2];
		potentialNextStep[0][0] = x;
		potentialNextStep[0][1] = y - 1;
		potentialNextStep[1][0] = x;
		potentialNextStep[1][1] = y + 1;
		potentialNextStep[2][0] = x - 1;
		potentialNextStep[2][1] = y;
		potentialNextStep[3][0] = x + 1;
		potentialNextStep[3][1] = y;
		potentialNextStep[4][0] = x - 1;
		potentialNextStep[4][1] = y - 1;
		potentialNextStep[5][0] = x - 1;
		potentialNextStep[5][1] = y + 1;
		potentialNextStep[6][0] = x + 1;
		potentialNextStep[6][1] = y - 1;
		potentialNextStep[7][0] = x + 1;
		potentialNextStep[7][1] = y + 1;
		
		for(Integer index = 0; index < 8; index++) {
			Integer xTemp = potentialNextStep[index][0], yTemp = potentialNextStep[index][1];
			if(xTemp >= 0 && xTemp < N && yTemp >= 0 && yTemp < M)
			{
				if(inputGrid[xTemp][yTemp].equals(1))
				{
					DFS( xTemp, yTemp);
				}
			}
		}
	}
	
	static Integer connectedCellsFunction( Integer n, Integer m) {
		Integer result = 0;
		for(Integer x = 0; x < n; x++)
		{
			for(Integer y = 0; y < m; y++)
			{
				if(inputGrid[x][y].equals(1))
				{
					cellsCounter = 0;
					DFS( x, y);
				}
				if(cellsCounter > result)
				{
					result = cellsCounter;
				}
			}
		}
		return result;
	}
 	
	public static void main(String[] agrs) throws IOException {
		Scanner in = new Scanner( new FileInputStream("Input.txt"));
		N = in.nextInt();
		M = in.nextInt();
		
		for(Integer x = 0; x < N; x++)
		{
			for(Integer y = 0; y < M; y++)
			{
				inputGrid[x][y] = in.nextInt();
			}
		}
		
		System.out.println(connectedCellsFunction( N, M));
		in.close();
	}
}