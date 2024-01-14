# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# C_version
set(CMAKE_C_STANDARD 99)

# Project name
project(SSP-client)

# Add your source files here
AUX_SOURCE_DIRECTORY(src/ SOURCES)
# Add your header filessource directory here
AUX_SOURCE_DIRECTORY(include/ HEADERS)

# Add executable target
add_executable(${PROJECT_NAME} client.c ${SOURCES} ${HEADERS})

# install target
install(TARGETS ${PROJECT_NAME} DESTINATION bin)