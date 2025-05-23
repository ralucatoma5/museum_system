#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
private:
    std::string question;
    std::vector<std::string> answers;
    int correctAnswerIndex;

public:
    Question(const std::string& question, const std::vector<std::string>& answers, int correctAnswer);
    std::string getQuestion() const;
    std::vector<std::string> getAnswers() const;
    int getCorrectAnswerIndex() const;

    ~Question() = default;
};


#endif //QUESTION_H
