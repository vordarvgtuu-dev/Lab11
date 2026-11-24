#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define N 10
#define K 100

void input_array(float arr[], int size) {
    float temp;
    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        arr[i] = temp;
    }
}

void make_doubled(float dest[], const float src[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i] * 2;
    }
}

float print_table(const float src[], const float doubled[], int size) {
    float sum = 0.0f;
    printf("\n.--------.-------------------.-------------------.\n");
    printf("| %-6s | %-17s | %-17s |\n", "индекс", "исходное значение", "новое значение   ");
    printf(":--------+-------------------+-------------------:\n");
    for (int i = 0; i < size; i++) {
        printf("| %-6d | %-17.2f | %-17.2f |\n", i + 1, src[i], doubled[i]);
        sum += doubled[i];
    }
    printf("'--------.-------------------.-------------------'\n");
    return sum;
}

float find_average(float sum, int size) {
    return sum / size;
}

double calculate_function(double x) {
    return x * x * x - 4.0 * x * x + 2.0;
}

void fill_function_array(double C[], int size, double x_start, double x_end) {
    double step = (x_end - x_start) / (size - 1);
    for (int i = 0; i < size; i++) {
        double x = x_start + i * step;
        C[i] = calculate_function(x);
    }
}

void print_stats(const double C[], int size) {
    double sum_pos = 0.0, sum_neg = 0.0;
    int count_pos = 0, count_neg = 0;

    for (int i = 0; i < size; i++) {
        if (C[i] > 0) {
            sum_pos += C[i];
            count_pos++;
        }
        else if (C[i] < 0) {
            sum_neg += C[i];
            count_neg++;
        }
    }

    double avg_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0.0;

    printf("\nЗАДАНИЕ 2:\nМассив: C | Сумма (+): %.4lf | Сумма (-): %.4lf | Кол-во (+): %d | Кол-во (-): %d | Среднее (+): %.4lf\n",
        sum_pos, sum_neg, count_pos, count_neg, avg_pos);
}

int main() {
    SetConsoleOutputCP(65001);

    printf("ЗАДАНИЕ 1:\nВведите %d вещественных чисел:\n", N);

    float A[N];
    float B[N];

    input_array(A, N);
    make_doubled(B, A, N);

    float sum = print_table(A, B, N);
    float average = find_average(sum, N);
    printf("\nСреднее арифметическое преобразованного массива: %.2f\n", average);

    double C[K];
    fill_function_array(C, K, 1.0, 3.0);
    print_stats(C, K);

    return 0;
}
