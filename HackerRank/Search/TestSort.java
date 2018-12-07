import java.util.Arrays;
import java.util.Comparator;

public class TestSort {
    private static void printTable(String caption, Integer[] orderArray, 
                Integer[] arrayToBeSorted, Integer[] sortOrder){

        System.out.println(caption+
                "\nNo   Num   Color"+
                "\n----------------");

        for(int i=0;i<sortOrder.length;i++){
            System.out.printf("%x    %d     %d\n", 
                    i,orderArray[sortOrder[i]],arrayToBeSorted[sortOrder[i]]);

        }
        
        for(int i=0; i<sortOrder.length; i++){
            System.out.println("SortOrder:"+sortOrder[i]);
        }
    }

    public static void main(String[] args) {

        final Integer[] orderArray = {58, 41, 56, 100};
        final Integer[] arrayToBeSorted  = {40, 50, 20, 10};
        Integer[] sortOrder = new Integer[orderArray.length];

        // Create index array.
        for(int i=0; i<sortOrder.length; i++){
            sortOrder[i] = i;
        }
        printTable("\nNot sorted",orderArray, arrayToBeSorted, sortOrder);

        Arrays.sort(sortOrder,new Comparator<Integer>() {   
            public int compare(Integer a, Integer b){
            	System.out.println(":"+(orderArray[a]-orderArray[b]));
                return orderArray[a]-orderArray[b];
            }});
        printTable("\nSorted by orderArray",orderArray, arrayToBeSorted, sortOrder);
    }
}