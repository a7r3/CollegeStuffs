import java.util.*;
/// Program to perform Bubble Sort

class bubbleSort
{
	public static void main(String args[])
	{
		/* Initialize Array with 20 integer elements */
		int array[]= new int[20];
		Scanner sc = new Scanner(System.in);
		int i, t, j;
		System.out.println("Specify the number of elements\n");
		int number = sc.nextInt();
		for (i=0;i<number; i++)
			array[i] = sc.nextInt();
		for (i=0; i<number-1; i++)
		{
			for (j=0; j<number-1-i; j++)
			{
				if(array[j]>array[j+1])
				{
					t = array[j];
					array[j] = array[j+1];
					array[j+1] = t;
				}
			}
		}
		System.out.println("[!] Printing Elements of (bubble) Sorted array\n");
		for (i=0; i<number; i++)
			System.out.println(array[i]);
		System.out.println("[!] Meh\n");
	}
}
