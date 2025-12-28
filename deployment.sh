rm -rf build

./build-linux.sh -t rv1106 -a armhf -d yolo11n

adb shell rm -rf /togethf/rknn_yolo11n_demo /board_run.sh

adb push ./install/rv1106_linux_armhf/rknn_yolo11n_demo /togethf
adb push ./board_run.sh /

adb shell

# ./board_run.sh

# adb pull /togethf/rknn_yolo11n_demo/out.png .