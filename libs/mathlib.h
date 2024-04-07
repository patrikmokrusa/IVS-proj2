//======== Copyright (c) 2018, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Custom math lib for kalkulacka project
//
// $NoKeywords: $kalkulacka $mathlib.h
// $Author:    Patrik Mokruša <xmokrup00@stud.fit.vutbr.cz>
// $Date:       $2024-07-04
//============================================================================//
/**
 * @file mathlib.h
 * @author Patrik Mokruša
 *
 * @brief Definice funkci matematicke knihovny pro kalkulacka
 */

#include <stdlib.h>
#pragma 

#ifndef MATHLIB_H_
#define MATHLIB_H_





/**
 * @brief k_plus
 * přičte add_num k base_num
 * @param[in, out] base_num prvni ciclo (pred +)
 * @param[in] add_num druhe cislo (za +)
 * @return vraci 0 pri uspechu
*/
int k_plus(float base_num, float add_num){
    float temp_num = base_num + add_num;
    base_num = temp_num;
    return 0;
};

/**
 * @brief k_minus
 * odecte sub_num od base_num
 * @param[in, out] base_num prvni ciclo (pred -)
 * @param[in] sub_num druhe cislo (za -)
 * @return vraci 0 pri uspechu
*/
int k_minus(float base_num, float sub_num){
    base_num = base_num - sub_num;
    return 0;
};

/**
 * @brief k_krat
 * prinasobi tiems_num k base_num
 * @param[in, out] base_num prvni ciclo (pred *)
 * @param[in] times_num druhe cislo (za *)
 * @return vraci 0 pri uspechu
*/
int k_krat(float base_num, float times_num){
    base_num = base_num * times_num;
    return 0;
};

/**
 * @brief k_deleno
 * vydeli base_num s div_num
 * @param[in, out] base_num prvni ciclo (pred /)
 * @param[in] div_num druhe cislo (za /)
 * @return vraci 0 pri uspechu, vraci 1 pri deleni nulou
*/
int k_deleno(float base_num, float div_num){
    if (div_num == 0) {
        return 1;
    }
    base_num = base_num / div_num;
    return 0;
};

/**
 * @brief k_faktorial
 * vypocita faktorial
 * @param[in, out] base_num cislo ze ktereho chceme faktorial
 * @return vraci 0 pri uspechu, vraci 1 pri faktorialu desetineho cisla
*/
int k_faktorial(float base_num){
    return 0;
}

/**
 * @brief k_mocnina
 * umocni basenum_num na^ base_num
 * @param[in, out] base_num puvodni ciclo (pod mocninou)
 * @param[in] mocnitel cislo na (mocnitel)
 * @return vraci 0 pri uspechu, vraci 1 pri mocnitel < 0 nebo desetinne cislo
*/
int k_mocnina(float base_num, int mocnitel){
    return 0;
}

/**
 * @brief k_odmocnina
 * base_num odmocni odmocnitel -em
 * @param[in, out] base_num puvodni cislo (pod odmocninou)
 * @param[in] times_num kolikata odmocnina (odmocnitel)
 * @return vraci 0 pri uspechu, 1 pri odmocnitel =< 0 nebo desetinne cislo 
*/
int k_odmocnina(float base_num, int odmocnitel){

    return 0;
}
/**
 * @brief k_custom_fce
 * @todo vymyslet
 * 
*/
int k_custom_fce(float base_num, float other_num){
    return 0;
}





#endif // MATHLIB_H_