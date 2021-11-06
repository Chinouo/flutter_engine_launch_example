# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.15)
add_definitions(-DUNICODE -D_UNICODE)
project ("WinEngine")

# 包含子项目。

add_subdirectory("ViewAndEngine")

#add_subdirectory ("WinEngine")
