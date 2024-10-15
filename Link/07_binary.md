1.[bit manipulation](https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bit-manipulation)

2.[check bit is set or not](https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1)

3.[power of two](https://leetcode.com/problems/power-of-two/)

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of two should be positive, and n & (n - 1) should be zero.
        return n > 0 && (n & (n - 1)) == 0;
    }
};
