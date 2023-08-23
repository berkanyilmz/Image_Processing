import cv2
import numpy as np

def matrixOperations():
    winName = "Matrix Operations"
    image = np.zeros((500, 500, 3), dtype="uint8")
    image = cv2.randu(image, (0, 0, 0), (255, 255, 255))
    cv2.imshow(winName, image)
    cv2.waitKey(0)




if __name__ == '__main__':
    matrixOperations()