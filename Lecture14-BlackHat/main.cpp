#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void blackHat()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders14_BlackHat/word.jpg", IMREAD_GRAYSCALE);
    namedWindow("Black Hat", WINDOW_AUTOSIZE);
    threshold(img, img, 128, 255, THRESH_BINARY);

    int min = 0;
    createTrackbar("Black Hat", "Black Hat", &min, 30);

    Mat filter, erodeImg, dilateImg, blackHatImg;
    filter = Mat::ones(Size(3, 3), img.type());

    while (true)
    {
        dilate(img, dilateImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        erode(dilateImg, erodeImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        blackHatImg = erodeImg - img;
        imshow("Black Hat", blackHatImg);

        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyWindow("Black Hat");
}
int main() {
    blackHat();
    return 0;
}
