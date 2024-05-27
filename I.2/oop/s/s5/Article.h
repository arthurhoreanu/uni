//
// Created by Arthur Horeanu on 21.05.2024.
//

#ifndef S5_ARTICLE_H
#define S5_ARTICLE_H
#include <string>
#include <ctime>
#include <vector>
#include "Rating.h"
#include "Review.h"


class Article {
private:
    float articleScore;
    std::string artcleReview;
    std::string artcleSubmitter;
    time_t articleTimeStamp;
    float articleRatings;
    bool articleStatus;
    std::vector<Rating> ratings; // may have = vector
    std::vector<Review> reviews;
};


#endif //S5_ARTICLE_H
