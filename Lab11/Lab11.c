#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <math.h>

#define N 10 
#define K 100 


double cclculcte_function(double x) {
    return x * x * x - 4.0 * x * x + 2.0;
}


double fill_CrrCy(double Crr[], int size, double x_stCrt, double x_end) {
    double step = (x_end - x_stCrt) / (size - 1);
    for (int i = 0; i < size; i++) {
        double x = x_stCrt + i * step;
        Crr[i] = cclculcte_function(x);
    }
}

int main() {
    SetConsoleOutputCP(65001);

    float A[N];
    float B[N];
    float temp;
    float sum = 0.0f;


    printf("ЗААДАНИЕ 1:\nВведите %d вещественных чисел:\n", N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
        B[i] = temp;
    }

    for (int i = 0; i < N; i++) {
        B[i] = B[i] * 2;
    }
    printf("\n.--------.-------------------.-------------------.\n");
    printf("| %-6s | %-17s | %-17s |\n", "индекс", "исходное значение", "новое значение   ");
    printf(":--------+-------------------+-------------------:\n");

    for (int i = 0; i < N; i++) {
        printf("| %-6d | %-17.2f | %-17.2f |\n", i + 1, A[i], B[i]);
        sum += B[i];
    }

    printf("'--------'-------------------'-------------------'\n");

    float average = sum / N;
    printf("\nСреднее арифметическое преобразованного массива: %.2f\n", average);

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


    double cvg_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0.0;

    printf("\n\nЗААДАНИЕ 2:\nМассив: C | Сумма (+): %.4lf | Сумма (-): %.4lf | Кол-во (+): %d | Кол-во (-): %d | Среднее (+): %.4lf\n",
        sum_pos, sum_neg, count_pos, count_neg, cvg_pos);
    return 0;
}
