class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int q=0;
        for(int i=0;i<s.length();i++){
            if(('a'<=s.charAt(i) && s.charAt(i)<='z') || ('0'<=s.charAt(i) && s.charAt(i)<='9')){
                q++;
            }
        }

        char[] arr = new char[q];

        int k=0;
        for(int i=0;i<s.length();i++){
            if(('a'<=s.charAt(i) && s.charAt(i)<='z') || ('0'<=s.charAt(i) && s.charAt(i)<='9')){
                arr[k++] = s.charAt(i);
            }
        }
        s = new String(arr);
        int start = 0;
        int end = s.length()-1;
        while(start<=end){
            if(s.charAt(start++)!=s.charAt(end--)){
                return false;
            }
        }
        return true;
    }
}