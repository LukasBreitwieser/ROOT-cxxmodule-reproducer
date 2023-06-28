cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(myapp)

find_package(ROOT REQUIRED COMPONENTS Core)
include(${ROOT_USE_FILE})

add_executable(myapp main.cc)
target_link_libraries(myapp ROOT::RIO)
ROOT_GENERATE_DICTIONARY(myapp_dict 
                         functor.h 
                         MODULE myapp 
                         LINKDEF LinkDef.h
                         OPTIONS --cxxmodule)

# Uncomment the following lines to fix the compilation error:
# error: cannot emit module myapp: size must be explicitly specified for missing header file "functor.h"
# add_custom_target(fix-modulemap
#                   COMMAND sed -i  "s|header \"functor.h\"|header \"../functor.h\"|g" ${CMAKE_CURRENT_BINARY_DIR}/module.modulemap
#                   VERBATIM)
# add_dependencies(myapp_dict fix-modulemap)
