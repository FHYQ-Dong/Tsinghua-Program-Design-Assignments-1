cmake_minimum_required(VERSION 3.15)

project(Experiment13-1)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

add_subdirectory(lib)
file(GLOB_RECURSE HEADERS lib/*.h)
file(GLOB_RECURSE LIBS build/lib/*.lib)

target_link_libraries(${PROJECT_NAME} Bool Sex Date Student)

set(CMAKE_INSTALL_PREFIX "../Release")
install(TARGETS Experiment13-1 DESTINATION bin)
install(FILES ${LIBS} DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)