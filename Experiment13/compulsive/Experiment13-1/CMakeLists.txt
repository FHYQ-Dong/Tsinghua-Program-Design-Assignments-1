cmake_minimum_required(VERSION 3.15)

project(Experiment13-1)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

add_subdirectory(include)
file(GLOB_RECURSE HEADERS include/*.h)
file(GLOB_RECURSE LIBS build/include/*.a)

target_link_libraries(${PROJECT_NAME} Bool Sex Date Student FileHandler args)

set(CMAKE_INSTALL_PREFIX "../Release")
install(TARGETS Experiment13-1 DESTINATION bin)
install(FILES ${LIBS} DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)