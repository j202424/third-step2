#include <stdio.h>
#include <math.h>

#define NUM_STUDENTS 20

// 関数宣言
void calculate_stats(int scores[], int n, float *mean, float *std_dev, int *sum);
void calculate_zscores(int scores[], int n, float mean, float std_dev, float zscores[]);
void sort_scores(int scores[], int n);

int main() {
    // 笑介くんのクラスの理科と英語の点数
    int science_scores[NUM_STUDENTS] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
    int english_scores[NUM_STUDENTS] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

    // 平均点、標準偏差、合計点の初期化
    float science_mean, science_std_dev, english_mean, english_std_dev;
    int science_sum = 0, english_sum = 0;

    // 統計量の計算
    calculate_stats(science_scores, NUM_STUDENTS, &science_mean, &science_std_dev, &science_sum);
    calculate_stats(english_scores, NUM_STUDENTS, &english_mean, &english_std_dev, &english_sum);

    // 偏差値の計算
    float science_zscores[NUM_STUDENTS], english_zscores[NUM_STUDENTS];
    calculate_zscores(science_scores, NUM_STUDENTS, science_mean, science_std_dev, science_zscores);
    calculate_zscores(english_scores, NUM_STUDENTS, english_mean, english_std_dev, english_zscores);

    // 点数の高い順に並べ替え
    sort_scores(science_scores, NUM_STUDENTS);
    sort_scores(english_scores, NUM_STUDENTS);

    // 結果の表示
    printf("Science Statistics:\n");
    printf("Mean: %.2f\n", science_mean);
    printf("Standard Deviation: %.2f\n", science_std_dev);
    printf("Total Score: %d\n", science_sum);
    printf("Sorted Scores (high to low):\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%d ", science_scores[i]);
    }
    printf("\n");

    printf("\nEnglish Statistics:\n");
    printf("Mean: %.2f\n", english_mean);
    printf("Standard Deviation: %.2f\n", english_std_dev);
    printf("Total Score: %d\n", english_sum);
    printf("Sorted Scores (high to low):\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%d ", english_scores[i]);
    }
    printf("\n");

    return 0;
}

// 平均点と標準偏差、合計点を計算する関数
void calculate_stats(int scores[], int n, float *mean, float *std_dev, int *sum) {
    // 平均点の計算
    *sum = 0;
    for (int i = 0; i < n; i++) {
        *sum += scores[i];
    }
    *mean = (float)*sum / n;

    // 標準偏差の計算
    float sum_squared_diff = 0.0;
    for (int i = 0; i < n; i++) {
        sum_squared_diff += pow(scores[i] - *mean, 2);
    }
    *std_dev = sqrt(sum_squared_diff / n);
}

// 偏差値を計算する関数
void calculate_zscores(int scores[], int n, float mean, float std_dev, float zscores[]) {
    for (int i = 0; i < n; i++) {
        zscores[i] = (scores[i] - mean) / std_dev * 10 + 50; // 偏差値の計算式
    }
}

// 配列を高い順に並べ替える関数
void sort_scores(int scores[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                // スワップ
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

