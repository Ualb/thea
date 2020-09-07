cmake_minimum_required(VERSION 3.1)

project(Theia)
set(SOURCES_FILES theia.c analizer/analizer.h analizer/analizer.c utility/utility.h utility/utility.c)
add_executable(Theia ${SOURCES_FILES})
