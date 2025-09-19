// 3484. Design Spreadsheet

class Spreadsheet {
public:
    unordered_map<string, int> mp;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        int n = formula.size();
        for(int i=1; i<n; i++){
            if(formula[i] == '+'){
                string s1 = formula.substr(1,i-1);
                string s2 = formula.substr(i+1);
                int val1 = (s1[0]>='A' && s1[0]<='Z') ? mp[s1] : stoi(s1);
                int val2 = (s2[0]>='A' && s2[0]<='Z') ? mp[s2] : stoi(s2);
                return val1+val2;
            }
        }

        return -1;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */