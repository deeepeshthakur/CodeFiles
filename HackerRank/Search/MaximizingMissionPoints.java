import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.io.*;

public class MaximizingMissionPoints{
	private static Integer N = Integer.valueOf(0),
			dlat = Integer.valueOf(0),
			dlong = Integer.valueOf(0);
	private static Integer indexArrayToBeSortedPosition[] = new Integer[200000],
			indexArrayToBeSortedHeight[] = new Integer[200000],
			latitudeArray[] = new Integer[200000],
			sortedLatitude[] = new Integer[200000],
			longitudeArray[] = new Integer[200000],
			sortedLongitude[] = new Integer[200000],
			pointsArray[] = new Integer[200000],
			heightsArray[] = new Integer[200000],
			pointsCountingArray[] = new Integer[200000];

	private static Long callFunctionLat(){
		// System.out.println("Checkpoint1");
		Arrays.sort(indexArrayToBeSortedPosition, 0, N, new Comparator<Integer>() {
				public int compare(Integer a, Integer b){
					// System.out.println(a +"--" +  latitudeArray[a] + "    " + b + "--" + latitudeArray[b]);
					if(latitudeArray[a] > latitudeArray[b])
						return 1;
					if(latitudeArray[a] < latitudeArray[b])
						return -1;
					return 0;
				}
		});

		// System.out.println("Checkpoint2");

		// for(Integer index = 0; index < N; index++)
		// {
		// 	System.out.println(indexArrayToBeSortedPosition[index]);
		// }
		// System.out.println("");

		for(Integer index = N-1; index >= 0; index--){
			System.out.println(index);
			Integer currIndex = indexArrayToBeSortedHeight[index];
			Integer currLatitude = latitudeArray[currIndex];
			Integer currLongitude = longitudeArray[currIndex];
			Integer currHeight = heightsArray[currIndex];
			Integer currAdditional = pointsCountingArray[currIndex];
			Integer currPoints = pointsArray[currIndex];
			// Integer.valueOf(Math.abs(longitudeArray[currTempIndex] - currLongitude));
			Integer indexInSortedLatitude = Arrays.binarySearch( sortedLatitude, 0, N, currLatitude);
			for(Integer innerCounter = indexInSortedLatitude + 1; innerCounter < N && (sortedLatitude[innerCounter] - currLatitude <= dlat); innerCounter++){
				Integer currTempIndex = indexArrayToBeSortedPosition[innerCounter];
				if(Integer.valueOf(Math.abs(longitudeArray[currTempIndex] - currLongitude)) <= dlong && heightsArray[currIndex] > heightsArray[currTempIndex]){
					if(pointsCountingArray[currTempIndex] < (pointsCountingArray[currIndex] + pointsArray[currIndex])){
						pointsCountingArray[currTempIndex] = pointsCountingArray[currIndex] + pointsArray[currIndex];
					}
				}
			}

			for(Integer innerCounter = indexInSortedLatitude - 1; innerCounter >= 0 && (currLatitude - sortedLatitude[innerCounter] <= dlat); innerCounter--){
				Integer currTempIndex = indexArrayToBeSortedPosition[innerCounter];
				if(Integer.valueOf(Math.abs(longitudeArray[currTempIndex] - currLongitude)) <= dlong && heightsArray[currIndex] > heightsArray[currTempIndex]){
					if(pointsCountingArray[currTempIndex] < (pointsCountingArray[currIndex] + pointsArray[currIndex])){
						pointsCountingArray[currTempIndex] = pointsCountingArray[currIndex] + pointsArray[currIndex];
					}
				}
			}
		}
		Long ans = Long.valueOf(0);
		for(Integer index = 0; index < N; index++)
		{
			if(ans < Long.valueOf(pointsArray[index] + pointsCountingArray[index])){
				ans = Long.valueOf(pointsArray[index] + pointsCountingArray[index]);
			}
		}

		return ans;
	}

