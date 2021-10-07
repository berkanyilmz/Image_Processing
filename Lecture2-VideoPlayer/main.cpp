#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void VideoRead()
{
    VideoCapture vCap;
    vCap.open("/home/berkan/CLionProjects/OpenCV/Ders2-VideoOkuma/suspus.mp4");

    if (vCap.isOpened())
    {
        double fps = vCap.get(CAP_PROP_FPS);
        Mat frame;
        namedWindow("Video");

        while (true)
        {
            if (!vCap.read(frame)) {break;}
            imshow("Video", frame);

            if (waitKey(1000/fps) >= 0) {break;}
        }
        vCap.release();
        destroyAllWindows();
    }
    else
    {
        cout << "Video is not opened" << endl;
    }
}

int main()
{
    VideoRead();
    return 0;
}
