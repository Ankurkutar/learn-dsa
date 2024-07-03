class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int reverse = 0, temp = x;

        while (x > 0) {
            int digit = x % 10;

            // Check for overflow before updating reverse
            if (reverse > (INT_MAX - digit) / 10) {
                return false; // Overflow would occur
            }

            reverse = (reverse * 10) + digit;
            x = x / 10;
        }

        return reverse == temp;
    }
};