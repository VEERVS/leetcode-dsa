/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    *returnSize = 2;
    double k, f;
    double *array = malloc(2 * sizeof(double));

    k = celsius + 273.15;
    f = celsius * 1.80 + 32.00;

    array[0] = k;
    array[1] = f;

    return array;
}