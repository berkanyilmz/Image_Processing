import cv2 as cv

def webcamPlayer():
    camera = cv.VideoCapture(0)

    while (True):
        ret, frame = camera.read()
        cv.imshow("Camera", frame)
        if cv.waitKey(10) == 27:
            break

    camera.release()
    cv.destroyAllWindows()


def Main():
    webcamPlayer()

if __name__ == '__main__':
    Main()
