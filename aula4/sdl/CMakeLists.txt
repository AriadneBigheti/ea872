# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(Asteroids)

#
add_executable(Asteroids src/main.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(SystemModel src/SystemModel.cpp)
target_link_libraries(Asteroids SystemModel)
add_library(SystemView src/SystemView.cpp)
target_link_libraries(Asteroids SystemView)
add_library(SystemController src/SystemController.cpp)
target_link_libraries(Asteroids SystemController)

# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
target_link_libraries(Asteroids SDL2)
target_link_libraries(Asteroids SDL2_image)
