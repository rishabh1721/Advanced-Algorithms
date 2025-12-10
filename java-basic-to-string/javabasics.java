
import java.util.*;

public class javabasics{
  public static void printHelloWorld(){
    System.out.println("hello world");
  }
  public static int calculateSum(int num1 , int num2){
    
    int sum = num1 + num2;
    return sum;
  }
  public static void swap(int a , int b){
    int temp = a;
    a = b;
    b = temp;
    System.out.println(a);
    System.out.println(b);
  }

  public static int multiply(int a , int b){
    int product = a * b;
    return product;

  }
  public static int factorial(int n){
    int f = 1;
    for(int i =1; i<=n; i++){
      f = f*i;
    } return f;
  }
  public static int binco(int n , int r) {
    
    int n_fact = factorial(n);
    int r_fact = factorial(r);
    int s_fact = factorial(n-r);
    int res = n_fact / (r_fact * (s_fact));
    return res;
  }
  // public static int sum(int a , int b){
  // return a+b;
  // }

  public static int sum(int a , int b , int c){
    return a + b + c;
  }
   
  public static int sum(int a , int b){
    return a + b;
  }
  public static float sum(float a , float b){
    return a + b;
  }

  public static boolean isPrime(int n){
    boolean isPrime = true;
    for(int i = 2 ; i<=Math.sqrt(n); i++){
      if(n % i == 0){
        isPrime = false;
      }
    }
    return isPrime;
  } 

  public static void primesinRange(int n){
    for(int i = 2 ; i<=n; i++){
      if(isPrime(i) == true){
        System.out.print(i);
      }
    } System.out.println();

  }

  public static void binToDec(int binNum){
    int myNum = binNum;
    int pow = 0;
    int decNum = 0;
    while(binNum > 0){
      int lastDigit = binNum % 10;
      decNum = decNum + (lastDigit * (int)Math.pow(2 , pow));

      pow++;
      binNum = binNum/10;
    }
    System.out.println("decimal of " + myNum + " = " + decNum);
  }

  public static void decToBin(int n){
    int myNum = n;
    int pow = 0;
    int binNum = 0;

    while(n>0){
      int rem = n % 2;
      binNum = binNum +(rem * (int)Math.pow(10 , pow));
      pow++;
      n = n/2;
    }
     System.out.println("binary form of "+ myNum + "=" + binNum);
  }

  public static int isAvg(int a , int b , int c){
    int avg = ( a + b + c )/3;
    return avg;
  }

  public static int isEven(int n){
    if(n%2==0){
      System.out.println("even");
    }else {
      System.out.println("odd");
    }
    return n ;
  }

  public static boolean isPal(int n){
    int palindrome = n;
    int reverse = 0;
    while(palindrome !=0){
    int remainder = palindrome % 10;
    reverse = reverse * 10 + remainder;
    palindrome = palindrome / 10;
    if(n == reverse){
      return true;
    }
   
    }return false;

  }

  public static int theSum(int n){
    int sum = 0;
    while(n > 0){
     int lastDigit = n % 10;
     sum = sum + lastDigit;
     n = n/10;

    }return sum ;
  }
  public static void hollow_rectangle(int totRows , int totCols){
    for(int i = 1; i<=totRows; i++){
      for(int j =1; j<=totCols; j++){
        if(i == 1 || i == totRows || j ==1 || j==totCols){
          System.out.print(" * ");
        }else{
          System.out.print("   ");
        }
      }System.out.println();
    }
  }
  
  public static void isPyra(int r){
    for(int i = 1; i<= r; i++){
      for(int j =1; j<=r-i; j++){
        System.out.print("   ");
      }
      for(int j = 1 ; j<=i; j++){
        System.out.print(" * ");
      }
      System.out.println();
    }
  }

  public static void numPy(int n){
    for(int i = 1; i<=n; i++){
      for(int j =1; j<=n-i+1; j++){
        System.out.print(j);
      }
      
      System.out.println();
    }
  }

  public static void floydTri(int n){
    int counter = 1;
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=i; j++){
        
        System.out.print(counter);
        counter++;
      }System.out.println();
    }
  }

  public static void trian(int n){
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=i; j++){
        if((i+j) % 2 == 0){
          System.out.print("1");
        }else{
           System.out.print("0");
        }
      } System.out.println();
    }

  }
   
  public static void butterFly(int n){
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=i; j++){
        System.out.print(" * ");
      }
      for(int j =1; j<=2*(n-i); j++){
        System.out.print("   ");
      }
      for(int j =1; j<=i; j++){
        System.out.print(" * ");
      }
      System.out.println();
    }
    for(int i = n; i>=1; i--){
      for(int j = 1; j<=i; j++){
        System.out.print(" * ");
      }
      for(int j =1; j<=2*(n-i); j++){
        System.out.print("   ");
      }
      for(int j =1; j<=i; j++){
        System.out.print(" * ");
      }
     System.out.println();

    }
  }

  public static void rohmbus(int n){
    for(int i =1; i<=n; i++){
      for(int j=1; j<=(n-i); j++){
        System.out.print(" ");
      }
      for(int j =1; j<=n; j++){
        System.out.print("*");
      }
      System.out.println();
    }
  }

  public static void rohmh(int n){
    for(int i = 0; i<=n; i++){
      for(int j = 1; j<=(n-i); j++){
        System.out.print(" ");
      }
      for(int j =1; j<=n; j++){
        if(i==1 || i==n || j ==1 || j==n){
          System.out.print("*");
        }
        else{
          System.out.print(" ");
        }

      }
      System.out.println();
    }
  }
   
  public static void diamond(int n){
    
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=(n-i); j++){
        System.out.print(" ");
      }
      for(int j = 1; j<=(2*i)-1; j++){
        System.out.print("*");
        
      }
      System.out.println();
    }
    for(int i = n; i>=1; i--){
      for(int j = 1; j<=(n-i); j++){
        System.out.print(" ");
      }
      for(int j = 1; j<=(2*i)-1; j++){
        System.out.print("*");
        
      }
      System.out.println();
    }
  }


  public static void main(String args[]){
   
    // System.out.println(theSum(623));
    // hollow_rectangle(9, 10);

  // numPy(50);
  // floydTri(50);

  // trian(5);

// butterFly(10);
// rohmbus(10);
// rohmh(6);
diamond(6);
}
}

