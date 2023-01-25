class Solution {
public:
    int sumOfDigits(int num) {
        int temp = num;
        int sum=0;
        while(temp!=0) {
            sum = sum + (temp%10);
            temp /= 10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int d=-1;
        int elemSum=0;
        int digSum=0;
        for(auto it=nums.begin();it!=nums.end();it++) {
            elemSum += *it;
            digSum += sumOfDigits(*it);
        }
        return abs(elemSum - digSum);
    }
};