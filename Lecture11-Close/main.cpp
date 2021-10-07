#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void close()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders11_Close/word.jpg", IMREAD_GRAYSCALE);
    Mat filter, dilateImg, close;
    filter = Mat::ones(Size(3, 3), img.type());

    namedWindow("Close");
    int min = 0;
    createTrackbar("Close", "Close", &min, 5);

    while (true)
    {
        dilate(img, dilateImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        erode(dilateImg, close, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        imshow("Close", dilateImg);

        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyWindow("Close");
}

int main() {
    close();
    return 0;
}
