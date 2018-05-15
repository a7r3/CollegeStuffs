import java.util.*;

/// Program which collects and prints details of 'n' number of students

class Student
{
	String name;
	int p,c,m,rno;

	void acceptDetails()
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter name of Student : ");
		name=scan.nextLine();
		System.out.println("Specify Roll No : ");
		rno=scan.nextInt();
		System.out.println("Specify PCM Marks (one-by-one)\n");
		p=scan.nextInt();
                c=scan.nextInt();
                m=scan.nextInt();
		System.out.println("Details for student " + name + " Recorded successfully");
	}

	void printDetails()
	{
		System.out.println("\nName : " + name);
		System.out.println("Roll No : " + rno);
		System.out.println("Physics : " + p);
		System.out.println("Chemistry : " + c);
		System.out.println("Maths : " + m);
		System.out.println("\n");
	}
}

class StudentDemo
{
	public static void main(String args[])
	{
		int i;
		Student[] s = new Student[10];
		System.out.println("\n[!] Specify the number of Students\n");
		Scanner sc = new Scanner(System.in);
		int no = sc.nextInt();
		for(i=0;i<no;i++)
		{
			s[i] = new Student();
			s[i].acceptDetails();
		}
		System.out.println("\n\n[!] Printing Student Database\n\n");
		for(i=0;i<no;i++)
			s[i].printDetails();
	}
}
