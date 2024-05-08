/*
** EPITECH PROJECT, 2024
** Black-Hole-Calculator
** File description:
** Main
*/

#include <iomanip>
#include <iostream>
#include <math.h>
#include "Functions.hpp"

void printButton(const char *label, bool selected) {
    if (selected)
        attron(A_REVERSE);
    printw("[%s]", label);
    attroff(A_REVERSE);
    printw("  ");
}

void displayResult(const char* result) {
    mvprintw(10, 0, "Result: %s", result);
    printw("\nPress any key to continue...");
    refresh();
    getch();
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
    Functions functionsObj;
    const char* options[] = {"Mass", "Temperature", "Radius", "Area", "Surface Gravity", "Time", "Energy"};
    int choice = 0;
    int ch;
    char inputBuffer[100];
    char resultBuffer[100];
    while (ch != 'q') {
        clear();
        printw("What do you want to calculate?\n");
        for (int i = 0; i < sizeof(options) / sizeof(options[0]); ++i)
            printButton(options[i], i == choice);
        refresh();
        if (choice == -1)
            ch = getch();
        else {
            ch = getch();
            switch (ch) {
                case KEY_LEFT:
                    choice = (choice == 0) ? sizeof(options) / sizeof(options[0]) - 1 : choice - 1;
                    break;
                case KEY_RIGHT:
                    choice = (choice + 1) % (sizeof(options) / sizeof(options[0]));
                    break;
                case '\n':
                    clear();
                    refresh();
                    switch (choice) {
                        case 0:
                            functionsObj.calculateMass();
                            sprintf(resultBuffer, "Mass calculation completed.");
                            continue;
                        case 1:
                            functionsObj.calculateTemp();
                            sprintf(resultBuffer, "Temperature calculation completed.");
                            continue;
                        case 2:
                            functionsObj.calculateRadius();
                            sprintf(resultBuffer, "Radius calculation completed.");
                            continue;
                        case 3:
                            functionsObj.calculateArea();
                            sprintf(resultBuffer, "Area calculation completed.");
                            continue;
                        case 4:
                            functionsObj.calculateSurfaceGravity();
                            sprintf(resultBuffer, "Surface Gravity calculation completed.");
                            continue;
                        case 5:
                            functionsObj.calculateTime();
                            sprintf(resultBuffer, "Time calculation completed.");
                            continue;
                        case 6:
                            functionsObj.calculateEnergy();
                            sprintf(resultBuffer, "Energy calculation completed.");
                            continue;
                    }
                    displayResult(resultBuffer);
                    choice = -1;
                    break;
            }
        }
    }
    endwin();
    return 0;
}