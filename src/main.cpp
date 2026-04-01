#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Вывод матрицы
void printMatrix(const Matrix& m) {
    for (auto& row : m) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;
}

// Сравнение матриц
bool equal(const Matrix& a, const Matrix& b) {
    return a == b;
}

// Транспонирование по главной диагонали
Matrix transposeMain(const Matrix& m) {
    int n = m.size();
    Matrix res = m;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(res[i][j], res[j][i]);

    return res;
}

// Транспонирование по побочной диагонали
Matrix transposeSecondary(const Matrix& m) {
    int n = m.size();
    Matrix res = m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            swap(res[i][j], res[n - j - 1][n - i - 1]);

    return res;
}

// DFS перебор операций (глубина до 4)
bool dfs(Matrix current, const Matrix& target, int depth) {
    if (equal(current, target))
        return true;

    if (depth == 4)
        return false;

    // Пробуем обе операции
    return dfs(transposeMain(current), target, depth + 1) ||
           dfs(transposeSecondary(current), target, depth + 1);
}

int main() {
    int n;
    cout << "Введите размер N: ";
    cin >> n;

    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    cout << "Введите матрицу A:\n";
    for (auto& row : A)
        for (auto& x : row)
            cin >> x;

    cout << "Введите матрицу B:\n";
    for (auto& row : B)
        for (auto& x : row)
            cin >> x;

    if (dfs(A, B, 0))
        cout << "YES: можно получить за <= 4 операций\n";
    else
        cout << "NO: нельзя\n";

    return 0;
}
