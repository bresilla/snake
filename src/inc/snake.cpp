#include "snake.h"

snakepart::snakepart(int col, int row){
    x=col;
    y=row;
}

snakepart::snakepart(){
    x,y=0;
}

snakeclass::snakeclass(){
    initscr();
    nodelay(stdscr,1);
    keypad(stdscr,1);
    noecho();
    curs_set(0);
    maxheigh = getmaxy(stdscr);
    maxwidth = getmaxx(stdscr);
    partchar = 'x';
    edgechar = (char)219;
    foodchar = '*';
    food.x=0;
    food.y=0;
    for (size_t i = 0; i < 5; i++){
        snake.push_back(snakepart(40+1,10));
    }
    points=0;
    del=110000;
    get=0;
    direction='l';
    srand(time(0));
    putfood();
    for (size_t i = 0; i < maxwidth-1; i++){
        move(0,i);
        addch(edgechar);
    }
    for (size_t i = 0; i < maxwidth-1; i++){
        move(maxheigh-2,i);
        addch(edgechar);
    }
    for (size_t i = 0; i < maxheigh-1; i++){
        move(i,0);
        addch(edgechar);
    }
    for (size_t i = 0; i < maxheigh-2; i++){
        move(i,maxwidth-1);
        addch(edgechar);
    }
    for (size_t i = 0; i < snake.size(); i++)
    {
        move(snake[i].y,snake[i].x);
        addch(partchar);
    }   
    move(maxheigh-1,0);
    printw("%d",points);
    move(food.y,food.x);
    addch(foodchar);
    refresh();
}

snakeclass::~snakeclass(){
    nodelay(stdscr,0);
    getch();
    endwin();
}

void snakeclass::putfood(){
    food.x=10;
    food.y=10;
};

