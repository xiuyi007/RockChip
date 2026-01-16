# 卡住就执行这个
# rkaiq_3A_server &
echo "--------take photo --------"

v4l2-ctl --device=/dev/video11 --set-fmt-video=width=1024,height=1024,pixelformat=NV12 --stream-mmap --stream-to=raw.yuv --stream-count=1

echo "-------- convert jpg --------"

./nv12_tool raw.yuv model/pest.jpg 1024 1024

echo "------- detect -------"
./rknn_yolo11_demo model/pest.rknn model/pest.jpg
