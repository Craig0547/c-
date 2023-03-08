import java.util.Scanner;

public class MyClass {
    public static void main(String args[]) {
        Scanner scanner=new Scanner(System.in);
    System.out.println("Podaj pierwsza liczbe");
    
    float a=scanner.nextFloat();
    System.out.println("Podaj druga liczbe");
    float b=scanner.nextFloat();
      System.out.println("Suma: " + (a+b));
    }
}
