#ifndef TRAITEMENT
#define TRAITEMENT


#include <iostream>
#include <algorithm>
#include <vector>

#include <QApplication>
#include <QImage>
#include <QtGui>
#include <QLayout>

#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>




void detectCircles(QImage *qim, QVector <int> *divisionPoints);
bool isValable(int minX, int minY, int maX, int maxY, cv::Mat mat);


cv::Mat QImageToCvMat(QImage const& src);


#endif
