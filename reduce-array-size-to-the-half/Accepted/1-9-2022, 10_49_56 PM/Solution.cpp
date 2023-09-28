// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution { 

public:
    int minSetSize(vector<int>& arr) {
        int new_size = arr.size() / 2;
        int res = 0;
        std::sort(arr.begin(), arr.end());
        
        vector<int> tmp;
        if (arr[1] != arr[0])
            tmp.push_back(1);
  
        int temp = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i-1]) 
            {
                tmp.push_back(temp);
                temp = 1;
            }
            else
                temp++;
        }
        tmp.push_back(temp);
        
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        for (auto a : tmp)
            cout << a << endl;
        temp = 0;
        for (int i =0; i < tmp.size(); i++)
        {
            res++;
            if (temp + tmp[i] >= new_size)
                break;
            temp += tmp[i];
        }
        
        return res;
    }
};