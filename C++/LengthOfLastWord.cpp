int lengthOfLastWord(string s) {
        int count = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] != ' ') 
                ++count;
            else if (count) // to tackle case where ending has blank spaces
                return count;
        }
        return count;
    }
