cmake_minimum_required(VERSION 3.15)
project(Pacman-eksamen)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
add_executable(Pacman-eksamen main.cpp Screen.cpp Screen.h GameManager.cpp GameManager.h Entity.cpp Entity.h Controller.cpp Controller.h Character.cpp Character.h PlayerController.cpp PlayerController.h NpcController.cpp NpcController.h Sprite.cpp Sprite.h Pacman.cpp Pacman.h Wall.cpp Wall.h Pellet.cpp Pellet.h PowerPellet.cpp PowerPellet.h)
target_link_libraries(Pacman-eksamen
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})



