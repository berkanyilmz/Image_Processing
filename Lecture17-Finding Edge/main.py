import cv2

def sobelFiltre():
    img = cv2.imread("sudoku.png", cv2.IMREAD_GRAYSCALE)
    cv2.threshold(img, 120,255, cv2.THRESH_BINARY)

    sobelX = cv2.Sobel(img, -1, 1, 0, ksize=5)
    sobelY = cv2.Sobel(img, -1, 0, 1, ksize=5)

    cv2.namedWindow("SobelX", cv2.WINDOW_AUTOSIZE)
    cv2.namedWindow("SobelY", cv2.WINDOW_AUTOSIZE)

    cv2.imshow("SobelX", sobelX)
    cv2.imshow("SobelY", sobelY)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == '__main__':
    sobelFiltre()


