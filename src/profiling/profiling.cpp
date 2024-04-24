//============================================================================//
//
// Purpose:     Výpočes směrodatné odchylky k profilingu
//
// $NoKeywords: $kalkulacka $profiling.cpp $profiling
// $Author:    Lukáš Jelínek <xjelinl00@stud.fit.vutbr.cz>
// $Date:       $2024-07-04
//============================================================================//
/**
 * @file profiling.cpp
 * @author Lukáš Jelínek
 *
 * @brief Výpočes směrodatné odchylky, který slouží k profilingu matematické
 * knihovny
 */
#include "../mathlib.cpp"
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  int numbers;
  std::vector<double> v;

  std::string str;
  std::getline(std::cin, str);
  std::istringstream sstr(str);
  int n;

  while (sstr >> n) {
    // scanf("%i", &numbers);
    v.push_back(n);
  }

  /*
    for (int i = 0; i < 1000; i++) {
      scanf("%i", &numbers);
      v.push_back(numbers);
    }
    */

  // Vypsani pole
  // for(int i = 0; i < v.size(); i++){
  //     printf("%lf\n", v[i]);
  // }

  double temp = 0;
  for (int i = 0; i < v.size(); i++) {
    temp = k_plus(temp, v[i]);
  }

  temp = k_deleno(temp, v.size());

  double temp1;
  for (int i = 0; i < v.size(); i++) {
    temp1 = k_minus(v[i], temp);
    temp1 = k_mocnina(temp1, 2);
    v[i] = temp1;
  }

  // printf("\n");

  double temp2;
  for (int i = 0; i < v.size(); i++) {
    temp2 = k_plus(temp2, v[i]);
  }

  double temp3;

  temp3 = k_minus(v.size(), 1);
  temp2 = k_deleno(temp2, temp3);
  temp2 = k_odmocnina(temp2, 2);

  // printf("Výsledek je %lf", temp2);
  printf("%lf", temp2);
  printf("\n");

  return 0;
}
