cmake_minimum_required(VERSION 2.6)
include(ExternalProject)

ExternalProject_Add(rapidjson
    GIT_REPOSITORY "https://github.com/miloyip/rapidjson/"
    GIT_TAG "v1.1.0"
    CMAKE_ARGS
    "-DRAPIDJSON_BUILD_TESTS=OFF"
    "-DRAPIDJSON_BUILD_EXAMPLES=OFF"
    "-DRAPIDJSON_BUILD_DOC=OFF"
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
)

SET(ENV{BOOST_ROOT} "/usr/lib")

#substitute your version number
find_package(Boost 1.61 EXACT REQUIRED COMPONENTS python)
INCLUDE_DIRECTORIES("${Boost_INCLUDE_DIRS}")

find_package( PythonLibs 2.7 REQUIRED )
INCLUDE_DIRECTORIES("${PYTHON_INCLUDE_DIRS}")

ADD_LIBRARY(simple SHARED simple.cpp)
TARGET_LINK_LIBRARIES(simple ${Boost_LIBRARIES})
set_target_properties(simple PROPERTIES PREFIX "" )
