add_library(snake STATIC inc/snake.cpp)

link_directories(/usr/lib)

add_executable(main main.cpp)

target_link_libraries(main
    snake
    ncurses
)
