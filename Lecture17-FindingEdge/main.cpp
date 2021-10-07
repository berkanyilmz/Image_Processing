#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

void sobelFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/sudoku.png", IMREAD_GRAYSCALE);
    Mat blackwhite, sobelX, sobelY;
    threshold(img, blackwhite, 120, 255, THRESH_BINARY);

    Sobel(blackwhite, sobelX, -1, 1, 0, 5);
    Sobel(blackwhite, sobelY, -1, 0, 1, 5);
    namedWindow("SobelX", WINDOW_AUTOSIZE);
    namedWindow("SobelY", WINDOW_AUTOSIZE);

    imshow("SobelX", sobelX);
    imshow("SobelY", sobelY);

    imwrite("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/SobelX.jpg", sobelX);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/SobelY.jpg", sobelY);

    waitKey(0);
    destroyAllWindows();
}

void laplacianFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/sudoku.png", IMREAD_GRAYSCALE);
    Mat blackWhite, laplacian;
    threshold(img, blackWhite, 120, 255, THRESH_BINARY);
    imshow("blackwhite", blackWhite);

    Laplacian(blackWhite, laplacian, -1, 3);
    namedWindow("Laplacian", WINDOW_AUTOSIZE);

    imshow("Laplacian", laplacian);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/Laplacian.jpg", laplacian);
    waitKey(0);
    destroyWindow("Laplacian");
}

void scharrFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/sudoku.png", IMREAD_GRAYSCALE);
    Mat blackwhite, scharr;
    threshold(img, blackwhite, 120, 255, THRESH_BINARY);

    Scharr(img, scharr, -1, 0, 1);
    imshow("Scharr", scharr);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/Scharr.jpg", scharr);

    waitKey(0);
    destroyWindow("Scharr");
}

void cannyFilter()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/sudoku.png", IMREAD_GRAYSCALE);
    Mat blackwhite, canny;
    threshold(img, blackwhite, 120, 255, THRESH_BINARY);

    Canny(blackwhite, canny, 0, 255);

    imshow("Canny", canny);
    imwrite("/home/berkan/CLionProjects/OpenCV/Ders17_KenarBulma/Scharr.jpg", canny);

    waitKey(0);
    destroyWindow("Canny");
}

int main() {
    //sobelFilter();
    //laplacianFilter();
    //scharrFilter();
    cannyFilter();
    return 0;
}
