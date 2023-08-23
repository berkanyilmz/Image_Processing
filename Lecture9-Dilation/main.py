import cv2
import numpy as np

def nothing():
    pass

def dilation():
    img = cv2.imread("cumle.jpg", cv2.IMREAD_GRAYSCALE)
    cv2.namedWindow("Dilation Image", cv2.WINDOW_AUTOSIZE)
    thresh = cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)
    filtre = np.ones((3,3))

    cv2.createTrackbar("Dilation", "Dilation Image", 0, 15, nothing)

    while True:
        dilationValue = cv2.getTrackbarPos("Dilation", "Dilation Image")
        dilationImg = cv2.dilate(img, filtre, iterations=dilationValue)
        cv2.imshow("Dilation Image", dilationImg)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()

if __name__ == '__main__':
    dilation()