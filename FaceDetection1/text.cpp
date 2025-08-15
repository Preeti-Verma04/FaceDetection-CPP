#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/*int main() {
    string path = "C:/Users/LENOVO/Downloads/preeti.jpg";

    // Try to load image
    Mat img = imread(path);

    if (img.empty()) {
        cout << "❌ Could not load image. Make sure it exists in the program's working directory." << endl;
        return 1;
    }

    cout << "✅ Image loaded successfully!" << img.cols << " x " << img.rows << endl;

    Mat imgResized;
    resize(img, imgResized, Size(), 0.5, 0.5);
    imshow("Frame-Resized", imgResized);
    waitKey(0);
    return 0;
}*/

int  main() {
    VideoCapture video(0);
    if (!video.isOpened()) {
        cout << "❌ Could not open camera" << endl;
        return 1;
    }
    CascadeClassifier facedetect;
    if (!facedetect.load("C:/Users/LENOVO/source/repos/FaceDetection1/FaceDetection1/x64/Debug/haarcascade_frontalface_default.xml")) {
        cout << "❌ Could not load haarcascade xml file" << endl;
        return 1;
    }

    cout << "✅ Camera and XML file loaded successfully!" << endl;

    Mat img;

    

    
    while (true) {
        video.read(img);
        if (img.empty()) break;
        vector<Rect>faces;
        
        facedetect.detectMultiScale(img, faces, 1.1, 3);

        cout << faces.size() << endl;

        for (auto& face : faces) {
            rectangle(img, face.tl(), face.br(), Scalar(50, 50, 255), 3);
            rectangle(img, Point(0,0), Point(250,70), Scalar(50, 50, 255), FILLED);
            putText(img, to_string(faces.size())+"FACE FOUND", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
        }
        imshow("Frame", img);
        waitKey(1);
    }
    return 0;
}