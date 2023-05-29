#include <opencv2/aruco.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
    cv::Mat img = cv::imread("/home/darleet/BMSTU/IU9-PLaM/Dz1_2/example.jpg");
    cv::aruco::Dictionary dict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

    std::vector<std::vector<cv::Point2f>> markerCorners;
    std::vector<int> markerIds;
    cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
    cv::aruco::ArucoDetector detector(dict, detectorParams);
    detector.detectMarkers(img, markerCorners, markerIds);

    if (!markerIds.empty()) {
        cv::aruco::drawDetectedMarkers(img, markerCorners, markerIds);

        std::cout << "{" << std::endl;
        for (int i = 0; i < markerCorners.size(); i++) {
            std::cout << "  \"id" << markerIds[i] << "\": [" << std::endl;

            for (int j = 0; j < markerCorners[i].size(); j++) {
                cv::Point2f point = markerCorners[i][j];
                std::cout << "    {\n      \"x\": " << point.x << "," << std::endl;
                std::cout << "      \"y\": " << point.y << "\n    }";
                if (j != markerCorners[i].size() - 1) {
                    std::cout << ",";
                }
                std::cout << std::endl;
            }

            std::cout << "  ]";
            if (i != markerCorners.size() - 1) {
                std::cout << ",";
            }
            std::cout << std::endl;
        }
        std::cout << "}" << std::endl;

    }

    cv::namedWindow("Output", cv::WindowFlags::WINDOW_AUTOSIZE);

    cv::imshow("Output", img);
    cv::waitKey(0);
};