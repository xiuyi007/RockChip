#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // 为了使用 atoi

int main(int argc, char** argv) {
    // 默认值 (如果没有输入参数)
    const char* input_path = "raw.yuv";
    const char* output_path = "out.jpg";
    int width = 2304;
    int height = 1296;

    // 解析命令行参数
    // 用法: ./nv12_tool <input> <output> <width> <height>
    if (argc >= 2) input_path = argv[1];
    if (argc >= 3) output_path = argv[2];
    if (argc >= 4) width = atoi(argv[3]);
    if (argc >= 5) height = atoi(argv[4]);

    printf("Processing: %s -> %s [%dx%d]\n", input_path, output_path, width, height);

    // 1. 读取 NV12
    size_t data_size = width * height * 3 / 2;
    std::vector<uchar> nv12_data(data_size);

    std::ifstream file(input_path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open input file!" << std::endl;
        return -1;
    }
    
    // 检查文件大小是否匹配分辨率
    file.seekg(0, std::ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    if (file_size != data_size) {
        printf("⚠️ 警告: 文件大小(%zu)与分辨率预期(%zu)不符！这会导致绿屏或花屏。\n", file_size, data_size);
        // 强制继续，但结果可能不对
    }

    file.read((char*)nv12_data.data(), data_size);
    file.close();

    // 2. 转换 (NV12 -> BGR)
    cv::Mat src(height * 3 / 2, width, CV_8UC1, nv12_data.data());
    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_YUV2BGR_NV12);

    // 3. 保存 JPG
    if (cv::imwrite(output_path, dst)) {
        std::cout << "转换成功: " << output_path << std::endl;
    } else {
        std::cerr << "Error: Failed to save JPG!" << std::endl;
        return -1;
    }

    return 0;
}