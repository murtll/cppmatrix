#include <iostream>
#include <algorithm>

void bubbleSort(std::pair<int, int> *arr, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].second > arr[j].second)
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int m;
    std::cout << "Enter matrix size (one number): ";
    std::cin >> m;
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new double[m];
    }
    std::cout << "Enter " << m * m << " matrix elements splitted by spaces: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    double* freeMems = new double[m];
    std::cout << "Enter " << m << " free members splitted by spaces: ";
    for (int i = 0; i < m; i++) {
        std::cin >> freeMems[i];
    }
    std::cout << std::endl << "Steps: " << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << "| " << freeMems[i] << std::endl;
	}
    for (int j = 0; j < m; j++)
    {
        for (int i = j + 1; i < m; i++)
        {
            int b, a;
            if (matrix[j][j] != 0) {
                b = matrix[j][j];
                if (matrix[i][j] != 0) {
                    a = matrix[i][j];
                    for (int k = 0; k < m; k++) {
                        matrix[j][k] = matrix[j][k] * a;

                    }
                    freeMems[j] = freeMems[j] * a;
                    for (int k = 0; k < m; k++) {
                        matrix[i][k] = matrix[i][k] * b;
                    }
                    freeMems[i] = freeMems[i] * b;

                    for (int k = 0; k < m; k++) {
                        matrix[i][k] -= matrix[j][k];
                    }

                    freeMems[i] -= freeMems[j];
                    for (int k = 0; k < m; k++) {
                        matrix[j][k] = matrix[j][k] / a;
                    }
                    freeMems[j] = freeMems[j] / a;
                }
            }
        }
        std::cout << std::endl;
        std::cout << "↓" << std::endl;
        std::cout << std::endl;

        for (int w = 0; w < m; w++)
        {
            for (int v = 0; v < m; v++)
            {
                std::cout << matrix[w][v] << ' ';
            }
            std::cout << " | " << freeMems[w] << std::endl;
        }
        std::cout << std::endl;
    }
    std::pair<int, int>* tmp = new std::pair<int, int>[m];
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                break;
            }
            else {
                count++;
            }
        }
        std::pair<int, int> p(i, count);
        tmp[i] = p;
    }

    bubbleSort(tmp, m);

    for (int j = m - 1; j > 0; j--) {
        for (int i = j - 1; i >= 0; i--) {
            int b, a;
            if (matrix[tmp[j].first][j] != 0) {
                freeMems[tmp[j].first] = freeMems[tmp[j].first] / matrix[tmp[j].first][j];
                matrix[tmp[j].first][j] = 1;
                b = matrix[tmp[j].first][j];
                if (matrix[tmp[i].first][j] != 0) {
                    a = matrix[tmp[i].first][j];

                    for (int k = 0; k < m; k++) {
                        matrix[tmp[j].first][k] = matrix[tmp[j].first][k] * a;
                    }
                    freeMems[tmp[j].first] = freeMems[tmp[j].first] * a;
                    for (int k = 0; k < m; k++) {
                        matrix[tmp[i].first][k] = matrix[tmp[i].first][k] * b;
                    }
                    freeMems[tmp[i].first] = freeMems[tmp[i].first] * b;

                    for (int k = 0; k < m; k++) {
                        matrix[tmp[i].first][k] -= matrix[tmp[j].first][k];
                    }
                    freeMems[tmp[i].first] -= freeMems[tmp[j].first];

                    for (int k = 0; k < m; k++) {
                        matrix[tmp[j].first][k] = matrix[tmp[j].first][k] / a;
                    }
                    freeMems[tmp[j].first] = freeMems[tmp[j].first] / a;
                }
            }

        }
    }
    std::cout << std::endl << "============" << std::endl;
    std::cout << std::endl << "Result matrix: " << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[tmp[i].first][j] << " ";
        }
        std::cout << "| " << freeMems[tmp[i].first] << std::endl;
    }
    
    std::cout << std::endl << "============" << std::endl;
    std::cout << std::endl << "Answer: " << std::endl;

    for (int i = 0; i < m; i++)
    {
        if (matrix[tmp[i].first][tmp[i].first] != 0) {
            freeMems[tmp[i].first] = freeMems[tmp[i].first] / matrix[tmp[i].first][tmp[i].first];
            matrix[tmp[i].first][tmp[i].first] = 1;
            std::cout << freeMems[tmp[i].first] << std::endl;
        }
        else
            std::cout << 0 << std::endl;
    }
    return 0;
}
