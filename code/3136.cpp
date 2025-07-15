class Solution {
public:
    bool isValid(string word) {
        bool vowel = true, conson = true, digiEng = true;
        int len = word.size();
        for(int i = 0; i < len && digiEng; ++i){
            char c = word[i];
            digiEng = isalnum(c);
            if(digiEng && (vowel || conson) && isalpha(c)){
                c = tolower(c);
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') vowel = false;
                else conson = false;
            }
        }
        cout << digiEng << !vowel << !conson;
        return len >= 3 && digiEng && !vowel && !conson;
    }
};