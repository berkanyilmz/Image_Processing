import cv2
import numpy as np

def renkFiltreleme():
    img = cv2.imread("galaksi.jpg")
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    lower = np.array([95,0,0])
    upper = np.array([255,255,255])

    maske = cv2.inRange(hsv, lower, upper)
    filt = cv2.bitwise_and(img, img, mask = maske)

    cv2.imshow("Maske", maske)
    cv2.imshow("Orijinal", img)
    cv2.imshow("Filtreli", filt)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

def videoRenkFiltre():
    cap = cv2.VideoCapture(0)


    while True:
        ret, frame = cap.read()
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        lower_blue = np.array([30, 100, 100])
        upper_blue = np.array([150, 240, 240])
        maske = cv2.inRange(hsv, lower_blue, upper_blue)
        cikti = cv2.bitwise_and(frame, frame, mask = maske)
        cv2.imshow("Kamera", frame)
        cv2.imshow("Filtre", cikti)
        cv2.imshow("Maske", maske)

        if cv2.waitKey(20) & 0xFF == 27:
            break

    cv2.destroyAllWindows()


if __name__ == '__main__':
    videoRenkFiltre()