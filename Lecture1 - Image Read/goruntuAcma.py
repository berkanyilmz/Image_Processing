import cv2 as cv

def openImage():
    img = cv.imread("code.jpg")
    cv.namedWindow("Kod")
    cv.imshow("Kod", img)
    cv.waitKey(0)
    cv.destroyWindow("Kod")


def Main():
    openImage()


if __name__ == '__main__':
    Main()
