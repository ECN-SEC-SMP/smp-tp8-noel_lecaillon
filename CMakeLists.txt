cmake_minimum_required(VERSION 3.10)
project(TP7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclure les fichiers d’en-tête
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)

# Liste des fichiers sources
set(SOURCES
    main.cpp
    src/animal.cpp
    src/attaque.cpp
    src/lion.cpp
    src/loup.cpp
    src/ours.cpp
    src/pierre.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})