/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __MINSEAM_H__
#define __MINSEAM_H__
#include <opencv2/core/core.hpp>
#include <vector>

class MinSeam {
    public:
        MinSeam(const cv::Mat & background, const cv::Mat & foreground, const cv::Mat & mask);
        virtual ~MinSeam();
        cv::Mat getEnergy() const;
        cv::Mat getEnergyCum(unsigned int i) const;
        void computeEnergyCumMaps();
        void computeMinimalSeam() const;

    private:
        cv::Mat _background;
        cv::Mat _foreground;
        cv::Mat _mask;

    private:
        cv::Mat_<cv::Vec3f> _energy;
        std::vector<std::pair<cv::Mat, cv::Point > > _energyCum;
        void neighbouroude (const cv::Point & steam0, const cv::Point & steam1, const cv::Point & steamStart);
};

#endif /* __MINSEAM_H__ */
