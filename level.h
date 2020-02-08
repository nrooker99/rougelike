#define _ROOM_H_
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

class Level {
    public:
    Level(WINDOW * win, string filename);
    void printroom(WINDOW * win, string filename);
};

Level::Level(WINDOW * win, string filename) {
    printroom(win, filename);
}

void Level::printroom(WINDOW * win, string filename) {
    string line, yPos, xPos, direction, length;
    ifstream ifs;
    ifs.open(filename);
    
    if (ifs.is_open()){
        while (!ifs.eof()) {
            getline(ifs, yPos, ',');
            getline(ifs, xPos, ',');
            getline(ifs, direction, ',');
            getline(ifs, length);

            int yInt = atoi(yPos.c_str());
            int xInt = atoi(xPos.c_str());
            int lengthInt = atoi(length.c_str()); 
           
            switch (direction[0]) {
            case 'u':
                for (int i = 0; i < lengthInt; ++i) {
                    if (yInt > 0) { mvwaddch(win, yInt, xInt, '|'); }
                    --yInt;
                }
                break;
            case 'l':


                break;
            case 'd':
                for (int i = 0; i < lengthInt; ++i) {
                    if (yInt > 0) mvwaddch(win, yInt, xInt, '|');
                    ++yInt;
                }

                break;
            case 'r':

                break;
            
            default:
                break;
            }
            
        }
        
        ifs.close();
    }

}