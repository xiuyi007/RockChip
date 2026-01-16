cmake_minimum_required(VERSION 3.10)
project(nv12_tool)

set(CMAKE_CXX_STANDARD 14)

# 你的脚本会自动传入 TARGET_SOC 等变量，这里我们只需要找库
# 通常 Luckfox SDK 里带了 opencv-mobile 或者标准 opencv

# 查找 OpenCV 包

set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

# 包含头文件
include_directories(${OpenCV_INCLUDE_DIRS})

# 生成可执行文件
add_executable(nv12_tool nv12_jpg.cc)

# 链接库
target_link_libraries(nv12_tool ${OpenCV_LIBS})

# 安装路径 (脚本需要这个 install 步骤)
install(TARGETS nv12_tool DESTINATION ./)