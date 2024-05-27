//
// Created by Arthur Horeanu on 21.05.2024.
//

#ifndef S5_REVIEW_H
#define S5_REVIEW_H
#include <string>
#include <ctime>


class Review {
    std::string reviewArtcile;
    std::string ratingUser;
    time_t reviewTimeStamp;
    std::string reviewTitle;
    std::string reviewBody;
};


#endif //S5_REVIEW_H
