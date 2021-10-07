#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void erosion()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders8_Erozyon/word.jpg", IMREAD_GRAYSCALE);
    namedWindow("Erosion", WINDOW_AUTOSIZE);
    threshold(img, img, 128, 255, THRESH_BINARY);

    int min = 0;
    createTrackbar("Erosion", "Erosion", &min, 5);

    Mat filter, erosionImg;
    filter = Mat::ones(Size(3,3), img.type());

    while (true)
    {
        erode(img, erosionImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        imshow("Erosion", erosionImg);
        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyAllWindows();
}

int main() {
    erosion();
    return 0;
}
