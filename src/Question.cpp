#include "../include/Question.h"

Question::Question(const std::string& question, const std::vector<std::string>& answers, int correctAnswer)
    : question(question), answers(answers), correctAnswerIndex(correctAnswer) {}

const std::string& Question::getQuestion() const {
    return question;
}

const std::vector<std::string>& Question::getAnswers() const {
    return answers;
}

int Question::getCorrectAnswerIndex() const {
    return correctAnswerIndex;
}
