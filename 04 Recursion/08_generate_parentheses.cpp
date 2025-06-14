// 22. Generate Parentheses


// Method 1: 
class Solution {
public:
    vector<string> result;

    bool isValid(string temp){
        int count = 0;

        for(char ch : temp){
            if(ch == '(') count++;
            else count--;
            if(count < 0) return false;
        }

        return count == 0;
    }

    void solveRec(string &temp, int n){
        if(temp.size() == 2*n){
            if(isValid(temp)){
                result.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        solveRec(temp, n);
        temp.pop_back();

        temp.push_back(')');
        solveRec(temp, n);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        solveRec(temp, n);

        return result;
    }
};



// Method 2: 
class Solution {
public:
    vector<string> result;
    
    void solveRec(string &curr, int n, int open, int close){
        if(curr.size() == 2*n){
            result.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            solveRec(curr, n, open+1, close);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            solveRec(curr, n, open, close+1);
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string curr = "";

        solveRec(curr, n, open, close);
        return result;
    }
};