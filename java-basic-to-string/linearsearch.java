public class linearsearch {

// public static int linearSearch(int numbers[], int key){
//   for(int i =0 ; i<numbers.length; i++){
//     if(numbers[i]==key){
//       return i;
//     }
//   }
//   return -1;
// }

// public static int getLargest(int numbers[]){
//   int largest = Integer.MIN_VALUE;
//   for(int i =0 ; i<numbers.length; i++){
//     if(largest < numbers[i]){
//       largest = numbers[i];
//     }
//   }
//   return largest;
// }

// public static int getSmallest(int numbers[]){
//   int smallest = Integer.MAX_VALUE;
//   for(int i =0; i<numbers.length; i++){
//     if(numbers[i]<smallest){
//       smallest = numbers[i];
//     }

//   }
//   return smallest;
// }
public static int binarySearch(int numbers[] , int key){
  int start = 0 , end = numbers.length-1;
  while(start<=end){
    int mid = (start + end)/2;

    if(numbers[mid]==key){
      return mid;
    }
    if(numbers[mid]< key){
      start = mid + 1;
    }else{
      end = mid -1;
    }
  }
  return -1;
}

public static void reverse(int numbers[]){
  int first = 0 , last = numbers.length-1;

  while(first<last){
    int temp = numbers[last];
    numbers[last] = numbers[first];
    numbers[first] = temp;
    first++;
    last--;

  }
  
}
 public static void printPairs(int numbers[]){
  int tp = 0;
  for(int i = 0; i<numbers.length ; i++){
    int curr = numbers[i];
    for(int j = i+1; j<numbers.length; j++){
      System.out.print("(" + curr + "," + numbers[j]+ ")");
      tp++;
    }
    System.out.println();
  }

  System.out.println("total pairs" + tp);
 }

 public static void printSubarrays(int numbers[]){
   int ts = 0;
  for(int i = 0; i<numbers.length;i++){
    int start = i;
    for(int j =1; j<numbers.length; j++){
      int end =j;
      for(int k =start; k<=end; k++){
        System.out.print(numbers[k]+" ");
        
      }
        ts++; 
        System.out.println();
    }
     System.out.println();
  }
   System.out.println(ts);
 }

 public static void printSub(int numbers[]) {
  int currSum = 0;
  int maxSum = Integer.MIN_VALUE;
  int prefix[] = new int[numbers.length];
  prefix[0] = numbers[0];
  for(int i =1; i<prefix.length; i++){
    prefix[i] = prefix[i-1] + numbers[i];
  }

  

  
  for(int i = 0 ; i<numbers.length; i++){
    int start = i;
    for(int j =i ; j<numbers.length; j++){
      int end = j;
      currSum = start == 0 ? prefix[end] : prefix[end] - prefix[start-1];
      // for(int k = start ; k<=end;k++){
      //   currSum += numbers[k];
      // }
      System.out.println(currSum);
     if(maxSum < currSum){
      maxSum = currSum;
     }
      
    }
      
  }
  System.out.println("total sum = "+ maxSum);
 }

 public static void kadanes(int numbers[]){
  int ms = Integer.MIN_VALUE;
  int cs = 0; 

  for(int i = 0; i<numbers.length; i++){
    cs = cs + numbers[i];
    if(cs<0){
      cs = 0;
    }
    ms = Math.max(cs ,ms);

  }
  System.out.println(ms);

 }


  public static void main(String[] args) {

    // int numbers[] = {2,4,6,8,10,12,14,16};
    // int key = 10;
    

    // int index = linearSearch(numbers, key);
    // if(index == -1){
    //   System.out.println("not found");
    // }else{
    //    System.out.println("key found at " + index);
    // }

    // int numbers[] = {1,2,6,3,5};
    // System.out.println("largest value is "+ getLargest(numbers));

    // System.out.println("smallest value is "+ getSmallest(numbers));


    // int numbers[] = {2,4,6,8,10,12,14};
    // int key = 10;
    // System.out.println("index for key is" + binarySearch(numbers , 10));

    int numbers[] = {-2,-3,4,-1,-2,1,5,-3};

  //  reverse(numbers);
  //  for(int i =0; i<numbers.length; i++){
  //   System.out.print(numbers[i]);
  //  } 

//  printPairs(numbers);
//  printSubarrays(numbers);
// printSub(numbers);
kadanes(numbers);
  }
}
