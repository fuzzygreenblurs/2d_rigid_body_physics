cmake_minimum_required(VERSION 3.15)
project(2dPhysics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(/opt/homebrew/include/SDL2)
link_directories(/opt/homebrew/lib)

file(GLOB_RECURSE SRC_FILES
  src/*.cpp
)

add_executable(app ${SRC_FILES})

include_directories(/opt/homebrew/include/SDL2)
link_directories(opt/homebrew/lib)

target_link_libraries(app
  SDL2
  SDL2_gfx
  SDL2_image
)
