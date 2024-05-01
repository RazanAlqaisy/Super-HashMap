cmake_minimum_required(VERSION 3.28)
project(mySuperHashMap)

set(CMAKE_CXX_STANDARD 17)

add_executable(mySuperHashMap main.cpp
        ObservableKey.h
        ObservableKey.cpp
        SuperHashMap.h
)
