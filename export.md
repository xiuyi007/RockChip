# Adjust the model file path in "./ultralytics/cfg/default.yaml" (default is yolo11n.pt). If you trained your own model, please provide the corresponding path. 
# For example, filled with yolo11n.pt for detection model.
# Filling with yolo11n-seg.pt for segmentation model.
# Filling with yolo11n-pose.pt for pose model.
# Filling with yolo11n-obb.pt for obb model.

export PYTHONPATH=./
python ./ultralytics/engine/exporter.py

# Upon completion, the ".onnx" model will be generated. If the original model is "yolo11n.pt," the generated model will be "yolo11n.onnx"