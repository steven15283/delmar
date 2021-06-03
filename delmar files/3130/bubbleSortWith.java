import java.util.Random;

public class bubbleSortWith {

	


		static int sort(int arr[]) 
	    { 
			int count=0;
	        int n = arr.length; 
	        for (int i = 0; i < n-1; i++) 
	            for (int j = 0; j < n-i-1; j++) 
	                if (arr[j] > arr[j+1]) 
	                { 
	                    // swap arr[j+1] and arr[i] 
	                	count++;
	                    int temp = arr[j]; 
	                    arr[j] = arr[j+1]; 
	                    arr[j+1] = temp; 
	                } 
	        return count;
	    } 
			
		 public static int[] randArray(int size, int[] arr)
	     {
	   	  Random rand = new Random();
	   	  int number;
	   	  for(int i = 0; i < size-1; i++)
	         {
	             number = rand.nextInt(10000)+1;
	             arr[i] = number;  
	         }
	   	  return arr;
	   	  
	     }
	     
	     public static int[] sortedArray(int size, int[] arr)
	     {
	   	  for(int i = 0; i < size-1; i++)
	         {
	             arr[i] = i;  
	         }
	   	  return arr;
	   	  
	     }
	     
	     public static int[] almostSortedArray(int size, int[] arr)
	     {
	   	  Random rand = new Random();
	   	  for(int i = 0; i < size-1; i++)
	         {
	   		  if(i%10==0)
	   		  {
	   			  arr[i] = rand.nextInt(10000)+1;
	   		  }
	   		  else
	   		  {
	   			   arr[i] = i; 
	   		  }
	             
	           
	         }
	   	  return arr;
	   	  
	     }

	     public static void main(String arr[])
	     {
	   	  final int SIZE = 1000;
	   	  final int SIZE1 = 10000;
	   	  final int SIZE2 = 100000;
	   	  long time = System.nanoTime();
	   	  
	         int[] arr1 = new int[SIZE];
	         int[] arr2 = new int[SIZE1];
	         int[] arr3 = new int[SIZE2];
	          int countSwap;
	          countSwap=sort(randArray(SIZE, arr1));
	          System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for random array with 1000 elements also with " + countSwap +" swaps");
		      time = System.nanoTime();
		      countSwap=sort(randArray(SIZE1, arr2));
	          System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for random array with 10000 elements also with " + countSwap + " swaps");
		      time = System.nanoTime();
		      countSwap=sort(randArray(SIZE2, arr3));
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for random array with 100000 elements also with "+ countSwap + " swaps");
		      time = System.nanoTime();
		      countSwap=sort(sortedArray(SIZE, arr1));
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for sorted array with 1000 elements also with "+ countSwap + " swaps");
		      time = System.nanoTime();
		      countSwap=sort(sortedArray(SIZE1, arr2));
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for sorted array with 10000 elements also with "+ countSwap + " swaps");
		      time = System.nanoTime();
		      countSwap=sort(sortedArray(SIZE2, arr3));
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for sorted array with 100000 elements also with "+ countSwap + " swaps");
		      time = System.nanoTime();
		      countSwap=sort(almostSortedArray(SIZE, arr1));
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for almost sorted array with 1000 elements also with "+ countSwap + " swaps");
		      time = System.nanoTime();
		      countSwap=sort(almostSortedArray(SIZE1, arr2));
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for almost sorted array with 10000 elements also with "+ countSwap + " swaps");
		      time = System.nanoTime();
		      countSwap=sort(almostSortedArray(SIZE2, arr3));
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for almost sorted array with 100000 elements also with "+ countSwap + " swaps");
		      time = System.nanoTime();
	        

	     }

}
