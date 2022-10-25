class Solution {
    public int myAtoi(String s) {
        double ans;
        int n = s.length();
        if(n==0)
            return 0;
        int low=0,high=0;
        boolean positive=true;
        int i=0;
        while(i<n && Character.isWhitespace(s.charAt(i)) )
            i++;
        if(i>=n)
            return 0;
        if(s.charAt(i)=='-'){
            positive = false;
            low = i+1;
            i++;
        }
        else if(s.charAt(i)=='+'){
            low = i+1;
            i++;
        }
        else if(!Character.isDigit(s.charAt(i)))
            return 0;
        else 
            low = i;
        if(i>=n)
            return 0;
        while(i<n && Character.isDigit(s.charAt(i))){
            i++;
        }
        high = i; 
        if(low==high)
            return 0;
        String str = s.substring(low,high);
        ans = Double.parseDouble(str);
        if(!positive)
            ans = ans*-1;
       
        if(ans>2147483647)
            return 2147483647;
        else if(ans < -2147483648)
            return -2147483648;
        else 
            return (int)ans;
    }
} 
// Time: 5ms , Memory: 44.7MB
