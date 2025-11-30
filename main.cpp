#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
T linear(T a, T b) {
    return -b / a;
}

template<typename T>
std::vector<double> square(T a, T b, T c) {
    double D = b*b - 4 * a * c;

    if (D > 0) return { (-b + std::sqrt(D)) / (2 * a), (-b - std::sqrt(D)) / (2 * a) };
    if (D == 0) return { static_cast<double>(-b) / (2 * a) };
    return {};
}

template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

int main() {
    std::cout << linear(2, -2) << std::endl;
    for (double x: square(1, -5, 4)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << max(1, 2) << std::endl;
    std::cout << min(1, 2) << std::endl;
}
