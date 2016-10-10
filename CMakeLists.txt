cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

# SET(CMAKE_CXX_FLAGS "-std=c++0x")
ExternalProject_Add(rapidjson
    GIT_REPOSITORY "https://github.com/miloyip/rapidjson/"
    GIT_TAG "v1.0.2"
    CMAKE_ARGS
    "-DRAPIDJSON_BUILD_TESTS=OFF"
    "-DRAPIDJSON_BUILD_EXAMPLES=OFF"
    "-DRAPIDJSON_BUILD_DOC=OFF"
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
)
ExternalProject_Get_Property(rapidjson SOURCE_DIR)
include_directories(${SOURCE_DIR}/include)


SET(ENV{BOOST_ROOT} "/usr/lib")

#substitute your version number
find_package(Boost REQUIRED COMPONENTS python)
INCLUDE_DIRECTORIES("${Boost_INCLUDE_DIRS}")

find_package( PythonLibs 2.7 REQUIRED )
INCLUDE_DIRECTORIES("${PYTHON_INCLUDE_DIRS}")

ADD_LIBRARY(simple SHARED simple.cpp)
add_dependencies(simple rapidjson)
TARGET_LINK_LIBRARIES(simple ${Boost_LIBRARIES})
SET_TARGET_PROPERTIES(simple PROPERTIES PREFIX "" )
