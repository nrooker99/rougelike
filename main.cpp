
// To compile: g++ main.cpp -lncurses

#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <ncurses.h>
#include <fstream>
#include "player.h"
#include "room.h"


using namespace std;

int main(int argc,  char ** argv) {
    initscr();
    cbreak(); 
    noecho();

    if (!has_colors()) {
    endwin();
    printf("A terminal that supports color is required to play this game.");
    exit(1);
    } 

    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * win = newwin(yMax - 5, xMax, 0, 0);
    refresh();

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLUE);

    wattron(win, COLOR_PAIR(1));
    box(win, 0, 0);
    wrefresh(win);
    wattroff(win, COLOR_PAIR(1));

    Player * p = new Player(win, 1, 1, '@');
    
    Room r(win, "room1.txt");
    do {
        p->display();
        wrefresh(win);
     } while (p->getmv() != 'x');
       
    getch();

    endwin();

    return 0;
}