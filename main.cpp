#include <iostream>
#include <string>
#include <vector>

class Book {
    std::string author;
    std::string title;
    std::string publisher;
    int year;
    int pages;

public:
    explicit Book (const std::string& a, const std::string& t, const std::string& pub, const int y, const int p):
    author(a), title(t), publisher(pub), year(y), pages(p) {}

    void print() const {
        std::cout << "---\n" << "Book \"" << title << "\" by " << author <<
            "\nPublisher: " << publisher << "\nYear: " << year << "\nPages: " << pages << "\n---" << std::endl;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getPublisher() const {
        return publisher;
    }

    int getYear() const {
        return year;
    }
};

class Worker {
    std::string FIO;
    std::string position;
    int year;
    int salary;

public:
    explicit Worker (const std::string& fio, const std::string& p, const int y, const int s):
        FIO(fio), position(p), year(y), salary(s) {}

    void print() const {
        std::cout << "---\n" << "Worker " << FIO << "\nPosition: " << position <<
            "\nEmployment year: " << year << "\nSalary: " << salary << "\n---" << std::endl;
    }

    int getYear() const {
        return year;
    }

    int getSalary() const {
        return salary;
    }

    std::string getPosition() const {
        return position;
    }
};

void printBooksByAuthor(const std::vector<Book>& books, const std::string& author) {
    std::cout << author << "\'s books:" << std::endl;
    for (Book book: books) {
        if (book.getAuthor() == author) {
            book.print();
        }
    }
}

void printBooksByPublisher(const std::vector<Book>& books, const std::string& publisher) {
    std::cout << "Books published by " << publisher <<  ":" << std::endl;
    for (Book book: books) {
        if (book.getPublisher() == publisher) {
            book.print();
        }
    }
}

void printBooksByYear(const std::vector<Book>& books, const int year) {
    std::cout << "Books made after " << year << ":" << std::endl;
    for (Book book: books) {
        if (book.getYear() > year) {
            book.print();
        }
    }
}

void printWorkersByExperience(const std::vector<Worker>& workers, const int experience) {
    std::cout << "Workers with experience more than " << experience << " years:" << std::endl;
    for (Worker worker: workers) {
        if (2025 - worker.getYear() > experience) {
            worker.print();
        }
    }
}

void printWorkersBySalary(const std::vector<Worker>& workers, const int salary) {
    std::cout << "Workers with salary more than $" << salary << ":" << std::endl;
    for (Worker worker: workers) {
        if (worker.getSalary() > salary) {
            worker.print();
        }
    }
}

void printWorkersByPosition(const std::vector<Worker>& workers, const std::string& position) {
    std::cout << "Workers at " << position << " position:" << std::endl;
    for (Worker worker: workers) {
        if (worker.getPosition() == position) {
            worker.print();
        }
    }
}

int main() {
    std::vector<Book> books {
        Book("George Orwell", "1984", "Secker and Warburg", 1948, 500),
        Book("Mary Shelley", "Frankenstein", "Lackington, Hughes, Harding, Mavor & Jones", 1818, 400),
        Book("Ray Douglas Bradbury", "Fahrenheit 451", "Ballantine Books", 1953, 450)
    };

    std::vector<Worker> workers {
        Worker("Bob White", "Senior Programmer", 2018, 1200),
        Worker("John Smith", "Middle Programmer", 2022, 800),
        Worker("Tom Gray", "Junior Programmer", 2024, 600)
    };

    printBooksByAuthor(books ,"George Orwell");
    printBooksByPublisher(books, "Lackington, Hughes, Harding, Mavor & Jones");
    printBooksByYear(books, 1950);

    printWorkersByExperience(workers, 6);
    printWorkersBySalary(workers, 700);
    printWorkersByPosition(workers, "Junior Programmer");
}