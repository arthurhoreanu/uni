#ifndef CAR_H
#define CAR_H

#include <string>


class Car {
private:
    std::string licensePlate;
    std::string model;
    std::string brand;
    int yearOfFirstRegistration;
    int mileage;
    float dailyRate;
    std::string fuelType;
    std::string transmission;
    std::string color;
    std::string remarks;
    bool isActive;

public:


    Car(std::string licensePlate, std::string model, std::string brand, int yearOfFirstRegistration,
        int mileage, float dailyRate, std::string fuelType, std::string transmission, std::string color,
        std::string remarks, bool isActive);

    Car();


    // Getters
    std::string getLicensePlate() const;

    std::string getModel() const;

    std::string getBrand() const;

    int getYearOfFirstRegistration() const;

    int getMileage() const;

    float getDailyRate() const;

    std::string getFuelType() const;

    std::string getTransmission() const;

    std::string getColor() const;

    std::string getRemarks() const;

    // Setters
    void setLicensePlate(const std::string &newLicensePlate);

    void setModel(const std::string &newModel);

    void setBrand(const std::string &newBrand);

    void setYearOfFirstRegistration(int newYearOfFirstRegistration);

    void setMileage(int newMileage);

    void setDailyRate(float newDailyRate);

    void setFuelType(const std::string &newFuelType);

    void setTransmission(const std::string &newTransmission);

    void setColor(const std::string &newColor);

    void setRemarks(const std::string &newRemarks);


    void setisActive(bool isActive);

    bool getisActive();
};
#endif // CAR_H