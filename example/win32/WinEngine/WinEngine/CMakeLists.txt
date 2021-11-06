# CMakeList.txt: WinEngine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.15)

#设定C++版本
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

#设置MFC
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

#设置flutter引擎路径
set(FLUTTER_LIB "D:/src/custom_flutter_engine/engine/src")

# 将源代码添加到此项目的可执行文件。
add_executable (WinEngine WIN32 "WinEngine.cpp" "WinEngine.h")
#添加头文件
target_include_directories(
	WinEngine
	PRIVATE
	${FLUTTER_LIB} 
)





# TODO: 如有需要，请添加测试并安装目标。
