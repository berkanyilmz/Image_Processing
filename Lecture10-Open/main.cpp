#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void open()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders10_Open/word.jpg", IMREAD_GRAYSCALE);
    namedWindow("Open", WINDOW_AUTOSIZE);

    Mat filter, openImg, eroImg;
    filter = Mat::ones(Size(3,3), img.type());

    int min = 0;
    createTrackbar("Open", "Open", &min, 5);

    while (true)
    {
        erode(img, eroImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        dilate(eroImg, openImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        imshow("Open", openImg);

        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyWindow("Open");
}

int main() {
    open();
    return 0;
}
