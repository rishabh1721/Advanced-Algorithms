#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>


int func1(vector<int>& arr){

  int mini = arr[0];
  for(int i =1; i<arr.size(); i++){
    if(arr[i] < mini){
      mini = arr[i];
    }
  }
  return mini;
}

int func2(vector<int>& arr){

  int maxi = arr[0];
  for(int i =1; i<arr.size(); i++){
    if(arr[i] > maxi){
      maxi = arr[i];
    }
  }
  return maxi;
}

pair<int,int> func3(vector<int>& arr){
  // int mini = 0;
  // int maxi =0;
    int mini = INT_MAX, small = INT_MAX;
    int maxi = INT_MIN, large = INT_MIN;
  for(int i=1; i<arr.size(); i++){
    if(arr[i] > maxi){
      maxi= arr[i];

    }
    if(arr[i] < mini){
      mini = arr[i];
    }

  }
  for(int i=0; i<arr.size(); i++){
    if(arr[i] > large && arr[i] != maxi){
      large = arr[i];
    }
    if(arr[i] < small && arr[i] != mini){
      small = arr[i];
    }
  }
  return {small,large};
}

int func4(vector<int>& arr){
  int n = arr.size();
  int small = INT_MAX, ssmall = INT_MAX;
  for(int i=0; i<n; i++){
    if(arr[i] < small){
      ssmall = small;
      small = arr[i];
    }
    else if(arr[i] < ssmall && arr[i] != small){
      ssmall = arr[i];

    }

  }
  return ssmall;
}

int func5(vector<int>& arr){
  int n = arr.size();
  int large = INT_MIN, llarge = INT_MIN;
  for(int i=0; i<n; i++){
    if(arr[i] > large){
      llarge = large;
      large = arr[i];
    }
    else if(arr[i] > llarge && arr[i] != large){
      llarge = arr[i];

    }

  }
  return llarge;
}


int func6(vector<int>& arr){
  int n = arr.size();
  reverse(arr.begin(), arr.end());  
  return 0;
}

int reverse(vector<int>& arr, int left, int right){
  while(left < right){
    swap(arr[left], arr[right]);
    left++;
    right--;
  }
  return 0;
}

int cntfreq(vector<int>& arr){
  unordered_map<int,int>freq;
  for(int x : arr){
    freq[x]++;
  }
  return 0;
}
int reve(vector<int>& arr){
  sort(arr.begin(), arr.end());
  int n = arr.size();
  reverse(arr.begin()+ n/2, arr.end());
  return 0;
}


int sum(vector<int>& arr){
  int sum = 0;
  for(int i=0; i<arr.size(); i++){
    sum += arr[i];
  }
  return sum;
}

int sums(vector<int>& arr){
  return accumulate(arr.begin(), arr.end(), 0);
}

class Solution {
public:
    vector<int> reverse(vector<int>& arr,int l,int r){
        while(l < r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++,r--;
        }
        return arr;
    }
    void rotateArray(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        if(k==0) return;
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);
        reverse(arr,0,n-1);


    }
};

int avg(vector<int>& arr){

  int n = arr.size();
  int sum = accumulate(arr.begin(), arr.end(), 0);
  return sum/n;
  
}

int median(vector<int>& arr){
  sort(arr.begin(), arr.end());

  int n = arr.size();
  if(n % 2==0){
    return (arr[n/2] + arr[n/2 -1])/2;
  }
  else{
    return arr[n/2];
  }
}


    int removeDuplicates(vector<int>& nums) {
        int i =0;
        for(int j=1; j<nums.size(); j++){ 
           if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }


 vector<int> removeDuplicatesS(vector<int>& arr) {
  unordered_map<int,bool>mp;
  vector<int>ans;
  for(int x : arr){
    if(mp.find(x) == mp.end()){
      ans.push_back(x);
      mp[x] = true;
    }
  }
  return ans;
} 

void insertel(vector<int>&arr){
  int n = arr.size();
  int x = 5;
  arr.push_back(0);
  arr.insert(arr.begin(), x);
  arr.insert(arr.begin() + n/2, x);

}

void freqcnttt(vector<int>& arr){
  unordered_map<int,int>freq;
  for(int x : arr){
    freq[x]++;
  }
  for(auto it : freq){
    if(it.second > 1){
      cout<<it.first<<" "<<it.second<<endl;
    }            
  }



}

void freqcnt(vector<int>& arr){
  unordered_map<int,int>freq;
  for(int x : arr){
    freq[x]++;
  }
  for(auto it : freq){
    if(it.second == 1){
      cout<<it.first<<" "<<it.second<<endl;
    }            
  }

}
 
void pairsss(){
  unordered_map<int,int>mp;
  int arr[5][2] = {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}};
  for(int i=0; i<5; i++){
    int first = arr[i][0];
    int second = arr[i][1];

    if(mp.find(first) != mp.end() && mp.find(second) != mp.end()){
      cout<<first<<" "<<second<<endl;
    }
    else{
      mp[first] = second;
      
    }
  }
}


 int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MIN;
        int pre=1,suff=1;
        for(int i=0; i<n; i++){
            if(pre==0) pre = 1;
            if(suff == 0) suff = 1;
            pre *= arr[i];
            suff *= arr[n-i-1];
            ans = max(ans, max(pre,suff));
        }
        return ans;
    }


