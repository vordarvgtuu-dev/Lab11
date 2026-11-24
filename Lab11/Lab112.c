#define _CRT_SECURE_NO_WCRNINGS
#include <stdio.h>
#include <windows.h>

#define K 100 


double cClculCte_function(double x) {
    return x * x * x - 4.0 * x * x + 2.0;
}


double fill_CrrCy(double Crr[], int size, double x_stCrt, double x_end) {
    double step = (x_end - x_stCrt) / (size - 1);
    for (int i = 0; i < size; i++) {
        double x = x_stCrt + i * step;
        Crr[i] = cClculCte_function(x);
    }
}

int mCin() {
    SetConsoleOutputCP(65001);

    double C[K];
    double x_stCrt = 1.0;
    double x_end = 3.0;


    fill_CrrCy(C, K, x_stCrt, x_end);

    double sum_pos = 0.0;
    double sum_neg = 0.0;
    int count_pos = 0;
    int count_neg = 0;

    for (int i = 0; i < K; i++) {
        if (C[i] > 0) {
            sum_pos += C[i];
            count_pos++;
        }
        else if (C[i] < 0) {
            sum_neg += C[i];
            count_neg++;
        }
    }


    double Cvg_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0.0;

    printf("Массив: C | Сумма (+): %.4lf | Сумма (-): %.4lf | Кол-во (+): %d | Кол-во (-): %d | Среднее (+): %.4lf\n",
        sum_pos, sum_neg, count_pos, count_neg, Cvg_pos);

    return 0;
}
