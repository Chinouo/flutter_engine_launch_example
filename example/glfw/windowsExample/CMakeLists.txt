# CMakeList.txt: windowsExample 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


project(flutterExample)




set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(GLFW_DIR "D:/src/glfw-3.3.4.bin.WIN64")
set(GLFW_LIB "${GLFW_DIR}/lib-vc2019")

add_executable (windowsExample "windowsExample.cpp" "windowsExample.h" "glad/glad.c")


#引入include文件
target_include_directories(windowsExample PUBLIC "${GLFW_DIR}/include")

#GLAD
set(GLAD_DIR "D:/src/custom_flutter_engine/windowsExample/windowsExample")
target_link_libraries(windowsExample 
${GLFW_LIB}/glfw3.lib
)

##
#Flutter Engine
##
set(FLUTTER_DIR "D:/src/custom_flutter_engine/engine/src/flutter")
target_include_directories(windowsExample PUBLIC "${FLUTTER_DIR}/shell/platform/embedder")
find_library(FLUTTER_LIB NAMES flutter_engine.dll PATHS ${FLUTTER_DIR}/../out/win_debug_unopt)
MESSAGE( STATUS  ${FLUTTER_LIB})
target_link_libraries(windowsExample 
 ${FLUTTER_LIB}
)
# 将源代码添加到此项目的可执行文件。

# TODO: 如有需要，请添加测试并安装目标。
