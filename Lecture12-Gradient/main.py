import cv2
import numpy as np

def nothing():
    pass

def gradient():
    img = cv2.imread("cumle.jpg", cv2.IMREAD_GRAYSCALE)
    cv2.namedWindow("Gradient", cv2.WINDOW_AUTOSIZE)
    cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)
    cv2.createTrackbar("Gradient", "Gradient", 0, 15, nothing)
    filtre = np.ones((3,3))

    while True:
        iteration = cv2.getTrackbarPos("Gradient", "Gradient")

        dil = cv2.dilate(img, filtre, dst = (-1,-1), iterations=iteration)
        ero = cv2.erode(img, filtre, dst = (-1,-1), iterations=iteration)

        gradient = dil - ero

        cv2.imshow("Gradient", gradient)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()


if __name__ == '__main__':
    gradient()