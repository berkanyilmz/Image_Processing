#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void filter2d()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders15_Filtreleme/castle.jpg", IMREAD_GRAYSCALE);
    threshold(img, img, 128, 255, THRESH_BINARY);
    imshow("Original", img);

    float data[] = {1, 1, 1,
                    1, -7, 1,
                    1, 1, 1};
    Mat kernel(3, 3, CV_32F, data);
    filter2D(img, img, -1, kernel);
    imshow("Castle", img);
    waitKey(0);
    destroyAllWindows();
}

void sepFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders15_Filtreleme/castle.jpg", IMREAD_GRAYSCALE);
    threshold(img, img, 128, 255, THRESH_BINARY);
    imshow("Original", img);

    float dataX[] = {-1, -2, 6, -2, -1};
    float dataY[] = {0, 0, 1, 0, 0};
    Mat kernelX(1, 5, CV_32F, dataX);
    Mat kernelY(5, 1, CV_32F, dataY);
    sepFilter2D(img, img, -1, kernelX, kernelY);
    imshow("Sep Filter", img);
    waitKey(0);
}

void findEdge()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders15_Filtreleme/castle.jpg", IMREAD_GRAYSCALE);
    threshold(img, img, 128, 255, THRESH_BINARY);
    imshow("Original", img);

    float data[] = {1, 1, 1,
                    1, 8, 1,
                    1, 1, 1};
    Mat kernel(3, 3, CV_32F, data);
    filter2D(img, img, -1, kernel);
    imshow("Finding Edge", img);
    waitKey(0);
}

int main() {
    //filter2d();
    //sepFilter();
    findEdge();
    return 0;
}
