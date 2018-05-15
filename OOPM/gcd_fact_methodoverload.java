import java.util.*;

/// Program which demonstrates method overloading

class Calc
{
	int n, n1, n2;

	Calc()
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("\nSpecify no. for Factorial Calculation\n");
		n = scan.nextInt();
		System.out.println("\nSpecify two numbers for GCD Evaluation\n");
		n1 = scan.nextInt();
		n2 = scan.nextInt();
	}

	int calculate(int x)
	{
		if(x>0)
			return x*calculate(x-1);
		else
			return 1;
	}

	int calculate(int x, int y)
	{
		if(x%y==0)
			return y;
		else
			return calculate(y,x%y);
	}
}

class CalcDemo
{
	public static void main(String args[])
	{
		Calc c = new Calc();
		int fact = c.calculate(c.n);
		int gcd = c.calculate(c.n1,c.n2);
		System.out.println("\nFactorial of " + c.n + " is : " + fact);
		System.out.println("\nGCD of " + c.n1 + " & " + c.n2 + " is : " + gcd + "\n");
	}
}
