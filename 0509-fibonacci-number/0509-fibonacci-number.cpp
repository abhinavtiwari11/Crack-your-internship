class Solution {
public:
    int fib(int n) {
     double golden_mean = (1+sqrt(5))/2;
        double golden_number = (1-sqrt(5))/2;
        return (pow(golden_mean,n)-pow(golden_number,n))/sqrt(5);
    }
};