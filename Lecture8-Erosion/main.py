import cv2
import numpy as np

def nothing():
    pass

def erozyon():
    img = cv2.imread("cumle.jpg", cv2.IMREAD_GRAYSCALE)
    cv2.namedWindow("Erozyon", cv2.WINDOW_AUTOSIZE)
    thres = cv2.threshold(img, 128 ,255, cv2.THRESH_BINARY)

    filtre = np.ones((3,3)) #3 satır 3 sütundan oluşan 1ler matrisi

    cv2.createTrackbar("Asindir", "Erozyon", 0, 15, nothing)

    while True:
        asindirmaDegeri = cv2.getTrackbarPos("Asindir", "Erozyon")
        erodeImg = cv2.erode(img, filtre, iterations=asindirmaDegeri)
        cv2.imshow("Erozyon", erodeImg)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()

if __name__ == '__main__':
    erozyon()