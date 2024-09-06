#ifndef EQUATION_H

#define EQUATION_H

#include <vector>
#include "question.h"

using namespace std;

class Equation {
    vector<const char*> reactants = {};
    vector<const char*> products = {};
    vector<Question> questions = {};
    
    Equation(
        vector<const char*> reactants_ = {},
        vector<const char*> products_ = {},
        vector<Question> questions_ = {}
    ): reactants(reactants_), products(products_), question(questions_) {}
};

#endif
