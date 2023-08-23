import cv2

def nothing(x):
    pass

def renkFiltreleme():
    img = cv2.imread("colorful.jpg")

    cv2.namedWindow("Ayar", flags=cv2.WINDOW_AUTOSIZE)

    cv2.createTrackbar("Kirmizi Min", "Ayar", 0, 255, nothing)
    cv2.createTrackbar("Yesil Min", "Ayar", 0, 255, nothing)
    cv2.createTrackbar("Mavi Min", "Ayar", 0, 255, nothing)

    cv2.createTrackbar("Kirmizi Max", "Ayar", 255, 255, nothing)
    cv2.createTrackbar("Yesil Max", "Ayar", 255, 255, nothing)
    cv2.createTrackbar("Mavi Max", "Ayar", 255, 255, nothing)

    rgbimg = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    cv2.imshow("rgb", rgbimg)
    while True:
        kirmiziMin = cv2.getTrackbarPos("Kirmizi Min", "Ayar")
        yesilMin = cv2.getTrackbarPos("Yesil Min", "Ayar")
        maviMin = cv2.getTrackbarPos("Mavi Min", "Ayar")

        kirmiziMax = cv2.getTrackbarPos("Kirmizi Max", "Ayar")
        yesilMax = cv2.getTrackbarPos("Yesil Max", "Ayar")
        maviMax = cv2.getTrackbarPos("Yesil Max", "Ayar")

        cimg = cv2.inRange(rgbimg, (maviMin, yesilMin, kirmiziMin), (maviMax, yesilMax, kirmiziMax))
        cv2.imshow("Balon", cimg)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()

def videoRenkFiltreleme():
    cap = cv2.VideoCapture(0)

    cv2.namedWindow("Ayar", flags=cv2.WINDOW_AUTOSIZE)
    cv2.createTrackbar("Kirmizi Min", "Ayar", 0, 255, nothing)
    cv2.createTrackbar("Yesil Min", "Ayar", 0, 255, nothing)
    cv2.createTrackbar("Mavi Min", "Ayar", 0, 255, nothing)

    cv2.createTrackbar("Kirmizi Max", "Ayar", 255, 255, nothing)
    cv2.createTrackbar("Yesil Max", "Ayar", 255, 255, nothing)
    cv2.createTrackbar("Mavi Max", "Ayar", 255, 255, nothing)

    while True:
        ret, frame = cap.read()
        kirmiziMin = cv2.getTrackbarPos("Kirmizi Min", "Ayar")
        yesilMin = cv2.getTrackbarPos("Yesil Min", "Ayar")
        maviMin = cv2.getTrackbarPos("Mavi Min", "Ayar")

        kirmiziMax = cv2.getTrackbarPos("Kirmizi Max", "Ayar")
        yesilMax = cv2.getTrackbarPos("Yesil Max", "Ayar")
        maviMax = cv2.getTrackbarPos("Yesil Max", "Ayar")

        hsvframe = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        maske = cv2.inRange(hsvframe, (maviMin, yesilMin, kirmiziMin), (maviMax, yesilMax, kirmiziMax))
        output = cv2.bitwise_and(frame, frame, mask = maske)
        cv2.imshow("Kamera", frame)
        cv2.imshow("Filtre", output)

        if cv2.waitKey(10) == 27:
            break

    cv2.destroyAllWindows()

if __name__ == '__main__':
    videoRenkFiltreleme()