#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void colorFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders7_RenkFiltreleme/uzay.jpg");
    Mat cImg, mask;
    int blueMin = 0, greenMin = 0, redMin = 0,
        blueMax = 255, redMax = 255, greenMax = 255;
    namedWindow("Settings");
    createTrackbar("BlueMin", "Settings", &blueMin, 255);
    createTrackbar("GreenMin", "Settings", &greenMin, 255);
    createTrackbar("RedMin", "Settings", &redMin, 255);

    createTrackbar("BlueMax", "Settings", &blueMax, 255);
    createTrackbar("GreenMax", "Settings", &greenMax, 255);
    createTrackbar("RedMax", "Settings", &redMax, 255);
    imshow("Original", img);

    img.copyTo(cImg);

    while (true)
    {
        cvtColor(img, cImg, COLOR_BGR2RGB);
        inRange(cImg, Scalar(blueMin, greenMin, redMin), Scalar(blueMax, greenMax, redMax), mask);
        imshow("Mask", mask);
        if (waitKey(10) == 27)
        {
            break;
        }
    }
    destroyAllWindows();
}

void masking()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders7_RenkFiltreleme/uzay.jpg");
    Mat maskImg, outImg;
    cvtColor(img, maskImg, COLOR_BGR2RGB);
    namedWindow("Masking");
    imshow("Masking", maskImg);

    outImg = img + maskImg;
    imshow("OR", outImg);
    waitKey(0);
    destroyAllWindows();
}

int main() {
    //colorFilter();
    masking();
    return 0;
}
