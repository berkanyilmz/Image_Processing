#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void dilation()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders9_Dilation/word.jpg", IMREAD_GRAYSCALE);
    namedWindow("Dilation", WINDOW_AUTOSIZE);
    threshold(img, img, 128, 255, THRESH_BINARY);

    Mat filter, dilationImg;
    filter = Mat::ones(Size(3, 3), img.type());

    int min = 0;
    createTrackbar("Dilation", "Dilation", &min, 5);

    while (true)
    {
        dilate(img, dilationImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        imshow("Dilation", dilationImg);
        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyAllWindows();
}

int main() {
    dilation();
    return 0;
}
