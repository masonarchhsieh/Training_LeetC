// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
    vector<string> history;
    int itr;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        itr = 0;
    }
    
    void visit(string url) {
        //delete all the historys
        int s = history.size()-1;
        for (auto it = s; it>itr; it--) {
            history.pop_back();
        }
        history.push_back(url);
        itr++;
    }
    
    string back(int steps) {
        while (steps-- && itr > 0) {
            itr--;
        }
        return history[itr];
    }
    
    string forward(int steps) {
        itr = (itr + steps < history.size())? itr + steps : history.size() - 1;
        return history[itr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */