class ParkingSystem {
private:
    vector<int> slots;
    
public:
    ParkingSystem(int big, int medium, int small) {
        slots = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if (slots[carType-1]) {
            slots[carType-1] --;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */