cmake_minimum_required(VERSION 3.10)

project(CalcCLI LANGUAGES CXX)

file(GLOB SOURCES "src/*.cpp")

add_executable(calccli ${SOURCES})
