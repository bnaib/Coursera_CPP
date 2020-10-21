#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
	private:
		int					rows;
		int					cols;
		vector<vector<int>>	value;
	public:
		Matrix() {
			this->rows = 0;
			this->cols = 0;
		}
		Matrix(int rows, int cols) {
			this->Reset(rows, cols);
		}
		void	Reset(int rows, int cols) {
			if (rows < 0)
				throw out_of_range("rows must be >= 0");
			if (cols < 0)
				throw out_of_range("cols must be >= 0");
			if (rows == 0 || cols == 0)
				rows = cols = 0;
			this->rows = rows;
			this->cols = cols;
			this->value.assign(rows, vector<int>(cols));
		}
		int		At(int row, int col) const {
			return this->value.at(row).at(col);
		}
		int&	At(int row, int col) {
			return this->value.at(row).at(col);
		}
		int		GetNumRows() const {
			return this->rows;
		}
		int		GetNumColumns() const {
			return this->cols;
		}
};

istream&	operator >>(istream& is, Matrix& matrix) {
	int		rows, cols;

	is >> rows >> cols;
	matrix.Reset(rows, cols);
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++)
			is >> matrix.At(r, c);
	}
	return is;
}

ostream&	operator <<(ostream& os, const Matrix& matrix) {
	int		rows = matrix.GetNumRows();
	int		cols = matrix.GetNumColumns();

	os << rows << " " << cols << endl;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (c > 0)
				os << " ";
			os << matrix.At(r, c);
		}
		os << endl;
	}
	return os;
}

bool		operator ==(const Matrix& m1, const Matrix& m2) {
	int		rows = m1.GetNumRows();
	int		cols = m1.GetNumColumns();

	if (rows != m2.GetNumRows() || cols != m2.GetNumColumns())
		return false;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (m1.At(r, c) != m2.At(r, c))
				return false;
		}
	}
	return true;
}

Matrix		operator +(const Matrix& m1, const Matrix& m2) {
	int		rows = m1.GetNumRows();
	int		cols = m1.GetNumColumns();
	Matrix	result(rows, cols);
	int 	i;

	if (rows != m2.GetNumRows() || cols != m2.GetNumColumns())
		throw invalid_argument("Operator \"+\": size matrix1 != size matrix2");
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++)
		result.At(r, c) = m1.At(r, c) + m2.At(r, c);
	}
	return result;
}

int		main(void) {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
