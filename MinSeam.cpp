/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include "MinSeam.h"
#include <iostream>
using namespace cv;
using namespace std;

MinSeam::MinSeam(const cv::Mat & background, const cv::Mat & foreground, const cv::Mat & mask) :
    _background(background),
    _foreground(foreground),
    _mask(mask) 
{
    Mat_<Vec3f> bgf, fgf;
    background.convertTo(bgf, CV_32FC3);
    foreground.convertTo(fgf, CV_32FC3);

    pow((bgf - fgf), 2, _energy);
    vector<Mat> channels;
    split(_energy, channels);
    _energy = channels[0] + channels[1] + channels[2];
}

MinSeam::~MinSeam() {
}

Mat MinSeam::getEnergy() const {
    return _energy;
}

void MinSeam::computeEnergyCumMaps() {
    Point steam0(895, 708);
    Point steam1(895, 739);
    
    cv::Mat_<double> eCum(_energy.rows, _energy.cols, CV_32FC1);
    for (int i = steam0.y; i < steam1.y; i++) {
        Point steamStart(steam0.x, i);
        eCum.at<double>(steamStart) = -1.0f;

        eCum = neighbouroude(steam0, steam1, steamStart); // Init de eCum dans neighbouroude; duplique le for -1 dedans;
    }
}
