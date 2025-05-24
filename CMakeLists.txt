cmake_minimum_required(VERSION 3.5) # CMake install : https://cmake.org/download/
# Include build directory for config.h
include_directories(${PROJECT_BINARY_DIR})
project(test1 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "E:/Qt/Qt5.14.2/5.14.2/mingw73_64") # Qt Kit Dir
#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS
aux_source_directory(./src srcs)
list(APPEND srcs "src/global.cpp")
list(APPEND srcs "src/json.cpp")
aux_source_directory(./src/view views)
aux_source_directory(./src/model models)
aux_source_directory(./src/control controls)
file(GLOB includes "include/*.h")
file(GLOB includes2 "include/control/*.h")
file(GLOB includes3 "include/model/*.h")

# 获取 src/view 目录下所有 .ui 文件的列表
file(GLOB UI_FILES src/view/*.ui)

# 自动处理 UI 文件
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

add_executable(${PROJECT_NAME}
    ${includes}
    ${includes2}
    ${includes3}
    ${srcs}
    ${views}
    ${models}
    ${controls}
    ${UI_HEADERS}
    #res.qrc
)
# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

#add_executable(${PROJECT_NAME}
#    WIN32 # If you need a terminal for debug, please comment this statement
#    ${srcs}
#)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets) # Qt5 Shared Library
