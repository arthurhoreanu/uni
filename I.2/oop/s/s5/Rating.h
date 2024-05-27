//
// Created by Arthur Horeanu on 21.05.2024.
//

#ifndef S5_RATING_H
#define S5_RATING_H
#include <string>
#include <ctime>

class Rating {
private:
    float ratingArticle;
    std::string ratingUser;
    float ratingValue;
    time_t ratingTimeStamp;
};


#endif //S5_RATING_H
