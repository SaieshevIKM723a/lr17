#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    double area;

public:

    Room(double area) {
        this->area = area;
    }

    double getArea() const {
        return area;
    }
};

class OneRoomApartment {
private:
    Room room;
    double kitchenArea;
    int floor;

public:

    OneRoomApartment(const Room& room, double kitchenArea, int floor) : room(room) {
        this->kitchenArea = kitchenArea;
        this->floor = floor;
    }

    double getRoomArea() const {
        return room.getArea();
    }

    double getKitchenArea() const {
        return kitchenArea;
    }

    int getFloor() const {
        return floor;
    }
};

class PublicOneRoomApartment : public OneRoomApartment {
private:
    string city;

public:
    PublicOneRoomApartment(const Room& room, double kitchenArea, int floor, const string& city)
        : OneRoomApartment(room, kitchenArea, floor), city(city) {}

    ~PublicOneRoomApartment() {
        cout << "Apartment in " << city << " is being rented." << endl;
    }

    void print() const {
        cout << "Apartment in " << city << ":" << endl;
        cout << "Room area: " << getRoomArea() << " sq.m" << endl;
        cout << "Kitchen area: " << getKitchenArea() << " sq.m" << endl;
        cout << "Floor: " << getFloor() << endl;
    }
};

int main() {
 
    Room room(20.0);
    PublicOneRoomApartment apartment(room, 10.0, 5, "Kharkiv");

    apartment.print();

    return 0;
}
