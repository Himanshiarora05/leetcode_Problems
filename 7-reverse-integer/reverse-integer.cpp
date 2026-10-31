class Solution {
public:
    int reverse(int x) {
        long long n = abs((long long)x);
        long long rev = 0;
        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n = n / 10;
        }
        if (rev > INT_MAX || rev < INT_MIN) return 0;
        if (x < 0)  return -rev;
        else  return rev;
    }
};