cmake_minimum_required(VERSION 3.10)

project(chess-terminal VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/src/include)

set(SOURCES
    src/main.cpp
    src/bishop.cpp
    src/board.cpp
    src/game.cpp
    src/king.cpp
    src/knight.cpp
    src/pawn.cpp
    src/piece.cpp
    src/queen.cpp
    src/rook.cpp
)

set(HEADERS
    src/include/bishop.hpp
    src/include/board.hpp
    src/include/game.hpp
    src/include/king.hpp
    src/include/knight.hpp
    src/include/pawn.hpp
    src/include/piece.hpp
    src/include/queen.hpp
    src/include/rook.hpp
)

add_executable(chess ${SOURCES} ${HEADERS})

if(MSVC)
    target_compile_options(chess PRIVATE /W4)
else()
    target_compile_options(chess PRIVATE -Wall -Wextra -Wpedantic)
endif()

set_target_properties(chess PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
