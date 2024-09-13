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
            Question("Se aumentarmos a concentração de F2 para \nqual lado direção o sistema tende a ir?", true),
            Question("Se diminuirmos a concentração de F2 para \nqual lado direção o sistema tende a ir?", false),
            Question("Para qual lado a reação tende \na ir se aumentarmos o volume do recipiente", true),
            Question("Para qual lado a reação tende \na ir se diminuirmos o volume do recipiente", false)
        }
    ),
    Equation(
        {"2SO2(g)" , "O2(g)"},
        {"2SO3(g)", " DH<0"},
        {
            Question("Para qual lado a reação tende a ir se \naumentarmos a temperatura da reação?", false),
            Question("Para qual lado a reação tende a ir se \ndiminuirmos a temperatura da reação?", true),
            Question("Para qual lado a reação tende \na ir se aumentarmos o volume do recipiente", true),
            Question("Para qual lado a reação tende \na ir se diminuirmos o volume do recipiente", false)
        }
    ),
    Equation(
        {"N2(g)" , "3H2(g)"},
        {"2NH3(g)"},
        {
            Question("Para qual lado a reação irá se \naumentarmos a pressão sobre o sistema?", true),
            Question("Para qual lado a reação irá se \ndiminuirmos a pressão sobre o sistema?", false),
            Question("Para qual lado o equilíbrio se desloca se \na concentração de NH3 for aumentada?", false),
            Question("Para qual lado o equilíbrio se desloca se \na concentração de NH3 for diminuida?", true)
        }
    ),
    Equation(
        {"Fe2O3(s)" , "3CO(g)"},
        {"2Fe(s)", "3CO2(g)"},
        {
            Question("Para qual lado a reação tende a ir se \ndiminuirmos a concentração de 3CO2 no sistema?", true),
            Question("Para qual lado a reação tende a ir se \naumentarmos a concentração de 3CO2 no sistema?", false),
            Question("Para qual lado a reação tende \na ir se aumentarmos a pressão do recipiente", false),
            Question("Para qual lado a reação tende \na ir se diminuirmos a pressão do recipiente", true),
        }
    ),
    Equation(
        {"PCl5(g)"},
        {"PCl3(g)", "Cl2(g)", " DH>0"},
        {
            Question("Se diminuirmos a concentração de PCl5, \npara qual lado a reação tende a ir?", false),
            Question("Se aumentarmos a concentração de PCl5, \npara qual lado a reação tende a ir?", true),
            Question("Para qual lado a reação tende a ir se \ndiminuirmos o volume do recipiente?", true),
            Question("Para qual lado a reação tende a ir se \naumentarmos o volume do recipiente?", false),
            Question("Para qual lado a reação tende \na ir se resfriarmos o sistema?", true),
            Question("Para qual lado a reação tende \na ir se esquentarmos o sistema?", false)
        }
    ),
    Equation(
        {"CO2(g)" , "H2(g)"},
        {"2CO(g)", " H2O(g)"},
        {
            Question("Se adicionarmos mais CO2 ao sistema, \npara qual lado o equilíbrio irá se deslocar?", true),
            Question("Se tirarmos certa quantidade de CO2 do sistema, \npara qual lado o equilíbrio irá se deslocar?", false),
            Question("Para qual lado a reação tende \na ir se aumentarmos o volume do recipiente", true),
            Question("Para qual lado a reação tende \na ir se diminuirmos o volume do recipiente", false)
        }
    ),
    Equation(
        {"CH3COOH(l)" , "C2H5OH(l)"},
        {"CH3COOC2H5(l)", "H2O(l)", " DH<0"},
        {
            Question("O que acontece com o equilíbrio se \ndiminuirmos a temperatura da reação?", false),
            Question("O que acontece com o equilíbrio se \naumentarmos a temperatura da reação?", true)
        }
    ),
    Equation(
        {"N2(g)" , "3O2(g)"},
        {"2NO3(g)", " DH>0"},
        {
            Question("Para qual lado o equilíbrio se \ndesloca se a temperatura for diminuída?", false),
            Question("Para qual lado o equilíbrio se \ndesloca se a temperatura for aumentada?", true)
        }
    ),
    Equation(
        {"2SO2(g)", "O2(g)"},
        {"2SO3(g)"},
        {
            Question("Se diminuirmos a pressão do sistema, qual \nserá a direção de deslocamento do equilíbrio?", false),
            Question("Se aumentarmos a pressão do sistema, qual \nserá a direção de deslocamento do equilíbrio?", true)
        }
    ),
    Equation(
        {"4NH3(g)", "3O2(g)"},
        {"2N2(g)", "6H2O(g)"},
        {
            Question("Para qual lado a reação tende \na ir se adicionarmos N2(g)?", false),
            Question("Para qual lado a reação tende \na ir se retirarmos N2(g)?", true),
            Question("Para qual lado a reação tende \na ir se aumentarmos a pressão?", false),
            Question("Para qual lado a reação tende \na ir se diminuirmos a pressão?", true),
            Question("Para qual lado a reação tende \na ir se diminuirmos a concentração de 4NH3(g)?", false),
            Question("Para qual lado a reação tende \na ir se aumentarmos a concentração de 4NH3(g)?", true)
        }
    ),
    Equation(
        {"2NO2(g)", "3O2(g)"},
        {"N2O4(g)", " DH<0"},
        {
            Question("Para qual lado a reação tende \na ir se aumentarmos a temperatura?", false),
            Question("Para qual lado a reação tende \na ir se diminuirmos a temperatura?", true),
            Question("Para qual lado a reação tende \na ir se aumentarmos o volume do recipiente", true),
            Question("Para qual lado a reação tende \na ir se diminuirmos o volume do recipiente", false),
            Question("Para qual lado a reação tende a \nir se diminuirmos a concentração de 2NO2(g)?", false),
            Question("Para qual lado a reação tende a \nir se aumentarmos a concentração de 2NO2(g)?", true)
        }
    )
};

#endif