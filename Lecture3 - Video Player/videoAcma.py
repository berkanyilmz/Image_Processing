import cv2 as cv

def videoPlayer():
    video = cv.VideoCapture("suspus.mp4")

    while (True):
        ret, frame = video.read()
        cv.imshow("Ceza", frame)
        if cv.waitKey(10) == 27:
            break

    video.release()
    cv.destroyAllWindows()


def Main():
    videoPlayer()

if __name__ == '__main__':
    Main()
