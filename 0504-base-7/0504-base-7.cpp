class Solution {
public:
    string convertToBase7(int num) {
        
      
        if(num==0){
            return "0";
        }

        string newNum = "";
        bool isNegative = false;

        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        while (num) {
            long long int rem = num % 7;
            newNum = to_string(rem) + newNum;
            num /= 7;
        }

        if (isNegative) {
            return "-" + newNum;
        } else {
            return newNum;
        }
    }
};