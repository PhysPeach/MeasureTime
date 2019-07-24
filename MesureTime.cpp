#include<iostream>
#include<chrono>

#define N 10

class Matrix {
private:
	int dim;
	double a;
public:
	double** Mat;

	Matrix(int n) {
		dim = n;

		Mat = new double*[dim];
		Mat[0] = new double[dim*dim];

		for (int i = 0; i < dim; i++) {
			Mat[i] = Mat[0] + i * dim;
		}
		for (int i = 0; i < dim; i++){
			for (int j = 0; j < dim; j++) {
				Mat[i][j] = (double)(i * dim + j);
			}
		}
	}
	~Matrix() {
		delete[] Mat;
		for (int i = 0; i < dim; i++) {
			delete[] Mat[i];
		}
	}
	inline void access() {
		for (int  i= 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				a = Mat[i][j];
			}
		}
		return;
	}
	inline void maltiple(Matrix a, Matrix b) {
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				for (int k = 0; k < dim; k++) {
					Mat[i][j] = a.Mat[i][k] + b.Mat[k][j];
				}
			}
		}
		return;
	}
};

int main()
{	
	Matrix A(N);
	Matrix B(N);
	Matrix C(N);

	std::chrono::system_clock::time_point start, end;
	std::cout << "start" << std::endl;
	start = std::chrono::system_clock::now();

	//Routine
	for (int hvoiabnu = 0; hvoiabnu < 10000000; hvoiabnu++) {
		C.access();
	}

	end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << elapsed << "ms" << std::endl;
	return 0;
}