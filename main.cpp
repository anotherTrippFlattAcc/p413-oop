#include <iostream>

class Student {
protected:
    std::string name;
    std::string group;
    std::string university;
    int year;

public:
    Student(const std::string& n, const std::string& gr, const std::string& un, int y) : name(n), group(gr), university(un), year(y) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getGroup() const {
        return group;
    }

    void setGroup(const std::string& group) {
        this->group = group;
    }

    std::string getUniversity() const {
        return university;
    }

    void setUniversity(const std::string& university) {
        this->university = university;
    }

    int getYear() const {
        return year;
    }

    void setYear(const int year) {
        this->year = year;
    }

    virtual void print() const {
        std::cout << "Student " << name << ":\n" << "\tUniversity: " << university << "\n\tGroup: " << group << "\n\tYear: " << year << std::endl;
    }
};

class Aspirant: public Student {
protected:
    std::string thesisTopic;

public:
    Aspirant(const std::string& n, const std::string& gr, const std::string& un, const int y,
             const std::string& topic)
        : Student(n, gr, un, y),
          thesisTopic(topic) {}

    std::string getThesisTopic() const {
        return thesisTopic;
    }

    void setThesisTopic(const std::string& thesisTopic) {
        this->thesisTopic = thesisTopic;
    }

    void print() const override {
        std::cout << "Student " << name << ":\n" << "\tUniversity: " << university << "\n\tGroup: " << group << "\n\tYear: " << year << "\n\tThesis Topic: " << thesisTopic << std::endl;
    }
};

class Passport {
protected:
    std::string fullName;
    std::string birthDate;
    std::string number;

public:
    Passport(const std::string& name, const std::string& birth, const std::string& num)
        : fullName(name), birthDate(birth), number(num) {}

    std::string getFullname() const {
        return fullName;
    }

    void setFullname(const std::string& fullName) {
        this->fullName = fullName;
    }

    std::string getBirthDate() const {
        return birthDate;
    }

    void setBirthDate(const std::string& birthDate) {
        this->birthDate = birthDate;
    }

    std::string getNumber() const {
        return number;
    }

    void setNumber(const std::string& number) {
        this->number = number;
    }

    virtual void print() const {
        std::cout << "Passport\n" << "\tFull name: " << fullName << "\n\tBirth date: " << birthDate << "\n\tPassport number: " << number << std::endl;
    }
};

class ForeignPassport: public Passport {
protected:
    std::string foreignNumber;
    std::string visaInfo;

public:
    ForeignPassport(const std::string& name, const std::string& birth, const std::string& num, const std::string& foreignNum, const std::string visa)
        : Passport(name, birth, num), foreignNumber(foreignNum), visaInfo(visa) {}
    
    std::string getForeignNumber() const {
        return foreignNumber;
    }

    void setForeignNumber(const std::string& foreignNumber) {
        this->foreignNumber = foreignNumber;
    }

    std::string getVisaInfo() const {
        return visaInfo;
    }

    void setVisaInfo(const std::string& visaInfo) {
        this->visaInfo = visaInfo;
    }

    void print() const override {
        std::cout << "Passport:" << "\n\tFull name: " << fullName << "\n\tBirth date: " << birthDate << "\n\tPassport number: " << number << "\n\tForeign Number: " << foreignNumber << "\n\tVisa Info: " << visaInfo << std::endl;
    }
};

class Transport {
protected:
    double distance;
    double speed;
    int passengers;
    int cargo;

    double passengerCost;
    double cargoCost;
public:
    Transport(const double dis, const int pass, const int carg): distance(dis), passengers(pass), cargo(carg) {
        speed = 0;
        passengerCost = 0;
        cargoCost = 0;
    }

    double getTime() const {
        if (speed == 0) return -1;
        return distance / speed;
    }

    double getCost() const {
        return passengers * passengerCost + cargo * cargoCost;
    }

    double getDistance() const {
        return distance;
    }

    void setDistance(double distance) {
        this->distance = distance;
    }

    double getSpeed() const {
        return speed;
    }

    void setSpeed(double speed) {
        this->speed = speed;
    }

    int getPassengers() const {
        return passengers;
    }

    void setPassengers(int passengers) {
        this->passengers = passengers;
    }

    int getCargo() const {
        return cargo;
    }

    void setCargo(int cargo) {
        this->cargo = cargo;
    }

    double getPassengerCost() const {
        return passengerCost;
    }

    void setPassengerCost(double passengerCost) {
        this->passengerCost = passengerCost;
    }

    double getCargoCost() const {
        return cargoCost;
    }

    void setCargoCost(double cargoCost) {
        this->cargoCost = cargoCost;
    }

    void print() const {
        std::cout << "Transport:" << "\n\tTime: " << getTime() << " hours" << "\n\tCost: $" << getCost() << std::endl;
    }
};

class Car : public Transport {
public:
    Car(const double dis, const int pass, const int carg): Transport(dis, pass, carg) {
        speed = 80;
        passengerCost = 10;
        cargoCost = 5;
    }
};

class Bicycle : public Transport {
    Bicycle(const double dis, const int pass, const int carg): Transport(dis, pass, carg) {
        speed = 10;
        passengerCost = 5;
        cargoCost = 2;
    }
};

class Wagon : public Transport {
    Wagon(const double dis, const int pass, const int carg): Transport(dis, pass, carg) {
        speed = 20;
        passengerCost = 10;
        cargoCost = 5;
    }
};

int main() {
    Aspirant s("Bob", "A12345", "MSU", 2, "C++ Programming Language");
    s.print();

    ForeignPassport p("John", "21.11.2000", "123456", "654321", "Cool visa info");
    p.print();

    Car c(500, 3, 2);
    c.print();
}