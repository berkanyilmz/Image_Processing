#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void gradient()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders12_Gradient/word.jpg", IMREAD_GRAYSCALE);
    Mat filter, erodeImg, dilateImg, gradientImg;
    namedWindow("Gradient");
    threshold(img, img, 128, 255, THRESH_BINARY);
    filter = Mat::ones(Size(3, 3), img.type());

    int min = 0;
    createTrackbar("gradient", "Gradient", &min, 10);

    while (true)
    {
        erode(img, erodeImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        dilate(img, dilateImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        gradientImg = dilateImg - erodeImg;
        imshow("Gradient", gradientImg);

        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyWindow("Gradient");
}

int main() {
    gradient();
    return 0;
}
