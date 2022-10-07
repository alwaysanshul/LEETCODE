class Solution {
    public int reverse(int x) {
        // MAX_VALUE = 2147483647 //  MIN_VALUE = -2147483648
        if(x>2147483647 || x<-2147483648)
            return 0;
        StringBuffer sb = new StringBuffer(String.valueOf(x));
        sb.reverse();
        if(sb.charAt(sb.length()-1)=='-')
        {
            sb.delete(sb.length()-1,sb.length());
            sb.insert(0,"-");
        }
        long y = Long.parseLong(sb.toString());
        if(y>2147483647 || y<-2147483648)
            return 0;
        
        return (int)y;
    }
}//try input: 1638474123
