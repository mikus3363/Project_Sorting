cmake_minimum_required(VERSION 3.27)
project(ProjektAIZO)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(.)

add_executable(ProjektAIZO
        Menu.cpp
        Menu.h
        initTab.cpp
        initTab.h
        main.cpp
        Insertion.h
        Insertion.cpp
        Quick.h
        Quick.cpp
        Shell.h
        Shell.cpp
        Heap.h
        Heap.cpp
)
