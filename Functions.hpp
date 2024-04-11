/*
** EPITECH PROJECT, 2024
** Black-Hole-Calculator
** File description:
** Functions
*/

#pragma once

#include <iostream>
#include <cmath>
#include <ncurses.h>


class Functions {
    public:
        Functions();
        ~Functions();

        void calculateMass();
        void calculateTemp();
        void calculateRadius();
        void calculateArea();
        void calculateSurfaceGravity();
        void calculateTime();
        void calculateEnergy();
        typedef void (Functions::*FunctionPtr)();
        FunctionPtr* getFunctionArray();

    private:
        FunctionPtr functions[7] = {&Functions::calculateMass,
                                    &Functions::calculateTemp,
                                    &Functions::calculateRadius,
                                    &Functions::calculateArea,
                                    &Functions::calculateSurfaceGravity,
                                    &Functions::calculateTime,
                                    &Functions::calculateEnergy};
};
