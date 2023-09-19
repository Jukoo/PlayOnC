cmake_minimum_required (VERSION 3.26)
project(smphcr.elfbin)  

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_STANDARD_REQUIRED True) 

add_executable(${PROJECT_NAME} main.c  smphr.c)
target_link_libraries(${PROJECT_NAME}  pthread)
