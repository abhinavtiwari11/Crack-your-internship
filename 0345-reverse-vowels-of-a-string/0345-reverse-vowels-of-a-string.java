class Solution {
    public String reverseVowels(String s) {
        
    Set<Character> vowels = new HashSet<>(Arrays.asList('A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'));
        char[] chars = s.toCharArray();

        int p1 = 0;
        int p2 = chars.length - 1;
        while(p1 < p2){
            if(vowels.contains(chars[p1])){
                while(true) {
                    if(vowels.contains(chars[p2])){
                        swap(chars, p1, p2--);
                        break;
                    }

                    p2--;
                }
            }
            p1++;
        }

        StringBuilder stringBuilder = new StringBuilder();

        for(char c : chars)
            stringBuilder.append(c);
        return stringBuilder.toString();

    }

     public void swap(char[] s, int i, int j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}
