#include <iostream>
#include <string>

enum class Weekday {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

Weekday lookup(int day) {
    switch (day) {
        case 1: return Weekday::MONDAY;
        case 2: return Weekday::TUESDAY;
        case 3: return Weekday::WEDNESDAY;
        case 4: return Weekday::THURSDAY;
        case 5: return Weekday::FRIDAY;
        case 6: return Weekday::SATURDAY;
        case 7: return Weekday::SUNDAY;
        default: return Weekday();
    }
}

Weekday lookup(const std::string& day) {
    if (day == "Monday") return Weekday::MONDAY;
    if (day == "Tuesday") return Weekday::TUESDAY;
    if (day == "Wednesday") return Weekday::WEDNESDAY;
    if (day == "Thursday") return Weekday::THURSDAY;
    if (day == "Friday") return Weekday::FRIDAY;
    if (day == "Saturday") return Weekday::SATURDAY;
    if (day == "Sunday") return Weekday::SUNDAY;
    return Weekday();
}

template<class T>
class GeometricForm{
public:
    virtual T calculateArea(){return 0.0;};
    virtual void printDescription(){std::cout << "GeometricForm";};
};

template<class T>
class Circle : public GeometricForm<T>{
public:
    T rad;
    Circle(T radius);

    T calculateArea();
    void printDescription();
};

template<class T>
Circle<T>::Circle( T rad){
    this->rad = rad;
}

template<class T>
T Circle<T>::calculateArea(){
    return (this->rad * this->rad);
}

template<class T>
void Circle<T>::printDescription(){
    std::cout << "Description is printing...\n";
}

class Square: public GeometricForm<int>{
private:
    double lat;
    /* data */
public:
    int calculateArea();
    void printDescription();
    Square(double lat);
};


Square::Square(double lat){
    this->lat = lat;
}

int Square::calculateArea(){
    return this->lat*this->lat;
}

void Square::printDescription(){
    std::cout << "Description is printing...\n";
}

int main() {
    //std::cout << "By number: " << static_cast<int>(lookup(3)) << std::endl;
    //std::cout << "By name: " << static_cast<int>(lookup("Friday")) << std::endl;
    Circle<double> c(2.5);
    Circle<int> c1(2);
    std::cout << c.calculateArea() << '\n';
    std::cout << c1.calculateArea() << "\n";
    return 0;
}