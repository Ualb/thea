cmake_minimum_required(VERSION 3.1)
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)
project(Theia)
set(SOURCES_FILES src/theia.c
        src/engine_string/analizer.h src/engine_string/analizer.c
        src/errors/panic.h src/errors/panic.c
        src/equifinality/iofile.c src/equifinality/iofile.h
        src/constants.h
        test/sintact_analizer_test.c)
add_executable(Theia ${SOURCES_FILES})
