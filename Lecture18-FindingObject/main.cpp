#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void contoursDetection()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders18_BilgiCikarma/coffee.jpg", IMREAD_GRAYSCALE);
    threshold(img, img, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);
    namedWindow("Contours Detection", WINDOW_AUTOSIZE);
    imshow("Contours Detection", img);
    waitKey(0);

    vector<vector<Point>> contours;
    vector<Point> contPoly;
    vector<Vec4i> hierarchy;

    findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
    cout << "Number of Coffees : " << contours.size() << endl;
    waitKey(0);
    Mat outImg = Mat::zeros(img.size(), CV_8UC3);
    RotatedRect rRect;


    for (int i = 0; i < contours.size(); i++)
    {
        drawContours(outImg, contours, i, Scalar(255, 0, 0),
                     FILLED, 8, hierarchy, 0, Point());
        rRect = minAreaRect(contours[i]);
        putText(outImg, format("%d", i + 1), rRect.center, 1, 1, Scalar(0, 0, 255));
    }

    imshow("Contours Detection", outImg);
    waitKey(0);
    destroyWindow("Contours Detection");
}

int main() {
    contoursDetection();
    return 0;
}
