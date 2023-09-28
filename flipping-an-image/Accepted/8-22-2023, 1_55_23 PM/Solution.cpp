// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> img = image;
        // step 1: flip image
        for (auto i = 0; i < img.size(); i++)
            for (auto j = 0; j < img[i].size() / 2; j++)
                swap(img[i][j], img[i][img[i].size() - 1 - j]);
            
        // step 2: invert image
        for (auto i = 0; i < img.size(); i++)
            for (auto j = 0; j < img[i].size(); j++)
                img[i][j] = (img[i][j] != 1);

        return img;
    }
};