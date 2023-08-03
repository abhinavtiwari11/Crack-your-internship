class Solution {
    public int lengthOfLastWord(String s) {
        
     int count = 0; // Initialize a variable to keep track of the length of the last word

        // Handle the special case when the length of the string is 1
        if (s.length() == 1) {
            if (s.equals(" ")) {
                return -1; // If the string is a single space, return -1 (no last word)
            }
            return 1; // If the string contains a single non-space character, return 1 (length of the last word)
        }

        // Loop through the characters of the string from the end to the beginning
        for (int i = s.length() - 1; i >= 0; i--) {
            // Check if the current character is an alphabet character (between 'A' and 'z')
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'z') {
                count++; // Increment the count to keep track of the length of the current word

                // Check if the character before the current character is a space (double space)
                // If it is, it indicates the end of the last word, so break out of the loop
                if (i != 0 && s.charAt(i - 1) == ' ') {
                    break;
                }
            }
        }

        return count; // Return the count, which represents the length of the last word in the string
    }
}
