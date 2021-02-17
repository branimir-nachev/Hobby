cmake_minimum_required(VERSION 3.17)
project(Work)

set(CMAKE_CXX_STANDARD 20)

add_executable(Work main.cpp Person.cpp Person.hpp FamilyMember.cpp FamilyMember.hpp)