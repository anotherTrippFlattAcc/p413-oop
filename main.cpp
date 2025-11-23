#include <iostream>
#include <vector>
#include <pstl/execution_defs.h>

class List {
protected:
    std::vector<int> data;

public:
    virtual void insert(int value) = 0;

    virtual int remove() = 0;

    void print() const {
        std::cout << "[";
        for (int i = 0; i < data.size(); i++) {
            std::cout << data.at(i);
            if (i + 1 != data.size()) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

class Stack: public List {
public:
    void insert(int value) override {
        data.insert(data.begin(), value);
    }

    int remove() override {
        if (!data.empty()) {
            int value = data.front();
            data.erase(data.begin());
            return value;
        }
    }
};

class Queue: public List {
public:
    void insert(int value) override {
        data.insert(data.end(), value);
    }

    int remove() override {
        if (!data.empty()) {
            int value = data.back();
            data.erase(data.begin());
            return value;
        }
    }
};

class Pet {
protected:
    std::string name;
    std::string chars;

public:
    Pet(const std::string& name, const std::string& chars): name(name), chars(chars) {}

    virtual void Sound() const = 0;

    virtual void Type() const = 0;

    virtual void Show() const {
        std::cout << "Pet" << "\n\tName: " << name << "\n\tCharacteristics: " << chars << std::endl;
    }
};

class Dog: public Pet {
public:
    Dog(const std::string& name, const std::string& chars): Pet(name, chars) {}

    void Sound() const override {
        std::cout << "Dog " << name << " is barking" << std::endl;
    }

    void Type() const override {
        std::cout << "Pet " << name << " is dog" << std::endl;
    }
};

class Cat: public Pet {
public:
    Cat(const std::string& name, const std::string& chars): Pet(name, chars) {}

    void Sound() const override {
        std::cout << "Cat " << name << " is meowing" << std::endl;
    }

    void Type() const override {
        std::cout << "Pet " << name << " is cat" << std::endl;
    }
};

class Parrot: public Pet {
public:
    Parrot(const std::string& name, const std::string& chars): Pet(name, chars) {}

    void Sound() const override {
        std::cout << "Parrot " << name << " is chirping" << std::endl;
    }

    void Type() const override {
        std::cout << "Pet " << name << " is parrot" << std::endl;
    }
};

class Hamster: public Pet {
public:
    Hamster(const std::string& name, const std::string& chars): Pet(name, chars) {}

    void Sound() const override {
        std::cout << "Hamster " << name << " is squeaking" << std::endl;
    }

    void Type() const override {
        std::cout << "Pet " << name << " is hamster" << std::endl;
    }
};

void firstTask() {
    Stack s;

    std::cout << "Stack:" << std::endl;

    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.print();

    s.remove();
    s.print();

    Queue q;

    std::cout << "Queue:" << std::endl;

    q.insert(5);
    q.insert(10);
    q.insert(15);
    q.print();

    q.remove();
    q.print();
}

void secondTask() {
    Dog dog("Bob", "Funny and energetic");
    Cat cat("Luna", "Lazy and fluffy");
    Parrot parrot("Buddy", "Loud and talkative");
    Hamster hamster("Daisy", "Tiny and fast");

    Pet* pets[] = { &dog, &cat, &parrot, &hamster };

    for (Pet* pet: pets) {
        pet->Show();
        pet->Type();
        pet->Sound();
        std::cout << std::endl;
    }
}

int main() {
    firstTask();
    secondTask();
}