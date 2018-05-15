import java.util.*;

/// Program to perform Insertion Sort

class insertSort
{
	public static void main(String args[])
	{
		int a[]= new int[20];
		int tempval, tempadd,i, j, k;
		Scanner sc = new Scanner(System.in);
		System.out.println("Specify the number of elements\n");
		int number = sc.nextInt();
		for (i=0;i<number; i++)
			a[i] = sc.nextInt();
		System.out.println("[!] Performing Insertion Sort\n");
		for (i=0;i<number;i++)
		{
				tempval=a[i];
				j=i-1;
				for (j=i-1;j>0;j--)
				{
					if (a[j] > tempval)
					{
						for(k=i-1;k>j;k--)
							a[k+1]=a[k];
					}
				}
				a[j+1]=tempval;
		}
		System.out.println("[!] Printing Elements of  Sorted array\n");
		for (i=0; i<number; i++)
			System.out.println(a[i]);
		System.out.println("[!] Meh\n");
	}
}
