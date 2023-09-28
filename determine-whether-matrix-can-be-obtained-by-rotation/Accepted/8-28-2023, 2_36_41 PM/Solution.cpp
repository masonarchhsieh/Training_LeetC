// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
    // reference: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target)
            return true;
        for (auto i = 0; i < 4; i++) {
            rotate(mat);
            //print(mat);
            if (mat == target)
                return true;
    
        }
        
        return false;   
    }

    void rotate(vector<vector<int>>& mat) {
        for (auto i = 0; i < mat.size(); i++) {
            for (auto j = i + 1; j < mat[i].size(); j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // reverse individual rows
        for (auto i = 0; i < mat.size(); i++) {
            int low = 0, high = mat.size() - 1;
            while (low < high) {
                swap(mat[i][low], mat[i][high]);
                low++;
                high--;
            }
        }
    }

    void print(vector<vector<int>>& mat) {
        for (auto i = 0; i < mat.size(); i++) {
            for (auto j= 0; j < mat[0].size(); j++) {
                cout << mat[i][j] << ", ";
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }
};