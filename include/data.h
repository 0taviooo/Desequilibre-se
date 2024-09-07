#ifndef DATA_H

#define DATA_H

#include "equation.h"
#include "question.h"
#include <vector>

std::vector<Equation> data = {
    Equation(
        {"2F2(g)" , "O2(g)" , "ΔH = 11,0 kcal"},
        {"2FO2(g)"},
        {
            Question("Se aumentarmos a concentração de F2 para qual lado direção o sistema tende a ir?", true)
        }
    ),
    Equation(
        {"2SO2(g)" , "O2(g)"},
        {"2SO3(g)", "ΔH < 0"},
        {
            Question("Para qual lado a reação tende a ir se aumentarmos a temperatura da reação? ", false)
        }
    ),
    Equation(
        {"N2(g)" , "3H2(g)"},
        {"2NH3(g)"},
        {
            Question("Para qual lado a reação irá se aumentarmos a pressão sobre o sistema?", true)
        }
    ),
    Equation(
        {"Fe2O3(s)" , "3CO(g)"},
        {"2Fe(s)", "3CO2(g)"},
        {
            Question("Para qual lado a reação tende a ir se diminuirmos a concentração de 3CO2 no sistema?", true)
        }
    ),
    Equation(
        {"PCl5(g)"},
        {"PCl3(g)", "Cl2(g)", "ΔH = +39,5 kcal/mol"},
        {
            Question("Se diminuirmos a concentração de PCl5, para qual lado a reação tende a ir?", false)
        }
    ),
};

#endif