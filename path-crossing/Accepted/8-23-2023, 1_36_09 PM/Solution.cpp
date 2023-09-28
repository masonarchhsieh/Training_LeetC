// https://leetcode.com/problems/path-crossing

// Hash function 
struct hashFunction
{
  size_t operator()(const pair<bool, 
                    bool> &x) const
  {
    return x.first ^ x.second;
  }
};
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, hashFunction> s;
        int posX = 0, posY = 0;
        s.insert(make_pair(posX, posY));

        for (auto i = 0; i < path.length(); i++) {
            switch (path[i]) {
                case 'N':
                    posY++;
                break;
                case 'S':
                    posY--;
                break;
                case 'E':
                    posX++;
                break;
                case 'W':
                    posX--;
                break;
                default:
                break;
            }
            if (s.find(make_pair(posX, posY)) != s.end())
                return true;
            s.insert(make_pair(posX, posY));
        }
        return false;
    }
};