import java.util.*;

import javax.swing.ScrollPaneLayout;


public class strings {


public static void printLetters(String str){
  for(int i=0; i<str.length(); i++){
    System.out.println(str.charAt(i) + " ");
  }
  
}

public static boolean isPalindrome(String str){
  for(int i=0; i<str.length()/2; i++){
    int n = str.length();
    if(str.charAt(i) != str.charAt(n-i-1)){
      return false;

    }
  }
  return true;
}

public static float getPath(String path){
  int x =0 , y=0;
  for(int i=0;i<path.length(); i++){
    char dir = path.charAt(i);
    if(dir == 'S'){
      y--;
    }
    else if(dir == 'N'){
      y++;
    }
    else if(dir == 'E'){
      x++;
    }
    else {
      x--;
    }

  }
  int X2 = (x*x);
  int Y2 = (y*y);
  return (float)Math.sqrt(X2 + Y2);
}

public static String subString(String str, int si, int ei){
  String substr ="";
  for(int i=si; i<ei; i++){
    substr += str.charAt(i);
  }
  return substr;
}

public static String toUpperCase(String str){
  StringBuilder sb = new StringBuilder("");
  char ch = Character.toUpperCase(str.charAt(0));
  sb.append(ch);
  for(int i=1; i<str.length(); i++){
    if(str.charAt(i)== ' ' && i<str.length()-1){
      sb.append(str.charAt(i));
      i++;
      sb.append(Character.toUpperCase(str.charAt(i)));

    }else{
      sb.append(str.charAt(i));
    }
  }
  return sb.toString();

}

public static String compress(String str){
  if(str == null || str.isEmpty()){
    return "";
  }
  StringBuilder sb = new StringBuilder();
  for(int i =0; i<str.length(); i++){
    int count = 1;
    while(i<str.length()-1 && str.charAt(i)== str.charAt(i+1)){
      count++;
      i++;
    }
    sb.append(str.charAt(i));
    if(count>1){
      sb.append(count);
    }
  }
  return sb.toString();
  
  // String newStr ="";
  // for(int i=0; i<str.length(); i++){
  //   Integer count =1;
  //   while(i<str.length()-1 && str.charAt(i)== str.charAt(i+1)){
  //     count++;
  //     i++;
  //   }
  //   newStr += str.charAt(i);
  //   if(count > 1){
  //     newStr += count.toString();
  //   }
  // }
  // return newStr;
}



  public static void main(String[] args) {

    String str = "aaaabbcccdd";
    System.out.println(compress(str));

    // String str = "hi, i am shradha";
    // System.out.println(toUpperCase(str));

    // String fruits[] = {"apple", "mango", "banana"};
    // String largest = fruits[0];
    // for(int i=1; i<fruits.length; i++){
    //   if(largest.compareTo(fruits[i])<0){
    //     largest = fruits[i];
    //   }
    // }

    // System.out.println(largest);

    // StringBuilder sb = new StringBuilder("");
    // for(char ch='a'; ch<='z'; ch++){
    //   sb.append(ch);
    // }
    // System.out.println(sb.length());








    // System.out.println(subString(str, 01, 5));


    // String S2 = "Tony";
    // String S3 = new String("Tony");

    // if(S1 == S2){
    //  System.out.println("Strings are equal");

    // }else {
    //   System.out.println("Strings are not equal");
    // }

    //  if(S1 == S3){
    //  System.out.println("Strings are equal");

    // }else {
    //   System.out.println("Strings are not equal");
    // }

    // if(S1.equals(S3)){
    //    System.out.println("Strings are  equal");
    // }else{
    //    System.out.println("Strings are not equal");
    // }





    //  String str = "A man, a plan, a canal: Panama";
    // // String str = "racecar";
    
   
    // // char arr[] = {'a','b','c','d'};
    // // String str = "abcd";
    // // String str2 = new String("xyz");

    // // Scanner sc = new Scanner(System.in);
    // // String name;
    // // name = sc.nextLine();
    // System.out.println(getPath(path));

    // String fullName = "tony stark";
    // System.out.println(fullName.length());
    
    // printLetters(fullName);
    // String firstName = "Rishabh";
    // String lastName = "Kumar";
    // String fullName = firstName + " " + lastName;
    // System.out.println(fullName.charAt(4));
    // printLetters(fullName);




   


  }
  
}
