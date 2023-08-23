import cv2 as cv

img = cv.imread("fire.jpg")
cv.namedWindow("Orijinal", cv.WINDOW_AUTOSIZE)
cv.imshow("Orijinal", img)

def blur():
    cv.namedWindow("Blur", cv.WINDOW_AUTOSIZE)
    blurImage = cv.blur(img, (3,3))
    cv.imshow("Blur", blurImage)
    cv.imwrite("FireBlur.jpg", blurImage)


def gaussianBlur():
    cv.namedWindow("Gaussian Blur", cv.WINDOW_AUTOSIZE)
    gaussianImg = cv.GaussianBlur(img, (5,5), 0)
    cv.imshow("Gaussian Blur", gaussianImg)
    cv.imwrite("FireGaussianBlur.jpg", gaussianImg)

def BoxFilter():
    cv.namedWindow("Box Filter", cv.WINDOW_AUTOSIZE)
    boxImg = cv.boxFilter(img, -1, (5,5))
    cv.imshow("Box Filter", boxImg)
    cv.imwrite("BoxFilterImg.jpg", boxImg)

def medianBlur():
    cv.namedWindow("Median Blur", cv.WINDOW_AUTOSIZE)
    medianImg = cv.medianBlur(img, 5)
    cv.imshow("Median Blur", medianImg)
    cv.imwrite("MedianImg.jpg", medianImg)

def BilateralFiltre():
    cv.namedWindow("Bilateral Filtre", cv.WINDOW_AUTOSIZE)
    bilateralImg = cv.bilateralFilter(img, 9, 75, 75)
    cv.imshow("Bilateral Filtre", bilateralImg)
    cv.imwrite("BilateralImg.jpg", bilateralImg)

if __name__ == '__main__':
    BilateralFiltre()
    cv.waitKey(0)
    cv.destroyAllWindows()