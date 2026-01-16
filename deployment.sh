rm -rf build

# 生成yuv转换jpg程序
./build-linux.sh -t rv1106 -a armhf -d camera 

./build-linux.sh -t rv1106 -a armhf -d yolo11n

adb shell rm -rf /togethf/rknn_yolo11n_demo
adb shell rm /togethf/nv12_tool

adb push ./install/rv1106_linux_armhf/rknn_yolo11n_demo /togethf
adb push ./install/rv1106_linux_armhf/rknn_camera_demo/nv12_tool /togethf
adb push ./run.sh /togethf

# 进入板子
# adb shell

# ./board_run.sh

# 取回输出
# adb pull


