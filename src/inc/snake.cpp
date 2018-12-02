#include "snake.h"

snakepart::snakepart(int col, int row){
    x = col; y = row;
}

snakepart::snakepart(){
    x,y = 0;
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
    food.x = 0;
    food.y = 0;
    for (size_t i = 0; i < 5; i++){
        snake.push_back(snakepart(40+i,10));
    }
    points = 0;
    del = 110000;
    get = 0;
    direction = 'l';
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
    while(1){
        int tmpx=rand()%maxwidth+1;
        int tmpy=rand()%maxheigh+1;
        for(int i = 0; i < snake.size(); i++){
            if (snake[i].x == tmpx && snake[i].y == tmpy){
                continue;
            }
        }
        
        if (tmpx>=maxwidth-2 || tmpy>=maxheigh-3) {
            continue;
        }
        food.x=tmpx;
        food.y=tmpy;    
        break;
    }
    move(food.y,food.x);
    addch(foodchar);
    refresh();
};

bool snakeclass::collision(){
    
    if (snake[0].x == 0 || snake[0].x == maxwidth-1 || snake[0].y == 0 || snake[0].y==maxheigh-2){
        return true;
    }

    for(int i = 2; i < snake.size(); i++)
    {
        if (snake[0].x==snake[i].x && snake[0].y == snake[i].y){
            return true;
        }
    }

    if (snake[0].x == food.x && snake[0].y == food.y){
        get=true;
        putfood();
        points+=10;
        move(maxheigh-1,0);
        printw("%d",points);
        if(points%100==0){
            del-=10000;
        }
    }
    else{
        get = false;
    }
    return false;
}

void snakeclass::movesnake(){
    int tmp = getch();
    
    switch (tmp){
        case KEY_LEFT:
            if (direction!='r'){direction='l';}
            break;
        case KEY_UP:
            if (direction!='d'){direction='u';}
            break;   
        case KEY_DOWN:
            if (direction!='u'){direction='d';}
            break;   
        case KEY_RIGHT:
            if (direction!='l'){direction='r';}
            break;
        case KEY_BACKSPACE:
            direction='q';
            break;
    }
    
    if (!get) {
        move(snake[snake.size()-1].y,snake[snake.size()-1].x);
        addch(' ');
        refresh();
        snake.pop_back();
    }

    
    if (direction=='l') {
        snake.insert(snake.begin(),snakepart(snake[0].x-1,snake[0].y));
    }
    else if (direction=='r'){
        snake.insert(snake.begin(),snakepart(snake[0].x+1,snake[0].y));
    }
    else if (direction=='u'){
        snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y-1));
    }
    else if (direction=='d'){
        snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y+1));
    }
    move(snake[0].y,snake[0].x);
    addch(partchar);
}

void snakeclass::start(){
    while(1){
        if(collision()){
            move(maxwidth/2-4,maxheigh/2);
            printw("GAME OVER");
            break;
        }
        movesnake();
        if (direction=='q') {break;}
        usleep(del);
    }
    
    
}

