//TLE on Code Studio
class Solution {
public:
    string reverseWords(string str) {
        int i = 0, n = str.length();
        string word="",ans="";
        //Iterate the string and keep on adding to form a word
        //If empty space is encountered then add the current word to the result
        while(i < n) {
            if(str[i] != ' ')
                word += str[i];
            else if(str[i] == ' ' && word!="") {
                if (ans!="") ans = word + " " + ans;
                else ans = word;
                word = "";
            }
            i++;
        }
        //If not empty string then add to the result(Last word is added)
        if (word!="") {
            if (ans!="") ans = word + " " + ans;
            else ans = word;
        }
        return ans;
    }
};
