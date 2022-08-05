cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
include_directories(src)
include_directories(helpers)

set(SRC
    src/Board.cpp
    src/Easy.cpp
    src/Medium.cpp
    src/Hard.cpp
    src/Game.cpp
)

set(FLAGS
    -Wall
    -pedantic
    -Wconversion
    -Wextra
)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
