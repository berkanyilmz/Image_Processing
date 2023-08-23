import cv2
import numpy as np

def nesneSay():
    img = cv2.imread("kahve.jpg", cv2.IMREAD_GRAYSCALE)
    cv2.namedWindow("Nesne Sayma", cv2.WINDOW_AUTOSIZE)
    cv2.threshold(img, 120, 255, cv2.THRESH_BINARY)
    cv2.imshow("Orijinal", img)

    contours, hierarchy = cv2.findContours(img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    width, height = img.shape[:2]
    filtre = np.zeros((width, height), np.float32)

    for i in range(len(contours)):
        image = cv2.drawContours(filtre, contours, i, (255, 0, 0), 2, cv2.LINE_8, hierarchy, 0)
        rRect = cv2.minAreaRect(contours[i])
        image = cv2.putText(image, str((i+1)), (1, 0), 1, 1, (27, 12, 255))


    cv2.imshow("Nesne Sayma", image)

    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == '__main__':
    nesneSay()
