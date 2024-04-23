#include <iostream>
#include <vector>
#include "mathlib.cpp"



int main() {
    int numbers;
    std::vector<double> v;

    for(int i = 0; i < 1000; i++)
    {
        scanf("%i", &numbers);
        v.push_back(numbers);
    }

    //Vypsani pole
    //for(int i = 0; i < v.size(); i++){
    //    printf("%lf\n", v[i]);
    //}

    double temp = 0;
    for(int i = 0; i < v.size(); i++){
        temp = k_plus(temp, v[i]);
    }

    temp = k_deleno(temp, v.size());


    double temp1;
    for(int i = 0; i < v.size(); i++){
        temp1 = k_minus(v[i], temp);
        temp1 = k_mocnina(temp1, 2);
        v[i] = temp1;
    }

    //printf("\n");

    double temp2;
    for(int i = 0; i < v.size(); i++){
        temp2 = k_plus(temp2, v[i]);

    }
    
    double temp3;

    temp3 = k_minus(v.size(), 1);
    temp2 = k_deleno(temp2, temp3);
    temp2 = k_odmocnina(temp2, 2);

    printf("Výsledek je %lf", temp2);
    printf("\n");


    return 0;
}
