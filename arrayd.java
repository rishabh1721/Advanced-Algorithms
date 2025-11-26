import java.util.*;


public class arrayd {
  
// public static boolean search(int matrix[], int key){
//    for(int i =0; i<matrix.length; i++){
//     for(int j=0 ; j<matrix[0].length; j++){

//       if(matrix[i][j] == key){

//         return true;
//       }
//     }
//   }

// return false;
// }


public static void printSpiral(int matrix[][]){
  int startRow =0;
  int startCol = 0;
  int endRow = matrix.length-1;
  int endCol = matrix[0].length-1;

  while(startRow <= endRow && startCol <= endCol){
    for(int j =startCol; j<=endCol;j++){
      System.out.print(matrix[startRow][j]+ " ");

    }
    for(int i = startRow+1; i<=endRow; i++ ){
      System.out.print(matrix[i][endCol]+ " ");
    }
    for(int j=endCol-1; j>= startCol;j--){
      if(startRow == endRow){
        break;
      }
      System.out.print(matrix[endRow][j]+ " ");
    }
    for(int i = endRow-1; i>=startRow+1; i--){
      if(startCol == endCol){
        break;
      }
      System.out.print(matrix[i][startCol]+ " ");
    }
    startCol++;
    startRow++;
    endCol--;
    endRow--;
  }
  System.out.println();
}

public static int diaSum(int matrix[][]){
  int sum = 0;
  // for(int i = 0 ; i<matrix.length;i++ ){
  //   for(int j=0; j<matrix[0].length; j++){
  //     if(i==j){
  //       sum += matrix[i][j];
  //     }
  //     else if(i+j == matrix.length-1){
  //       sum += matrix[i][j];
  //     }
  //   }
  // }

  for(int i =0; i<matrix.length; i++){
    sum += matrix[i][i];
    if(i != matrix.length-1-i){
      sum += matrix[i][matrix.length-i-1];
  }}
  return sum;  
}

public static boolean stairSearch(int matrix[][] , int key){
  int row = 0 , col = matrix[0].length-1;

  while(row<matrix.length && col >= 0){
    if(matrix[row][col] ==key){
      System.out.println(row + "," + col);
      return true;
    }

    else if(key < matrix[row][col]){
      col--;
    }
    else{
      row++;
    }
  }
  return false;

}

public static int seven(int matrix[][]){
  int count = 0;
  for(int i =0; i<matrix.length; i++){
    for(int j =0; j<matrix[0].length; j++){
      if(matrix[i][j] == 7){
        count++;
      }
    }
    
  }
  return count;
}

public static int sumSecond(int nums[][]){
  int sum = 0;
  
    for(int j=0; j<nums[0].length; j++){
      sum += nums[1][j];
    }
  
  return sum;

}
public static void transpose(int nums[][]){
  for(int i=0; i<nums.length; i++){
    for(int j=0; j<nums[0].length; j++){
      int temp = nums[i][j];
      nums[i][j] = nums[j][i];
      nums[j][i] = temp;
      System.out.print(nums[i][j]);
    }
    System.out.println();

  }
  
}
  public static void main(String[] args) {
    
    int nums[][] = {{23,22,9} ,
                    {11,4,3} ,
                     
                            };

  //  printSpiral(matrix);
  // System.out.println(diaSum(matrix));


//  System.out.println(seven(matrix));
transpose(nums);

  }
}
