class Solution {
public:
    string minWindow(string s, string t) {
        string ret;
        int lenS = s.length();
        int lenT = t.length();
        if (lenS < lenT) return ret;
        unordered_map<char, int> restOf;
        queue<char> charQueue;
        queue<int> posQueue;
        int startPos = 0, lenMin = lenS, startPosTmp, lenTmp;
        bool hasMatch = false;
        for (char T : t) {
            if (restOf.find(T) == restOf.end()) {
                restOf.insert(pair<char, int>(T, 1));
            }
            else {
                restOf[T]++;
            }
        }
        char* token;
        int* restOfTmp;
        for (int i = 0; i < lenS; i++) {
            token = &s[i];
            if (restOf.find(*token) != restOf.end()) { // token is in T
                restOfTmp = &restOf[*token];
                if (charQueue.empty()) { // use the first match char to init queue
                    charQueue.push(*token); // because queue.front() is used frequently later
                    posQueue.push(i); // but it can not be called if the queue is empty
                    (*restOfTmp)--;
                    startPos = i;
                    if (*restOfTmp == 0 && lenT == 1) { // deal with corner case the first char matches T
                        hasMatch = true;
                        lenMin = 1;
                        break;
                    }
                }
                else { // here's the tricky part
                    if (*restOfTmp > 0) { // substring can not be complete right now
                        charQueue.push(*token);
                        posQueue.push(i);
                        (*restOfTmp)--;
                        if (charQueue.size() == lenT) { // which means we got a complete substring
                            hasMatch = true;
                            startPosTmp = posQueue.front();
                            lenTmp = i - startPosTmp + 1;
                            if (lenTmp < lenMin) { // and the length is less than lenMin
                                startPos = startPosTmp; // update startPos
                                lenMin = lenTmp;// and lenMin
                            }
                        }
                    }
                    else if (*restOfTmp == 0 && *token == charQueue.front()) {
                        charQueue.push(*token);
                        posQueue.push(i);
                        (*restOfTmp)--;
                        lenT++;
                        while(*restOfTmp < 0) { // pop until the rest of front is larget than 0
                            lenT--;
                            (*restOfTmp)++;
                            charQueue.pop();
                            posQueue.pop();
                            restOfTmp = &restOf[charQueue.front()];
                        }
                        if (charQueue.size() == lenT) { // which means we got a complete substring
                            hasMatch = true;
                            startPosTmp = posQueue.front();
                            lenTmp = i - startPosTmp + 1;
                            if (lenTmp < lenMin) { // and the length is less than lenMin
                                startPos = startPosTmp; // update startPos
                                lenMin = lenTmp;// and lenMin
                            }
                        }
                    }
                    else { // push to the queue and increase lenT
                        (*restOfTmp)--;
                        lenT++;
                        charQueue.push(*token);
                        posQueue.push(i);
                    }
                }
            }
        }
        if (hasMatch) ret = s.substr(startPos, lenMin);
        return ret;
    }
};