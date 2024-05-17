cmake_minimum_required(VERSION 3.25.1)

project(Projekt)

file( GLOB LIB_SOURCES ./lib/*.cpp )
file( GLOB LIB_HEADERS ./lib/*.h )
add_library( YourLib ${LIB_SOURCES} ${LIB_HEADERS} )

file( GLOB APP_SOURCES ./main.cpp )
foreach( testsourcefile ${APP_SOURCES} )
    # Cut off the file extension and directory path
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    target_link_libraries( ${testname} YourLib )
endforeach( testsourcefile ${APP_SOURCES} )

