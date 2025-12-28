import os

# ================= 配置区域 =================
# 你的图片文件夹路径 (建议填相对路径，脚本会自动转绝对路径)
IMAGE_DIR = './dataset/calibration_data' 

# 输出的 txt 文件名
OUTPUT_TXT = './dataset/dataset.txt'
# ===========================================

def generate_txt():
    # 支持的图片格式
    valid_exts = ['.jpg', '.jpeg', '.png', '.bmp']
    images = []
    
    # 获取图片文件夹的绝对路径 (RKNN 对绝对路径支持最好)
    abs_img_dir = os.path.abspath(IMAGE_DIR)
    
    if not os.path.exists(abs_img_dir):
        print(f"❌ 错误：找不到文件夹 {abs_img_dir}")
        return

    print(f"📂 正在扫描目录: {abs_img_dir} ...")

    # 遍历目录及其所有子目录
    for root, dirs, files in os.walk(abs_img_dir):
        for file in files:
            ext = os.path.splitext(file)[1].lower()
            if ext in valid_exts:
                # 组合完整路径
                full_path = os.path.join(root, file)
                images.append(full_path)
    
    # 写入 txt 文件
    if images:
        with open(OUTPUT_TXT, 'w') as f:
            for img_path in images:
                f.write(img_path + '\n')
        print(f"✅ 成功生成: {OUTPUT_TXT}")
        print(f"📊 共包含 {len(images)} 张图片 (所有图片已全选)")
    else:
        print("⚠️ 警告：该目录下没有找到任何图片文件！")

if __name__ == '__main__':
    generate_txt()