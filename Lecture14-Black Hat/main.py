import cv2
import numpy as np

def nothing():
    pass

def close(image, filter, iteration):
    return cv2.erode(cv2.dilate(image, filter, dst=(-1,-1), iterations=iteration), filter, dst=(-1,-1), iterations=iteration)

def blackHat():
    img = cv2.imread("cumle.jpg", flags=cv2.IMREAD_GRAYSCALE)
    cv2.threshold(img, 128, 255, type=cv2.THRESH_BINARY)

    cv2.namedWindow("Black Hat", cv2.WINDOW_AUTOSIZE)
    cv2.createTrackbar("BlackHat", "Black Hat", 0, 20, nothing)
    filter = np.ones((3,3))

    while True:
        iteration = cv2.getTrackbarPos("BlackHat", "Black Hat")

        blackHatImage = close(img, filter, iteration) - img
        cv2.imshow("Black Hat", blackHatImage)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyWindow("Black Hat")


if __name__ == '__main__':
    blackHat()