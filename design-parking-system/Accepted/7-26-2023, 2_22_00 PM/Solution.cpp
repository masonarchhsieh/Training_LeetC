// https://leetcode.com/problems/design-parking-system

class ParkingSystem {
    vector<int> spaces;
public:
    ParkingSystem(int big, int medium, int small) {
        spaces.push_back(big);
        spaces.push_back(medium);
        spaces.push_back(small);
    }
    
    bool addCar(int carType) {
        return spaces[carType-1]-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */