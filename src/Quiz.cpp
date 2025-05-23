#include "../include/Quiz.h"

Quiz::Quiz(const std::vector<Question>& questions) : questions(questions) {}

bool Quiz::startQuiz() {
    std::string response;
    std::cout << "----------------------------\n";
    std::cout << "       WELCOME TO THE       \n";
    std::cout << "       MUSEUM QUIZ GAME     \n";
    std::cout << "----------------------------\n";
    std::cout << "Test your knowledge of art, history, and science!\n";
    std::cout << "Answer the questions correctly to earn loyalty points.\n";
    std::cout << "Score 50 points or more to win 50 loyalty points!\n";
    std::cout << "You can only play this game once, do you want to continue?(yes/no): ";
    std::cin >> response;

    if (response == "yes") {
        std::cout << "Let's get started!\n\n";
        return true;
    }
    if (response == "no") {
        std::cout << "You can take this quiz another time\n\n";
    } else {
        std::cout << "That is not a valid answer!\n";
    }
    return false;
}

bool Quiz::winQuiz() {
    int score = 0;
    for (int i = 0; i < questions.size(); i++) {
        std::cout << "Q" << (i+1) << ": " << questions[i].getQuestion() << "\n";
        for (int j = 0; j < questions[i].getAnswers().size(); j++) {
            std::cout << "  " << (j+1) << ". " << questions[i].getAnswers()[j] << "\n";
        }
        std::cout << "Your answer number: ";
        int answer;
        std::cin >> answer;

        if (answer - 1 == questions[i].getCorrectAnswerIndex()) {
            std::cout << "Correct!\n";
            score++;
        } else {
            std::cout << "Wrong. Correct answer was: "
                      << questions[i].getAnswers()[questions[i].getCorrectAnswerIndex()] << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "Quiz finished! You scored " << score << " out of " << questions.size() << ".\n";
    if (score >= 5) {
        std::cout << "You’ve won 50 loyalty points!\n";
        return true;
    }
    return false;
}
