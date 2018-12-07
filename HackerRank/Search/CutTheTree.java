import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class CutTheTree{
	private static Integer N = Integer.valueOf(0);
	private static Integer sumOfNodes = Integer.valueOf(0);
	private static Integer nodeArray[] = new Integer[100000];
	private static Integer sumNode[] = new Integer[100000];
	private static ArrayList<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
	private static Boolean dfsCheck[] = new Boolean[100000];
	
	static Integer modifiedDFS( Integer index, Integer currMin) {
		dfsCheck[index] = Boolean.valueOf(true);
		Integer currNodeSum = nodeArray[index];
		Iterator<Integer> iter = edges.get(index).iterator();
		while(iter.hasNext())
		{
			Integer nextEdge = iter.next();
			if(dfsCheck[nextEdge].equals(Boolean.valueOf(false)))
			{
				currMin = modifiedDFS( nextEdge, currMin);
				currNodeSum += sumNode[nextEdge];
			}
			
		}
		Integer sumOfTreeOne = currNodeSum;
		Integer sumOfTreeTwo = sumOfNodes - sumOfTreeOne;
		Integer diff = Integer.valueOf(Math.abs(sumOfTreeOne - sumOfTreeTwo));
		sumNode[index] = currNodeSum;
		if(diff < currMin) {
			currMin = diff;
		}
		return currMin;
	}
	
	
	
	static Integer cutTheTree() {
		Integer result = Integer.valueOf(0);
		result = sumOfNodes;
		for(Integer index = 0; index < N; index++)
		{
			sumNode[index] = Integer.valueOf(0);
			dfsCheck[index] = Boolean.valueOf(false);
		}
		result = modifiedDFS( 0, result);		
		return result;
	}
	
	public static void main(String[] agrs) throws IOException {
		Scanner in = new Scanner(new FileInputStream("Input.txt"));
		N = in.nextInt();
		for(Integer index = 0; index < N; index++)
		{
			nodeArray[index] = in.nextInt();
			sumOfNodes += nodeArray[index];
		}
		Integer edgeArray[][] = new Integer[N-1][2];
		for(Integer index = 0; index < N-1; index++)
		{
			edgeArray[index][0] = in.nextInt() - 1;
			edgeArray[index][1] = in.nextInt() - 1;
		}
		
		for(Integer index = 0; index < N; index++)
		{
			edges.add(new ArrayList<Integer>());
		}
		
		for(Integer index = 0; index < N-1; index++)
		{
			edges.get(edgeArray[index][0]).add(edgeArray[index][1]);
			edges.get(edgeArray[index][1]).add(edgeArray[index][0]);			
		}
		Integer ans = cutTheTree();
		System.out.println(ans);		
		in.close();
	}
}