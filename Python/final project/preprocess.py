import cv2
import numpy as np

def preprocess_image(img):
    """将图像灰度化并进行边缘检测"""
    # 检查图像是否为空
    if img is None:
        raise ValueError("Error: Image not loaded correctly.")
    
    # 检查图像是否为彩色图像
    if len(img.shape) == 3:
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    else:
        gray = img  # 如果已经是灰度图像，则直接使用

    # 进行边缘检测
    edges = cv2.Sobel(gray, cv2.CV_64F, 1, 0, ksize=3)
    return edges
