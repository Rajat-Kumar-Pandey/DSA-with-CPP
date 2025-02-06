
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.length() != t.length()) return false;

        std::vector<int> count(26,0);

        for(int i = 0 ; i <s.length() ; i++){
            count[s[i]- 'a']++;
            count[t[i]- 'a']--;
        }
        for(int c:count){
            if(c!=0) return false;
        }
        return true;
        
    }
};

int main() {
    Solution solution;
    std::string s, t;

    std::cout << "Enter the first string: ";
    std::cin >> s;

    std::cout << "Enter the second string: ";
    std::cin >> t;

    if(solution.isAnagram(s, t)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}
