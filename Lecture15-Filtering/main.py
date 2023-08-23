import cv2
import numpy as np

img = cv2.imread("Kale.jpg", cv2.IMREAD_GRAYSCALE)
cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)
cv2.imshow("Orijinal", img)

def filter2D():
    kernel = np.array([[1,1,1],
                      [1,-7,1],
                      [1,1,1]], np.float32)
    filterImg = cv2.filter2D(img, cv2.CV_32F, kernel=kernel)
    cv2.imshow("2D Filter", filterImg)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


def kenarBulma():
    kernel = np.array([[1,1,1],
                      [1,8,1],
                      [1,1,1]], np.float32)
    filterImg = cv2.filter2D(img, cv2.CV_32F, kernel)
    cv2.imshow("Kenar Bulma", filterImg)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def sepFilter():
     dataX = [-1, -2, 6, -2, -1]
     dataY = [0, 0, 1, 0, 0]

     kernelX = np.array((1, 5), cv2.CV_32F, dataX)
     kernelY = np.array((5, 1), cv2.CV_32F, dataY)

     cv2.sepFilter2D(img, -1, kernelX, kernelY)

     cv2.imshow("Sep Filter", img)

     cv2.waitKey(0)
     cv2.destroyAllWindows()

if __name__ == '__main__':
    kenarBulma()
    cv2.waitKey(0)
    cv2.destroyAllWindows()