import cv2
import numpy as np

def nothing():
    pass

def top_hat():
    img = cv2.imread("cumle.jpg", cv2.IMREAD_GRAYSCALE)
    cv2.namedWindow("Top Hat", cv2.WINDOW_AUTOSIZE)
    cv2.createTrackbar("TopHat", "Top Hat", 0, 15, nothing)
    cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)
    filtre = np.ones((3,3))

    while True:
        iteration = cv2.getTrackbarPos("TopHat", "Top Hat")
        erodeImg = cv2.erode(img, filtre, dst=(-1,-1), iterations=iteration)
        dilationImg = cv2.dilate(erodeImg, filtre, dst = (-1,-1), iterations=iteration)

        topHatImg = img - dilationImg
        cv2.imshow("Top Hat", topHatImg)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()


if __name__ == '__main__':
    top_hat()