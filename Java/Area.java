import java.util.*;

abstract class Shape
{
    abstract void calculateArea(double a, double b);
    abstract void display();
}

class Rectangle extends Shape
{
    double area;
    
    void calculateArea(double a, double b)
    {
        area = (a * b);
    }
    
    void display()
    {
        System.out.println("Area of Rectangle is : " + area);
    }
}

class Triangle extends Shape
{
    double area;

    void calculateArea(double a, double b)
    {
        area = (0.5 * a * b);
    }

    void display()
    {
        System.out.println("Area of Triangle is : " + area);
    }
}

class Area
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        Shape s;
        Rectangle r = new Rectangle();
        Triangle t = new Triangle();

        s = r;
        System.out.println("\nEnter Length and Breadth of Rectangle :");
        double l = sc.nextDouble();
        double b = sc.nextDouble();
        s.calculateArea(l, b);
        s.display();

        s = t;
        System.out.println("\nEnter Base and Height of Triangle :");
        b = sc.nextDouble();
        double h = sc.nextDouble();
        s.calculateArea(b, h);
        s.display();
    }
}