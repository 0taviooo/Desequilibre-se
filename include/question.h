#ifndef QUESTION_H

#define QUESTION_H

using namespace std;

struct Question {
    const char* text;
    bool answer = false;
    
    Question(
        const char* text_ = "",
        bool answer_ = false
    ): text(text_), answer(answer) {}
};

#endif
