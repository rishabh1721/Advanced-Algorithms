public class bitwise {

  public static void oddEven(int n) {
    int bitMask = 1;
    if ((n & bitMask) == 0) {
      System.out.println("even number");
    } else {
      System.out.println("odd number");
    }

  }

  public static int getIth(int n, int i) {
    int bitMask = 1 << i;
    if ((n & bitMask) == 0) {
      return 0;
    } else {
      return 1;
    }

  }

  public static int setIth(int n, int i) {
    int bitMask = 1 << i;
    return n | bitMask;
  }

  public static int clearIth(int n, int i) {
    int bitMask = ~(1 << i);
    return n & bitMask;
  }

  public static boolean isodd(int n) {
    if ((n & 1) == 1) {
      return true;
    }
    return false;
  }

  public static int updateIth(int n, int i, int newBit) {

    n = clearIth(n, i);
    int bitMask = newBit << i;
    return n | bitMask;

    // if (newBit == 0) {
    // return clearIth(n, i);
    // } else {
    // return setIth(n, i);
    // }
  }

  public static int ans(int[] arr) {
    int unique = 0;
    for (int n : arr) {
      unique ^= n;
    }
    return unique;
  }

  public static void main(String[] args) {

    // System.out.println(updateIth(10, 2, 1));
    // System.out.println(10 << 1);

    // System.out.println(isodd(33));

    // int[] arr = { 2, 2, 3, 3, 4, 4, 5, 5, 6 };
    // System.out.println(ans(arr));

    int n = 9;
    int ans = 0;
    int base = 5;
    while (n > 0) {
      int last = n & 1;
      n = n >> 1;
      ans += last * base;
      base *= 5;
      System.out.println(ans);

    }
  }

}
