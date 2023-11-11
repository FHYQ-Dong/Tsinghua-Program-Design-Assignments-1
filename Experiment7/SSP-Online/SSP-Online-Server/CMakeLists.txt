cmake_minimum_required(VERSION 3.15)
project(SSP-Online-Server)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

add_subdirectory(include)
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

# target_link_libraries(${PROJECT_NAME} Map)
# target_link_libraries(${PROJECT_NAME} PhoneNum)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_SOURCE_DIR}/include)