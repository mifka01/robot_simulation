cmake_minimum_required(VERSION 3.5)
project(robots)


# Compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# for vim
add_compile_options(-Wall -Wextra)

# Qt
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Source
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.hpp")

include_directories(include)

# Output
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
