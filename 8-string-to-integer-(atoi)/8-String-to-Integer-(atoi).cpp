#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Check if result * 10 will exceed INT_MAX.
            // If result > INT_MAX / 10, it will definitely overflow.
            // If result == INT_MAX / 10, it will overflow if the next digit is greater than 7 (since INT_MAX ends in 7).
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
