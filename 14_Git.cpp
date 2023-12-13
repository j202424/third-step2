#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// 関数宣言
double calculateMean(const std::vector<int>& scores);
double calculateStandardDeviation(const std::vector<int>& scores, double mean);
void calculateZScores(const std::vector<int>& scores, double mean, double stdDev, std::vector<double>& zScores);
void printResults(const std::vector<int>& scores, const std::vector<double>& zScores, const std::string& subject);

int main() {
    // テストの点数データ
    std::vector<int> scienceScores = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
    std::vector<int> englishScores = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

    // 平均点の計算
    double scienceMean = calculateMean(scienceScores);
    double englishMean = calculateMean(englishScores);

    // 標準偏差の計算
    double scienceStdDev = calculateStandardDeviation(scienceScores, scienceMean);
    double englishStdDev = calculateStandardDeviation(englishScores, englishMean);

    // 偏差値の計算
    std::vector<double> scienceZScores;
    calculateZScores(scienceScores, scienceMean, scienceStdDev, scienceZScores);

    std::vector<double> englishZScores;
    calculateZScores(englishScores, englishMean, englishStdDev, englishZScores);

    // 結果の表示
    printResults(scienceScores, scienceZScores, "理科");
    printResults(englishScores, englishZScores, "英語");

    return 0;
}

// 平均点の計算
double calculateMean(const std::vector<int>& scores) {
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }
    return static_cast<double>(sum) / scores.size();
}

// 標準偏差の計算
double calculateStandardDeviation(const std::vector<int>& scores, double mean) {
    double sumSquaredDifferences = 0;
    for (int score : scores) {
        double difference = score - mean;
        sumSquaredDifferences += difference * difference;
    }
    return sqrt(sumSquaredDifferences / scores.size());
}

// 偏差値の計算
void calculateZScores(const std::vector<int>& scores, double mean, double stdDev, std::vector<double>& zScores) {
    zScores.clear();
    for (int score : scores) {
        double zScore = (score - mean) / stdDev * 10 + 50;
        zScores.push_back(zScore);
    }
}

// 結果の表示
void printResults(const std::vector<int>& scores, const std::vector<double>& zScores, const std::string& subject) {
    std::cout << subject << "の結果:\n";
    std::cout << "平均点: " << calculateMean(scores) << "\n";
    std::cout << "標準偏差: " << calculateStandardDeviation(scores, calculateMean(scores)) << "\n";
    std::cout << "合計点: " << std::accumulate(scores.begin(), scores.end(), 0) << "\n";
    
    // 点数の高い順に並べ替え
    std::vector<std::pair<int, double>> sortedScores;
    for (int i = 0; i < scores.size(); ++i) {
        sortedScores.push_back({scores[i], zScores[i]});
    }

    std::sort(sortedScores.begin(), sortedScores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // 結果の表示
    std::cout << "点数の高い順:\n";
    for (const auto& entry : sortedScores) {
        std::cout << "点数: " << entry.first << ", 偏差値: " << entry.second << "\n";
    }

    std::cout << "-----------------------------\n";
}
