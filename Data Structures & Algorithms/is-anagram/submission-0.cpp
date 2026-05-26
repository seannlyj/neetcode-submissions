class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        int sCharacters[26] = {};
        int tCharacters[26] = {};

        for(int i = 0; i < s.length(); i++)
        {
            int sCharacterIndex = s.at(i) - 'a';
            sCharacters[sCharacterIndex]++;

            int tCharacterIndex = t.at(i) - 'a';
            tCharacters[tCharacterIndex]++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(sCharacters[i] != tCharacters[i])
                return false;
        }

        return true;
    }
};
