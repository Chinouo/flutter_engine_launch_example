cmake_minimum_required (VERSION 3.15)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
add_definitions(-D_AFXDLL)
add_definitions(-DUNICODE -D_UNICODE)
set(CMAKE_MFC_FLAG 2)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(FLUTTER_WIN32 "D:/src/custom_flutter_engine/engine/src/flutter/shell/platform/windows")

set(FLUTTER_LIB "D:/src/custom_flutter_engine/engine/src")

add_executable (ViewAndEngine WIN32 "controller.cpp" "controller.h")

target_include_directories(
	ViewAndEngine
	PUBLIC
	"${FLUTTER_LIB}" 
	"${FLUTTER_LIB}/flutter/shell/platform/common/public"
)


find_library(FLUTTER_WIN NAMES  flutter_windows.dll PATHS ${FLUTTER_LIB}/out/win_debug_unopt)
MESSAGE( STATUS  ${FLUTTER_WIN} )
target_link_libraries(ViewAndEngine 
 ${FLUTTER_WIN}
)

