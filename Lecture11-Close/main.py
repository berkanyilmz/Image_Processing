import cv2
import numpy as np

def nothing():
    pass

def close():
    img = cv2.imread("cumle.jpg", cv2.IMREAD_GRAYSCALE)
    cv2.namedWindow("Close Image", cv2.WINDOW_AUTOSIZE)
    cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)
    filtre = np.ones((3,3))
    cv2.createTrackbar("Close", "Close Image", 0, 15, nothing)

    while True:
        iteration = cv2.getTrackbarPos("Close", "Close Image")

        erodeImg = cv2.erode(cv2.dilate(img, filtre, dst=(-1,-1), iterations=iteration), filtre, dst=(-1,-1), iterations=iteration)

        cv2.imshow("Close Image", erodeImg)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()


if __name__ == '__main__':
    close()