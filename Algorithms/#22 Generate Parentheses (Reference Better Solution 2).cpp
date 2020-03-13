class Solution {
public:
	vector<string> generateParenthesis( int n ) {
		vector<string> ret;
		string combination;
		combination.append(2 * n, '.');
		generateParenthesisStr(0, 2 * n, combination, n, n, ret);
		return ret;
	}
private:
	void generateParenthesisStr(int index, int boundary, string & combination, int closeLeft, int closeRight, vector<string> & ret) {
		if (index == boundary) {// finish generating combination
			ret.push_back(combination);
			return;
		}
        // every position can be either '(' or ')'
		if (closeLeft < closeRight) {// if there are more open '(', ')' is OK to be placed here
			combination[index] = ')';
			generateParenthesisStr(index + 1, boundary, combination, closeLeft, closeRight - 1, ret);
		}
		if (closeLeft > 0) {// if the n '(' is not used up, it's OK to be placed here
			combination[index] = '(';
			generateParenthesisStr(index + 1, boundary, combination, closeLeft - 1, closeRight, ret);
		}
	}
};