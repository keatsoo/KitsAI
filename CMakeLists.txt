cmake_minimum_required(VERSION 3.0)
project(KitsAI)

set(SOURCES src/main.cpp)
set(HEADERS src/includes/ReseauNeuronal/ReseauNeuronal.hpp src/includes/ReseauNeuronal/Couche/Couche.hpp src/includes/ReseauNeuronal/Neurone/Neurone.hpp)

add_executable(KitsAI ${SOURCES} ${HEADERS} src/includes/ReseauNeuronal/ReseauNeuronal.cpp src/includes/ReseauNeuronal/Couche/Couche.cpp src/includes/ReseauNeuronal/Neurone/Neurone.cpp)
