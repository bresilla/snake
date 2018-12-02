#pragma once
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>

struct snakepart{
    int x,y;
    snakepart(int col, int row);
    snakepart();
};

class snakeclass{
    private:
        int points,del,maxwidth,maxheigh;
        char direction,partchar,edgechar,foodchar;
        bool get;
        snakepart food;
        std::vector<snakepart> snake;
        void putfood();
        bool collision();
        void movesnake();
    public:
        snakeclass();
        ~snakeclass();
        void start();
};