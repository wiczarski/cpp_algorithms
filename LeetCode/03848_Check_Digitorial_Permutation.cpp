long long factorial(int a) {
    long long sum = 1;
    for(int i = 1; i <= a; i++) {
        sum *= i;
    }
    return sum;
}

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int number_digits[10] = {0};
        int factorials_sum_digits[10] = {0};
        int temp = n;
        long long factorials_sum = 0;

        while(temp > 0) {
            number_digits[temp % 10]++;
            temp /= 10;
        }

        for(int i = 0; i < 10; i++){
            factorials_sum += number_digits[i] * factorial(i);
        }

        temp = factorials_sum;
        while(temp > 0) {
            factorials_sum_digits[temp % 10]++;
            temp /= 10;
        }

        for(int i = 0; i < 10; i++) {
            if (number_digits[i] != factorials_sum_digits[i]) return false;
        }
        
        return true;
    }
};