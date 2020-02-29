class Solution {
public:
    string convert(string s, int numRows) {
        // Solution 1 Sort by Row
        // if (numRows == 1) return s;
        // int numOfElementsPerSet = 2 * numRows - 2; // may be zero
        // int numOfSets = (int)ceil((double)s.length() / (double)numOfElementsPerSet);
		// int length = s.length();
        // vector<string> row(numRows);
        // string ret;
        // for (int i = 0; i < length; i++) {
        //     int belong = i % numOfElementsPerSet;
        //     if (belong >= numRows) belong = numOfElementsPerSet - belong;
        //     row[belong] += s[i];
        // }
        // for (int i = 0; i < numRows; i++) {
        //     ret.append(row[i]);
        // }
        // Solution 2 Visit by Row
        if (numRows == 1) return s;
        int numOfElementsPerSet = 2 * numRows - 2;
        int length = s.length();
        string ret;
        for (int i = 0; i < numRows; i++) { // should go through rows first
            for (int j = 0; j + i < length; j += numOfElementsPerSet) { // s[j+i] is each sets first element in row i+1
                ret += s[j + i]; // if j+i >= length means the next set's first element in row i+1 exceeds the length 
                if (i != 0 && i != numRows -1 && j + numOfElementsPerSet -i < length) { // only inner rows can have two elements in one set
                    ret += s[j + numOfElementsPerSet -i]; // the potential one exists
                }
            }
        }
        return ret;
    }
};