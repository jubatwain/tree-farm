#include <iostream>
#include <cmath>

class TreeFarm {
private:
    int N;
    double* heights;

public:
    TreeFarm(int n) {
        N = n;
        heights = new double[N];
    }

    ~TreeFarm() {
        delete[] heights;
    }

    void enterHeights() {
        for (int i = 0; i < N; i++) {
            std::cout << "Enter height of tree " << i+1 << ": ";
            std::cin >> heights[i];
        }
    }

    double getMeanHeight() {
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += heights[i];
        }
        return sum / N;
    }

    double getShortestHeight() {
        double min_height = heights[0];
        for (int i = 1; i < N; i++) {
            if (heights[i] < min_height) {
                min_height = heights[i];
            }
        }
        return min_height;
    }

    double getTallestHeight() {
        double max_height = heights[0];
        for (int i = 1; i < N; i++) {
            if (heights[i] > max_height) {
                max_height = heights[i];
            }
        }
        return max_height;
    }

    double getStdDev() {
        double mean = getMeanHeight();
        double variance = 0;
        for (int i = 0; i < N; i++) {
            variance += pow(heights[i] - mean, 2);
        }
        variance /= N;
        return sqrt(variance);
    }

    double getVariance() {
        double mean = getMeanHeight();
        double variance = 0;
        for (int i = 0; i < N; i++) {
            variance += pow(heights[i] - mean, 2);
        }
        return variance / N;
    }
};

int main() {
    int N;
    std::cout << "Enter the number of trees in the farm: ";
    std::cin >> N;
    TreeFarm farm(N);
    farm.enterHeights();
    std::cout << "The mean height is: " << farm.getMeanHeight() << std::endl;
    std::cout << "The shortest height is: " << farm.getShortestHeight() << std::endl;
    std::cout << "The tallest height is: " << farm.getTallestHeight() << std::endl;
    std::cout << "The standard deviation is: " << farm.getStdDev() << std::endl;
    std::cout << "The variance is: " << farm.getVariance() << std::endl;
    return 0;
}
