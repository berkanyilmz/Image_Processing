#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void WebCamPlayer()
{
    string wName = "webcam";
    VideoCapture vCap(-1);

    if (vCap.isOpened()) {
        double fps = vCap.get(CAP_PROP_FPS);
        if (fps < 1) {
            fps = 23;
        }
        Mat frame;
        namedWindow(wName);

        while (true)
        {
            if (vCap.read(frame))
            {
                imshow(wName, frame);
            }
            if (waitKey(1000/fps) >= 0)
            {
                break;
            }
        }
        vCap.release();
        destroyWindow(wName);
    }
    else
    {
        cout << "Camera is not opened" << endl;
    }
}

int main() {
    WebCamPlayer();
    return 0;
}
