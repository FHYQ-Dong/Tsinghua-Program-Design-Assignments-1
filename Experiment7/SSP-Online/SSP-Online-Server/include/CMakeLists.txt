link_libraries(ws2_32.lib)

# Define a library called "ssp-online-server" that will be built from the source files in this directory
add_library(ssp-online-server-judge STATIC judge.c judge.h)
add_library(ssp-online-server-player STATIC player.c player.h)
add_library(ssp-online-server-web-socket STATIC web-socket.c web-socket.h)

# Link the library to any other libraries it depends on
# target_link_libraries(ssp-online-server
#     PRIVATE
#         lib1
#         lib2
# )
