#include "Functions.hpp"

// gravitational constant
#define G_value 6.674184
#define G_power -11
#define G (G_value * pow(10, G_power))

// light speed in void
#define c 299792458

// Pi
#define PI 3.14159265358979323846

// planck constant
#define h_value 6.62607015
#define h_power -34
#define h (h_value * pow(10, h_power))

// Boltzmann constant
#define K_value 1.380649
#define K_power -23
#define K (K_value * pow(10, K_power))

// Stefan-Boltzmann constant
#define sigma_value 5.670374419
#define sigma_power -8
#define sigma (sigma_value * pow(10, sigma_power))

Functions::Functions() {}

Functions::~Functions() {}

void Functions::calculateMass() {
    char input[100];
    double A = 0;
    printw("\nEnter the area of the black hole in meters:\n");
    refresh();
    getstr(input);
    sscanf(input, "%lf", &A);
    double masse = sqrt((pow(c, 4) * A) / (16 * PI * G));
    printw("Mass of the black hole: %lf kg\n", masse);
    refresh();
}

void Functions::calculateTemp() {
    double T = 0, m = 0;
    printw("Enter the mass of the black hole in kilograms:\n");
    scanw("%lf", &m);
    T = (1 / (8 * PI * K)) * ((h * pow(c, 3)) / (G * m));
    printw("The temperature of the black hole is %lfK\n", T);
}

void Functions::calculateRadius() {
    double masse = 0, radius = 0;
    printw("Enter the mass of the black hole in kilograms:\n");
    scanw("%lf", &masse);
    radius = (2 * G * masse) / pow(c, 2);
    printw("Radius of the black hole in meters: %lf\n", radius);
}

void Functions::calculateArea() {
    double area = 0, masse = 0;
    printw("Enter the mass of the black hole in kilograms:\n");
    scanw("%lf", &masse);
    area = (16 * PI * pow(G, 2) * pow(masse, 2)) / pow(c, 4);
    printw("Area of the black hole in meters: %lf\n", area);
}

void Functions::calculateSurfaceGravity() {
    double k = 0, m = 0, radius = 0;
    printw("Enter the mass of the black hole in kilograms and the radius in meters:\n");
    scanw("%lf %lf", &m, &radius);
    k = (G * m) / pow(radius, 2);
    printw("The Surface gravity of the black hole is %lf m/s²\n", k);
}

void Functions::calculateTime() {
    double time = 0, masse = 0;
    printw("Enter the mass of the black hole in kilograms:\n");
    scanw("%lf", &masse);
    time = 5120 * PI * (pow(G, 2) / (pow(c, 4) * h)) * pow(masse, 3);
    printw("The black hole will be evaporated in %lf seconds\n", time);
}

void Functions::calculateEnergy() {
    double energy = 0, radius = 0, k = 0;
    printw("Enter the radius of the black hole in meters and the temperature in kelvins:\n");
    scanw("%lf %lf", &radius, &k);
    energy = 4 * PI * pow(radius, 2) * sigma * pow(k, 4);
    printw("The black hole emits %lf W\n", energy);
}

Functions::FunctionPtr* Functions::getFunctionArray() {
    return functions;
}
