#include <climits>

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int i = 0, n = s.length();
        int sign = 1; // Default is positive
        
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') i++;

        // Step 2: Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Step 3: Convert digits
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Step 4: Handle overflow early
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;
            
            i++;
        }

        return sign * ans;
    }
};
