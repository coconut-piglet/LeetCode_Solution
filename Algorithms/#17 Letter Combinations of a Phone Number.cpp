class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int numOfInputs = digits.size();
        string combination;
        combination.append(numOfInputs, '*');
        unordered_map<char, string> dict {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                          {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                          {'8', "tuv"}, {'9', "wxyz"}};// a little ugly but simplified
        generateLetterCombinations(digits, 0, numOfInputs - 1, combination, ret, dict);
        return ret;
    }
private:
    void generateLetterCombinations(string& digits, int index, int boundary, string& combination, vector<string>& ret, unordered_map<char, string>& dict) {
        if (index == boundary) {
            for (char token : dict[digits[index]]) {
                combination[index] = token;
                ret.emplace_back(combination);
            }
            return;
        }
        for (char token: dict[digits[index]]) {
            combination[index] = token;
            generateLetterCombinations(digits, index + 1, boundary, combination, ret, dict);
        }
        return;
    }
};