#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include <iostream>
#include "Question.h"

class Quiz {
private:
    std::vector<Question> questions;

public:
    explicit Quiz(const std::vector<Question>& questions);
    ~Quiz() = default;

    static bool startQuiz();
    bool winQuiz();
};


#endif //QUIZ_H