void rank(vector<int>& arr){
  vector<int>sorts = arr;
  sort(sorts.begin(), sorts.end());

  unordered_map<int,int>mp;
  int rank = 1;
  for(int i=0; i<sorts.size(); i++){
    if(mp.find(sorts[i]) == mp.end()){
      mp[sorts[i]] = rank;
      rank++;
    } 
  }
  vector<int>ranks;
  for(int x : arr){
    ranks.push_back(mp[x]); 
  }
}

vector<int> freqqI(vector<int>& arr){
  unordered_map<int,int>freq;
  for(int x : arr){
    freq[x]++;
  }

  auto cmp = [&](int a,int b){
    if(freq[a] == freq[b]){
      return a < b;
    }
    return freq[a] > freq[b];   

  };
   sort(arr.begin(), arr.end(), cmp);
    return arr;
}

    vector<int> reversesss(vector<int>& arr,int l,int r){
        while(l < r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++,r--;
        }
        return arr;
    }
    void rotateArrayyyy(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        if(k==0) return;
        //left
        reversesss(arr,0,k-1);
        reversesss(arr,k,n-1);
        reversesss(arr,0,n-1);

        //right
         reversesss(arr,0,n-1);
        reversesss(arr,0,k);
        reversesss(arr,k,n-1);
    }


int sumssss(vector<int>& arr){
  int sum = 0;
  for(int i=0; i<arr.size(); i++){
    sum += arr[i];
  }
  int ls = 0, rs = sum;
  for(int i=0; i<arr.size(); i++){
    rs -= arr[i];
    if(ls == rs){
      return i;
    }
    ls += arr[i];
  }
  return -1;
}

int bs(vector<int>& arr, int k){
  int low = 0, high = arr.size() - 1;
  while(low <= high){
    int mid = (low + high)/2;
    if(arr[mid] == k){
      return mid;
    }
    else if(arr[mid] < k){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return -1;
}
	
int bss(vector<int>&arr, vector<int>&brr){
  int n = arr.size();
  int m = brr.size();
  for(int i=0 ; i<m; i++){
    bool present = bs(arr, brr[i]);
    if (present==false){
        return false;
    }
  }
  return true;
}


    bool isPalindrome(int n) {
        int copy = n;
        int rev = 0;
        while(n > 0){
            int ls = n % 10;
             rev = (rev*10) + ls;
            n = n/10;
        }
        if (rev == copy) return true;
        else return false;
    }



    int count(int n){
        if(n==0) return 1;
        int cnt = log10(n)+1;
        return cnt;
    }
    bool isArmstrong(int n) {
        int cnt = count(n);
        int copy = n;
        long long sum = 0;

        while(n > 0){
            int ls = n%10;
            sum += pow(ls,cnt);
            n /= 10;
        }
        if(sum==copy) return true;
        else return false;

    }
  bool isPerfect(int n) {
        int sum =0;
        for(int i=1; i <n; i++){
            if(n%i==0) sum += i;

            
        }
        if(sum==n) return true;
        else return false;
    }

   	
    bool thisIsPalOrNot(string &s, int left, int right){
        if(left >= right) return true;
        if(s[left] != s[right]) return false;
        return thisIsPalOrNot(s,left+1,right-1);
    }
		bool palindromeCheck(string& s){
			//your code goes here
            return thisIsPalOrNot(s,0,s.size()-1);
		}


    // vector<int> allThecoPrimesinRange(int a, int b){
    //   vector<int> ans;
    //   for(int i =1; i <= b; i++){
        
    //     if (std::gcd(i,a) == 1){
    //       ans.push_back(i);
    //     }
    //   }
    //   return ans;
    // }


    int binarysearch(vector<int>&arr,int target){
      int low = 0,high = arr.size()-1;
      while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target){
          return mid;
        }
        else if(arr[mid] < target){
          low = mid + 1;
        }
        else{
          high = mid - 1;
        }
      }
      return -1;
    }

    int linearsearch(vector<int>&arr,int target){
      for(int i=0; i<arr.size(); i++){
        if(arr[i] == target){
          return i;
        }
      }
      return -1;
    }

    // int main(){
    //   vector<int>arr = {1,2,3,4,5,6,7,8,9};
    //   int target = 5;
    //   int index = binarysearch(arr,target);
    //   cout<<"Binary Search: Element "<<target<<" found at index "<<index<<endl;
    //   index = linearsearch(arr,target);
    //   cout<<"Linear Search: Element "<<target<<" found at index "<<index<<endl;
    //   string sr = "racecar";
    //   bool result = thisIsPalOrNot(sr,0,sr.size()-1);
    //   if(result){
    //     cout<<"The string is a palindrome."<<endl;
    //   }
    //   else{
    //     cout<<"The string is not a palindrome."<<endl;
    //   }
    //   return 0;
    // }