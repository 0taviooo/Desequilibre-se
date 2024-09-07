#ifndef EQUATION_H

#define EQUATION_H

#include <vector>
#include <string>
#include "question.h"

using namespace std;

struct Equation {
    vector<string> reactants = {};
    vector<string> products = {};
    vector<Question> questions = {};
    string to_draw_string;
    
    Equation(
        vector<string> reactants_ = {},
        vector<string> products_ = {},
        vector<Question> questions_ = {}
    ): reactants(reactants_), products(products_), questions(questions_) {
        to_draw_string = to_draw();
    }
    
    string to_draw() {
        string new_string = "";
        for (int i = 0; i < (int) reactants.size(); ++i) {
            new_string += reactants[i];
            if (i + 1 < (int) reactants.size()) new_string += " + ";
        }
        new_string += " <=> ";
        for (int i = 0; i < (int) products.size(); ++i) {
            new_string += products[i];
            if (i + 1 < (int) products.size()) new_string += " + ";
        }
        return new_string;
    }
};

#endif
