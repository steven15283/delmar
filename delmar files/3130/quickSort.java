import java.util.Random;

public class quickSort {

	 /* This function takes last element as pivot, 
	       places the pivot element at its correct 
	       position in sorted array, and places all 
	       smaller (smaller than pivot) to left of 
	       pivot and all greater elements to right 
	       of pivot */
	    int partition(int arr[], int low, int high) 
	    { 
	        int pivot = arr[high];  
	        int i = (low-1); // index of smaller element 
	        for (int j=low; j<high; j++) 
	        { 
	            // If current element is smaller than or 
	            // equal to pivot 
	            if (arr[j] <= pivot) 
	            { 
	                i++; 
	  
	                // swap arr[i] and arr[j] 
	                int temp = arr[i]; 
	                arr[i] = arr[j]; 
	                arr[j] = temp; 
	            } 
	        } 
	  
	        // swap arr[i+1] and arr[high] (or pivot) 
	        int temp = arr[i+1]; 
	        arr[i+1] = arr[high]; 
	        arr[high] = temp; 
	  
	        return i+1; 
	    } 
	  
	  
	    /* The main function that implements QuickSort() 
	      arr[] --> Array to be sorted, 
	      low  --> Starting index, 
	      high  --> Ending index */
	    void sort(int arr[], int low, int high) 
	    { 
	        if (low < high) 
	        { 
	            /* pi is partitioning index, arr[pi] is  
	              now at right place */
	            int pi = partition(arr, low, high); 
	  
	            // Recursively sort elements before 
	            // partition and after partition 
	            sort(arr, low, pi-1); 
	            sort(arr, pi+1, high); 
	        } 
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
	        quickSort ob = new quickSort(); 
	        ob.sort(randArray(SIZE, arr1),0,arr1.length-1);
	        System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for random array with 1000 elements");
		      time = System.nanoTime();
		      ob.sort(randArray(SIZE1, arr2),0,arr2.length-1);
	        System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for random array with 10000 elements");
		      time = System.nanoTime();
		      ob.sort(randArray(SIZE2, arr3),0,arr3.length-1);
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for random array with 100000 elements");
		      time = System.nanoTime();
		      ob.sort(sortedArray(SIZE, arr1),0,arr1.length-1);
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for sorted array with 1000 elements");
		      time = System.nanoTime();
		      ob.sort(sortedArray(SIZE1, arr2),0,arr2.length-1);
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for sorted array with 10000 elements");
		      time = System.nanoTime();
		     
		      ob.sort(almostSortedArray(SIZE, arr1),0,arr1.length-1);
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for almost sorted array with 1000 elements");
		      time = System.nanoTime();
		      ob.sort(almostSortedArray(SIZE1, arr2),0,arr2.length-1);
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for almost sorted array with 10000 elements");
		      time = System.nanoTime();
		      ob.sort(almostSortedArray(SIZE2, arr3),0,arr3.length-1);
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for almost sorted array with 100000 elements");
		      time = System.nanoTime();
		      ob.sort(sortedArray(SIZE2, arr3),0,arr3.length-1);
		      System.out.println("It took " + ((System.nanoTime() - time)/1e-9) + " seconds for sorted array with 100000 elements");
		      time = System.nanoTime();

	    }

}
