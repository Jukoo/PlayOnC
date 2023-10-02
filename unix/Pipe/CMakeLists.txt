cmake_minimum_required(VERSION 3.26) 
project(pio.eflb64)  
set(source main.c ipc.c) 

set(CMAKE_BUILD_TYPE Debug) 

if(PIPEN)
  message(STATUS "Using Named Pipe")
  add_definitions(-DIPC_FIFO)  
endif()

include_directories(${PROJECT_NAME} include) 

add_executable(${PROJECT_NAME}  ${source})
