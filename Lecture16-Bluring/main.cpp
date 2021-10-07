#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void blur() {
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/kask.jpg");
    Mat blr;
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Blur", WINDOW_AUTOSIZE);

    blur(img, blr, Size(8, 9));
    imshow("Original", img);
    imshow("Blur", blr);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/blur.jpg", blr);
    waitKey(0);
    destroyAllWindows();
}

void gaussianBlur()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/kask.jpg");
    Mat blr;
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Gaussian Blur", WINDOW_AUTOSIZE);

    GaussianBlur(img, blr, Size(11, 11), 3, 3);
    imshow("Original", img);
    imshow("Gaussian Blur", blr);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/Gaussian blur.jpg", blr);

    waitKey(0);
    destroyAllWindows();
}

void BoxFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/kask.jpg");
    Mat blr;
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Box Filter", WINDOW_AUTOSIZE);

    boxFilter(img, blr, -1, Size(7, 7));
    imshow("Original", img);
    imshow("Box Filter", blr);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/Box Filter.jpg", blr);

    waitKey(0);
    destroyAllWindows();
}

void MedianBlur()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/kask.jpg");
    Mat blr;
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Median Blur", WINDOW_AUTOSIZE);

    medianBlur(img, blr, 9);
    imshow("Original", img);
    imshow("Median Blur", blr);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/Median Blur.jpg", blr);

    waitKey(0);
    destroyAllWindows();
}

void bilateralFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders16_Bulaniklastirma/kask.jpg");
    Mat blr;
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Bilateral filter", WINDOW_AUTOSIZE);

    bilateralFilter(img, blr, -1, 50, 9);
    imshow("Original", img);
    imshow("Bilateral filter", blr);

    waitKey(0);
    destroyAllWindows();
}

int main() {
    //blur();
    //gaussianBlur();
    //BoxFilter();
    //MedianBlur();
    //bilateralFilter();
    return 0;
}
