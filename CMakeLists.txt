
cmake_minimum_required(VERSION 3.20)
project(vnPlugin LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
        yaml-cpp
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG yaml-cpp-0.9.0 # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_MakeAvailable(yaml-cpp)


add_subdirectory(godot-cpp)
target_include_directories(
        godot-cpp
        PUBLIC
        "${CMAKE_SOURCE_DIR}/godot-cpp/gen/include"
)

add_library(vnPlugin SHARED
        src/dialogueText.cpp
        src/register_types.h
        src/register_types.cpp
)

target_compile_features(vnPlugin PRIVATE cxx_std_17)
target_link_libraries(vnPlugin PRIVATE godot-cpp  yaml-cpp::yaml-cpp)

if(WIN32)
    set_target_properties(vnPlugin PROPERTIES
            PREFIX ""
            OUTPUT_NAME "vnPlugin.windows.template_debug.x86_64"
            SUFFIX ".dll"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/project/bin"
    )
elseif(APPLE)
    set_target_properties(vnPlugin PROPERTIES
            PREFIX "lib"
            OUTPUT_NAME "vnPlugin.macos.template_debug"
            SUFFIX ".framework"
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/project/bin"
    )
endif()