// class Solution {
// public:
//     vector<string> split(string s){
//         istringstream iss(s);
//         vector<string> tokens;
//         string token;
//         while(getline(iss,token,' ')){
//             tokens.push_back(token);
//         }
//         // reverse(tokens.begin(),tokens.end());
//         return tokens;
//     }
//     vector<string> swapw(vector<string> &words){
//         int l=0,r=words.size()-1;
//         while(l<r){
//             swap(words[l],words[r]);
//             l++;
//             r--;
//         }
//         return words;
//     }
//     string joined(vector<string> &swap){
//         ostringstream oss;
//         for(int i=0;i<swap.size();i++){
//             if(i!=0){
//                 oss<<" ";
//             }
//             oss<<swap[i];
//         }
//         return oss.str();
//     }
//     string reverse(string s){
//         vector<string> words=split(s);
//         vector<string> swap=swapw(words);
//         return joined(swap);
//     }
//     string trim(const std::string& s) {
//         auto start = s.find_first_not_of(" \t\n\r\f\v");
//         if (start == std::string::npos) {
//             return ""; 
//         }
//         auto end = s.find_last_not_of(" \t\n\r\f\v");
//         return s.substr(start, end - start + 1);
//     }
//     std::string reducespaces(const std::string& s) {
//         std::string result;
//         bool inWhitespace = false;

//         for (char c : s) {
//             if (std::isspace(static_cast<unsigned char>(c))) {
//                 if (!inWhitespace) {
//                     result += ' '; 
//                     inWhitespace = true;
//                 }
//             } else {
//                 result += c;
//                 inWhitespace = false;
//             }
//         }

//         return result;
//     }
//     string reverseWords(string s) {
//         s=trim(s);
//         s=reducespaces(s);
//         return reverse(s);
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        removeExtraSpaces(s);

        // Step 2: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }

private:
    void removeExtraSpaces(string &s) {
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') j++;  // skip spaces
            while (j < s.size() && s[j] != ' ') s[i++] = s[j++];
            while (j < s.size() && s[j] == ' ') j++;  // skip extra spaces
            if (j < s.size()) s[i++] = ' ';           // keep only one space
        }
        s.resize(i);
    }
};
