#ifndef DATA_H

#define DATA_H

#include "equation.h"
#include "question.h"
#include <vector>

std::vector<Equation> material_data = {
    Equation(
        {"2F2(g)" , "O2(g)"},
        {"2FO2(g)", " DH>0"},
        {
            Question("Se aumentarmos a concentração de F2 para \nqual lado direção o sistema tende a ir?", true)
        }
    ),
    Equation(
        {"2SO2(g)" , "O2(g)"},
        {"2SO3(g)", " DH<0"},
        {
            Question("Para qual lado a reação tende a ir se \naumentarmos a temperatura da reação?", false)
        }
    ),
    Equation(
        {"N2(g)" , "3H2(g)"},
        {"2NH3(g)"},
        {
            Question("Para qual lado a reação irá se \naumentarmos a pressão sobre o sistema?", true),
            Question("Para qual lado o equilíbrio se desloca se \na concentração de NH3 for aumentada?", false)
        }
    ),
    Equation(
        {"Fe2O3(s)" , "3CO(g)"},
        {"2Fe(s)", "3CO2(g)"},
        {
            Question("Para qual lado a reação tende a ir se \ndiminuirmos a concentração de 3CO2 no sistema?", true)
        }
    ),
    Equation(
        {"PCl5(g)"},
        {"PCl3(g)", "Cl2(g)", " DH>0"},
        {
            Question("Se diminuirmos a concentração de PCl5, \npara qual lado a reação tende a ir?", false),
            Question("Para qual lado a reação tende a ir se \ndiminuirmos o volume do recipiente?", true),
            Question("Para qual lado a reação tende \na ir se resfriarmos o sistema?", true),
            Question("Para qual lado a reação tende a ir \nse aumentarmos a concentração de PCl5(g)?", true)
        }
    ),
    Equation(
        {"CO2(g)" , "H2(g)"},
        {"2CO(g)", " H2O(g)"},
        {
            Question("Se adicionarmos mais CO2 ao sistema, \npara qual lado o equilíbrio irá se deslocar?", true)
        }
    ),
    Equation(
        {"CH3COOH(l)" , "C2H5OH(l)"},
        {"CH3COOC2H5(l)", "H2O(l)", " DH<0"},
        {
            Question("O que acontece com o equilíbrio se \ndiminuirmos a temperatura da reação?", false)
        }
    ),
    Equation(
        {"N2(g)" , "3O2(g)"},
        {"2NO3(g)", " DH>0"},
        {
            Question("Para qual lado o equilíbrio se \ndesloca se a temperatura for diminuída?", false)
        }
    ),
    Equation(
        {"2SO2(g)", "O2(g)"},
        {"2SO3(g)"},
        {
            Question("Se diminuirmos a pressão do sistema, qual \nserá a direção de deslocamento do equilíbrio?", false)
        }
    ),
    Equation(
        {"4NH3(g)", "3O2(g)"},
        {"2N2(g)", "6H2O(g)"},
        {
            Question("Para qual lado a reação tende \na ir se adicionarmos N2(g)?", false),
            Question("Para qual lado a reação tende \na ir se aumentarmos a pressão?", false),
            Question("Para qual lado a reação tende \na ir se diminuirmos a concentração de 4NH3(g)?", false)
        }
    ),
    Equation(
        {"2NO2(g)", "3O2(g)"},
        {"N2O4(g)", " DH<0"},
        {
            Question("Para qual lado a reação tende \na ir se aumentarmos a temperatura?", false),
            Question("Para qual lado a reação tende \na ir se aumentarmos o volume do recipiente", true),
            Question("Para qual lado a reação tende a \nir se diminuirmos a concentração de 2NO2(g)?", false)
        }
    )
};

#endif