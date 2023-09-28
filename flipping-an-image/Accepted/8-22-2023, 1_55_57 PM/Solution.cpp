// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // step 1: flip image
        for (auto i = 0; i < image.size(); i++)
            for (auto j = 0; j < image[i].size() / 2; j++)
                swap(image[i][j], image[i][image[i].size() - 1 - j]);
            
        // step 2: invert image
        for (auto i = 0; i < image.size(); i++)
            for (auto j = 0; j < image[i].size(); j++)
                image[i][j] = (image[i][j] != 1);

        return image;
    }
};