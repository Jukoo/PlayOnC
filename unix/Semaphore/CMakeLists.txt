cmake_minimum_required (VERSION 3.26)
project(smphcr.elfbin)  

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_STANDARD_REQUIRED True) 
set(CMAKE_BUILD_TYPE Debug) 

if(NAMEDSMPR)  
  message(STATUS "Named Semaphore") 
  add_compile_definitions(NAMEDSMPR) 

endif() 

add_executable(${PROJECT_NAME} main.c  smphr.c)
target_link_libraries(${PROJECT_NAME}  pthread)
