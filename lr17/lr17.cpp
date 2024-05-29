#include <iostream>
using namespace std;
class Room {
public:

    Room(double area);


    double getArea() const;

private:
    double area_; 
};


Room::Room(double area) : area_(area) {}


double Room::getArea() const {
    return area_;
}

class OneRoomApartment : public Room {
public:
 
    OneRoomApartment(double roomArea, double kitchenArea, int floor);


    double getKitchenArea() const;
    int getFloor() const;

private:
    double kitchenArea_; 
    int floor_; 
};


OneRoomApartment::OneRoomApartment(double roomArea, double kitchenArea, int floor)
    : Room(roomArea), kitchenArea_(kitchenArea), floor_(floor) {}


double OneRoomApartment::getKitchenArea() const {
    return kitchenArea_;
}


int OneRoomApartment::getFloor() const {
    return floor_;
}

class CityOneRoomApartment : public OneRoomApartment {
public:

    CityOneRoomApartment(double roomArea, double kitchenArea, int floor, const string& cityName);

 
    void printInfo();

private:
    string cityName_; 
};

CityOneRoomApartment::CityOneRoomApartment(double roomArea, double kitchenArea, int floor,
    const string& cityName)
    : OneRoomApartment(roomArea, kitchenArea, floor), cityName_(cityName) {}


void CityOneRoomApartment::printInfo() {
    cout << "One-room apartment in " << cityName_ << ":" << endl;
    cout << "  Room area: " << getArea() << " sq m" << endl;
    cout << "  Kitchen area: " << getKitchenArea() << " sq m" << endl;
    cout << "  Floor: " << getFloor() << endl;
}

int main() {
    CityOneRoomApartment apartment(17.5, 10, 5, "Kharkiv");

    apartment.printInfo();

    return 0;
}
