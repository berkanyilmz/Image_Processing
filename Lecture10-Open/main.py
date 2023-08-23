import cv2
import numpy as np

def nothing():
    pass

def open():
    img = cv2.imread("cumle.jpg", cv2.IMREAD_GRAYSCALE)
    cv2.namedWindow("Open Image", cv2.WINDOW_AUTOSIZE)
    cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)
    cv2.createTrackbar("Open", "Open Image", 0, 15, nothing)

    filtre = np.ones((3,3))

    while True:
        openValue = cv2.getTrackbarPos("Open", "Open Image")

        erodeImg = cv2.erode(img, filtre,dst=(-1,-1), iterations=openValue)
        dilationImg = cv2.dilate(erodeImg, filtre, iterations=openValue)

        cv2.imshow("Open Image", dilationImg)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()

if __name__ == '__main__':
    open()