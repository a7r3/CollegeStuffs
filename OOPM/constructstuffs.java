import java.util.*;

/// Program which deals with Constructor Usage (Basic/Parameterized/Copy) and Constructor (and Method) Overloading

class Circle
{
	float r, pi;

	Circle()
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("\nSpecify the Radius\n");
		r=scan.nextFloat();
		System.out.println("\nSpecify the Pi value\n");
		pi=scan.nextFloat();
	}

	Circle(float rad, float pie)
	{
		r=rad;
		pi=pie;
	}

	Circle(Circle c)
	{
		r=c.r;
		pi=c.pi;
	}

	double area()
	{
		return pi*r*r;
	}

	float area(float rad, float pie)
	{
		return pie*rad*rad;
	}

	double area(Circle x)
	{
		return (x.r)*(x.r)*(x.pi);
	}

}

class CircleDemo
{
	public static void main(String args[])
	{
		// Initialzing an Object c of Class 'Circle' - Calling the Default Constructor
		// Values are fetched from user
		Circle c = new Circle();
		// Calling area() with Default Constructor Values
		// Values were fetched from user in Object creation
		double a = c.area();
		// Initializing an Object c1 of Class 'Circle' - Calling the Parametrized Constructor explicitly
		Circle c1 = new Circle(10f,3.14f);
		// Calling Area method with parameters from object c1
		// Which is already specified in Object Creation
		double a1 = c1.area();
		// Initializing an Object c2 of Class 'Circle'
		// Copying the Object Data from object c to this object
		Circle c2 = new Circle(c);
		// Calling area method with no parameters
		// Observation : a2 equals a
		double a2 = c2.area();
		// Calling area method with two parameters
		// Method Overloading :D
		float a3 = c1.area(100f,3.14564f);
		// Calling area method with values from Default Constructor
		// Observation : a4 equals a2 (Copy) OR a (Default)
		double a4 = c.area(c);
		// Calling area method with values from Parametrized Constructor
		// Observation : a5 equals a1
		double a5 = c1.area(c1);
		System.out.println("\n================== Constructor ==================\n");
		System.out.println("Default Constructor : " + a);
		System.out.println("\nParameterized Constructor : " + a1);
		System.out.println("\nParameterized Constructor : Method Overload : " + a3);
		System.out.println("\nCopy Constructor (Copy of Default Constructor) : " + a2);
		System.out.println("\nPassing Object c to Method area(): " + a4);
		System.out.println("\nPassing Object c1 to Method area(): " + a5);
		System.out.println("\n=================================================\n");
	}
}
