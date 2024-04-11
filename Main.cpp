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
                    (functionsObj.*(functionsObj.getFunctionArray()[choice]))();
                    choice = -1;
                    break;
            }
        }
    }
    endwin();
    return 0;
}
