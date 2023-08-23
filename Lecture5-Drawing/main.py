import math

import cv2
import numpy as np

def cizim():
    img = cv2.imread("light.jpg")

    cv2.line(img, (0, 0), (30, 100), (0,255,0), 5)
    cv2.circle(img, (10, 80), 10, (255,255,255), 3)
    cv2.rectangle(img, (300, 400), (500, 550), (240,22,128), 4)

    cv2.imshow("Cizim", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == '__main__':
    cizim()