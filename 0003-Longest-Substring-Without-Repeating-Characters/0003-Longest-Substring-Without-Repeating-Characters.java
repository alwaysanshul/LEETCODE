class Solution {
    public int lengthOfLongestSubstring(String s) {
        String test = "";
        int maximum=-1;
        int n = s.length();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        for(char c: s.toCharArray())
        {
            String t = String.valueOf(c);
            
            if(test.contains(t))
            {
                test = test.substring(test.indexOf(t)+1);
            }
          
            test = test + t;
            maximum=Math.max(test.length(),maximum);
        }
        return maximum;
    }
}
