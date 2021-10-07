#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void drawing()
{
    string wName = "Draw";
    Mat bImg = imread("/home/berkan/CLionProjects/OpenCV/Ders5-CizimIslemleri/okyanus.jpg");
    Mat tImg = bImg.clone();
    int nCols = bImg.cols;
    int nRows = bImg.rows;
    tImg.copyTo(bImg);

    for (int i = 0; i <= 360; i++) {
        line(tImg, Point(nCols/2, nRows/2),
             Point(nCols/2+120* sin(i*M_PI/180),
                   nRows/2+120* cos(i*M_PI/180)),
                   Scalar(0,0,255), 3);
        putText(tImg, wName, Point(10+i, 10+i),
                FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 2,
                Scalar(255, 0, 0), 3);
        circle(tImg, Point(nCols - 1.3*i, 400), 15,
               Scalar(0, 255, 255), -1);
        rectangle(tImg, Rect(0+1.3*i, 380-0.9*i, 40, 40),
                  Scalar(255,255,0), 8);
        imshow(wName, tImg);
        waitKey(30);
        bImg.copyTo(tImg);
    }
    waitKey(0);
    destroyAllWindows();
}

int main() {
    drawing();
    return 0;
}
