#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void topHat()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Lecture13-Tophat/word.jpg", IMREAD_GRAYSCALE);
    namedWindow("Top Hat", WINDOW_AUTOSIZE);
    threshold(img, img, 128, 255, THRESH_BINARY);

    int min = 0;
    createTrackbar("TopHat", "Top Hat", &min, 10);

    Mat filter, dilateImg, erosionImg, tophatImg;
    filter = Mat::ones(Size(3, 3), img.type());

    while (true)
    {
        erode(img, erosionImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        dilate(erosionImg, dilateImg, filter, Point(-1, -1), min, 0, Scalar(255, 255, 255));
        tophatImg = img - dilateImg;
        imshow("Top Hat", tophatImg);

        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyAllWindows();
}

int main() {
    topHat();
    return 0;
}
