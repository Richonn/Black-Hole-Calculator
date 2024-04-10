#include <iomanip>
#include <iostream>
#include <math.h>

// gravitational constant
#define G_value 6.674184
#define G_power -11
#define G (G_value * pow(10, G_power))

// light speed in void
#define c 299792458

// Pi
#define PI 3.14159265358979323846

// planck constant
#define h_value 6,62607015
#define h_power -34
#define h (h_value * pow(10, h_power))

// Boltzmann constant
#define K_value 1,380649
#define K_power -23
#define K (K_value * pow(10, K_power))

// Stefan-Boltzmann constant
#define sigma_value 5,670374419
#define sigma_power -8
#define sigma (sigma_value * pow(10, sigma_power))

void calculateMasse() {
    double masse = 0, A = 0;
    std::cout << "Enter the area of the black hole in meters:" << std::endl;
    std::cin >> A;
    masse = sqrt((pow(c, 4) * A) / 16 * PI * G);
    std::cout << "Masse of the black hole is in kilogrammes: " << masse << std::endl;
}

void calculateTemp() {
    double T = 0, m = 0;
    std::cout << "Enter the masse of the black hole in kilogrammes" << std::endl;
    std::cin >> m;
    T = (1 / 8 * PI * K) * ((h * pow(c, 3)) / G * m);
    std::cout << "The temperature of the black hole is " << T << "K" << std::endl;
}

void calculateRadius() {
    double masse = 0, radius = 0;
    std::cout << "Enter the masse of the black hole in kilogrammes" << std::endl;
    std::cin >> masse;
    radius = (2 * G * masse) / pow(c, 2);
    std::cout << "Radius of the black hole in meters: " << radius << std::endl;
}

void calculateArea() {
    double area = 0, masse = 0;
    std::cout << "Enter the masse of the black hole in kilogrammes" << std::endl;
    std::cin >> masse;
    area = (16 * PI * pow(G, 2) * pow(masse, 2)) / pow(c, 4);
    std::cout << "Area of the black hole in meters: " << area << std::endl;
}

void calculateSurfaceGravity() {
    double k = 0, m = 0, radius = 0;
    std::cout << "Enter the masse of the black hole in kilogrammes and the radius in meters" << std::endl;
    std::cin >> m >> radius;
    k = (G * m) / pow(radius, 2);
    std::cout << "The Surface gravity of the black hole is " << k << "m/s²" << std::endl;
}

void calculateTime() {
    double time = 0, masse = 0;
    std::cout << "Enter the masse of the black hole in kilogrammes and the radius in meters" << std::endl;
    std::cin >> masse;
    time = 5120 * PI * (pow(G, 2) / (pow(c, 4) * h)) * pow(masse, 3);
    std::cout << "The black hole will be evaporated in " << time << "seconds" << std::endl;
}

void calculateEnergy() {
    double energy = 0, radius = 0, k = 0;
    std::cout << "Enter the radius of the black hole in meters and the temperature in kelvins" << std::endl;
    std::cin >> radius >> k;
    energy = 4 * PI * pow(radius, 2) * sigma * pow(k, 4);
    std::cout << "The black hole emits " << energy << "W" << std::endl;

}

int main(void) {
    while (true) {
        std::string option;
        std::cout << "What do you want to calcultate ?\n-Masse M\n-Temperature T\n-Radius R\n-Area A\n-Surface Gravity K\n-Time Ti\n-Energy E" << std::endl;
        std::getline(std::cin, option);
        if (option == "M") {
            calculateMasse();
            return 0;
        } else if (option == "T") {
            calculateTemp();
            return 0;
        } else if (option == "A") {
            calculateArea();
            return 0;
        } else if (option == "R") {
            calculateRadius();
            return 0;
        } else if (option == "K") {
            calculateSurfaceGravity();
            return 0;
        } else if (option == "Ti") {
            calculateTime();
            return 0;
        } else if (option == "E") {
            calculateEnergy();
            return 0;
        } else
            std::cout << "invalid option" << std::endl;
        option.clear();
    }
    return 0;
}
