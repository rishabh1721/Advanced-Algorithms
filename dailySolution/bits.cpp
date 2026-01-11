// #-- a/file:///Users/rishabhkumar/Desktop/CPP%20CODES/dailySolution/bits.cpp
// +#-- b/file:///Users/rishabhkumar/Desktop/CPP%20CODES/dailySolution/bits.cpp
// @@ -1,4 +1,5 @@
// +#include <cstdint>
// +using namespace std;
// -/* --- IGNORE ---

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t ans = 0;

//         for (int i = 0; i < 32; i++) {
//             ans = (ans << 1) | (n & 1);
//             n >>= 1;
//         }
//         return ans;
//     }
// };
