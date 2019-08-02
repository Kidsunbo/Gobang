cmake_minimum_required(VERSION 3.14)
project(Gobang)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gobang main.cpp Scene.cpp Scene.h MenuScene.cpp MenuScene.h EndScene.cpp EndScene.h SingleGameScene.cpp SingleGameScene.h DoubleGameScene.cpp DoubleGameScene.h ChessDetail/MenuBackGround.cpp ChessDetail/MenuBackGround.h ChessDetail/CheckBoard.cpp ChessDetail/CheckBoard.h)

target_include_directories(Gobang PRIVATE ../SFML/SFML-2.5.1/include)

find_library(GRAPHICS NAMES sfml-graphics-s HINTS ../SFML/SFML-2.5.1/lib)
find_library(WINDOW NAMES sfml-window-s HINTS ../SFML/SFML-2.5.1/lib)
find_library(SYSTEM NAMES sfml-system-s HINTS ../SFML/SFML-2.5.1/lib)
find_library(NETWORK NAMES sfml-network-s HINTS ../SFML/SFML-2.5.1/lib)
find_library(FT NAMES freetype HINTS ../SFML/SFML-2.5.1/lib)

target_link_libraries(Gobang PRIVATE ${GRAPHICS} ${WINDOW} ${SYSTEM} ${NETWORK} opengl32 winmm gdi32 ${FT})