	private static Long callFunctionLong(){
		Arrays.sort(indexArrayToBeSortedPosition, 0, N, new Comparator<Integer>() {
				public int compare(Integer a, Integer b){
					if(longitudeArray[a] > longitudeArray[b])
						return 1;
					if(longitudeArray[a] < longitudeArray[b])
						return -1;
					return 0;
				}
		});

		for(Integer index = N-1; index >= 0; index--){
			Integer currIndex = indexArrayToBeSortedHeight[index];
			Integer currLatitude = latitudeArray[currIndex];
			Integer currLongitude = longitudeArray[currIndex];
			Integer currHeight = heightsArray[currIndex];
			Integer currAdditional = pointsCountingArray[currIndex];
			Integer currPoints = pointsArray[currIndex];

			Integer indexInSortedLongitude = Arrays.binarySearch( sortedLongitude, 0, N, currLongitude);
			for(Integer innerCounter = indexInSortedLongitude + 1; innerCounter < N && (sortedLongitude[innerCounter] - currLongitude <= dlong); innerCounter++){
				Integer currTempIndex = indexArrayToBeSortedPosition[innerCounter];
				if(latitudeArray[currTempIndex] - currLatitude <= dlat && heightsArray[currIndex] > heightsArray[currTempIndex]){
					if(pointsCountingArray[currTempIndex] < (pointsCountingArray[currIndex] + pointsArray[currIndex])){
						pointsCountingArray[currTempIndex] = pointsCountingArray[currIndex] + pointsArray[currIndex];
					}
				}
			}

			for(Integer innerCounter = indexInSortedLongitude - 1; innerCounter >= 0 && (currLongitude - sortedLongitude[innerCounter] <= dlong); innerCounter--){
				Integer currTempIndex = indexArrayToBeSortedPosition[innerCounter];
				if(latitudeArray[currTempIndex] - currLatitude <= dlat && heightsArray[currIndex] > heightsArray[currTempIndex]){
					if(pointsCountingArray[currTempIndex] < (pointsCountingArray[currIndex] + pointsArray[currIndex])){
						pointsCountingArray[currTempIndex] = pointsCountingArray[currIndex] + pointsArray[currIndex];
					}
				}
			}
		}
		Long ans = Long.valueOf(0);
		for(Integer index = 0; index < N; index++)
		{
			if(ans < Long.valueOf(pointsArray[index] + pointsCountingArray[index])){
				ans = Long.valueOf(pointsArray[index] + pointsCountingArray[index]);
			}
		}

		return ans;
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileInputStream("Input.txt"));
		// PrintStream o = new PrintStream(new File("Output.txt"));
		// System.setOut(o);
		Long ans = Long.valueOf(0);
		N = in.nextInt();
		dlat = in.nextInt();
		dlong = in.nextInt();
		// System.out.println("Start");
		for(Integer index = 0; index < N; index++) {
			indexArrayToBeSortedPosition[index] = index;
			indexArrayToBeSortedHeight[index] = index;
			latitudeArray[index] = in.nextInt();
			sortedLatitude[index] = latitudeArray[index];
			longitudeArray[index] = in.nextInt();
			sortedLongitude[index] = longitudeArray[index];
			heightsArray[index] = in.nextInt();
			pointsArray[index] = in.nextInt();
			pointsCountingArray[index] = Integer.valueOf(0);
		}

		Arrays.sort(indexArrayToBeSortedHeight, 0, N, new Comparator<Integer>(){
			public int compare(Integer a, Integer b){
				if(heightsArray[a] > heightsArray[b])
					return 1;
				if(heightsArray[a] < heightsArray[b])
					return -1;
				return 0;
			}
		});

		Arrays.sort(sortedLatitude, 0, N);
		Arrays.sort(sortedLongitude, 0, N);

		ans = callFunctionLat();
		// for(Integer index = 0; index < N; index++)
		// {
		// 	System.out.println(pointsCountingArray[indexArrayToBeSortedHeight[index]]);
		// }

		System.out.println(ans);
		in.close();
	}
}
