class Solution
{
public:
  int gcd(int a, int b)
  {
    // brute  code here

    int gr = 0;
    int ans = 0;
    if (a > b)
    {
      gr = a;
    }
    else
    {
      gr = b;
    }
    for (int i = 1; i <= gr; i++)
    {

      if ((a % i == 0) && (b % i == 0))
      {
        ans = i;
      }
    }
    return ans;
  }
};
// // optimized brute code here
// class Solution {
//   public:
//     int gcd(int a, int b) {
//         // code here

//         // int gr = 0;
//         int ans =0;
//         // if(a>b){
//         //     gr = a;
//         // }else{
//         //     gr = b;
//         // }
//         for(int i=1; i<=min(a,b); i++){

//             if((a%i==0)&&(b%i==0)){
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };

//

// Euclidean algorithm
// class Solution {
//   public:
//     int gcd(int a, int b) {
//         int ans;
//         while(a>0 && b>0){
//             if(a>b){
//                 a = a%b;
//             }else{
//                 b = b%a;
//             }
//             if(a == 0) ans = b;
//             else ans = a;
//         }
//         return ans;
//     }
// };
