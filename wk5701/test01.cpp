#include <iostream>
#include <random>
#include <chrono>
#include <thread>

#define MATRIX_SIZE 1000
#define THREADS_NUMBER 4
#define N_EXECUTIONS 1e3


class Matrix{
public:
	Matrix(unsigned int n)
		:size(n)
	{
		elements = new float*[n];
		for(int i=0; i < n; ++i){
			elements[i] = new float[n];
			for(int j=0; j < n; ++j){
				elements[i][j] = 0.0f;
			}
		}
	}

	void initialize_random(){
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(-1e9, -1e9);
		auto random = std::bind(dist, mt);
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				elements[i][j] = random();
			}
		}
	}
	
	unsigned int get_size(){
		return size;
	}


	static void multiply_threading(Matrix& result, const int thread_number, const Matrix& m1, const Matrix& m2)
       	{
  	// Calculate workload
  	const int n_elements = (MATRIX_SIZE * MATRIX_SIZE);
  	const int n_operations = n_elements / THREADS_NUMBER;
  	const int rest_operations = n_elements % THREADS_NUMBER;

  	int start_op, end_op;

  	if (thread_number == 0) {
    		// First thread does more job
    		start_op = n_operations * thread_number;
    		end_op = (n_operations * (thread_number + 1)) + rest_operations;
  	}
 	 else {
   		 start_op = n_operations * thread_number + rest_operations;
   		 end_op = (n_operations * (thread_number + 1)) + rest_operations;
  	}

  	for (int op = start_op; op < end_op; ++op) {
    		const int row = op % MATRIX_SIZE;
    		const int col = op / MATRIX_SIZE;
    		float r = 0.0f;
    		for (int i = 0; i < MATRIX_SIZE; ++i) {
      			const float e1 = m1.elements[row][i];
      			const float e2 = m2.elements[i][col];
      			r += e1 * e2;
    		}

    		result.elements[row][col] = r;
  		}
	}


	Matrix operator*(const Matrix& m){
		Matrix r(size);
		std::thread threads[THREADS_NUMBER];

		for (int i = 0; i < THREADS_NUMBER; ++i) {
			threads[i] = std::thread(multiply_threading, r, i, this, m);
		}

		for (int i = 0; i < THREADS_NUMBER; ++i) {
			threads[i].join();
		}
		return r;
	}


private:
	float **elements;
	unsigned int size;
};




int main(int argc, char *argv[]){
	Matrix r(MATRIX_SIZE);
	Matrix m1(MATRIX_SIZE);
	Matrix m2(MATRIX_SIZE);
	
	m1.initialize_random();
	m2.initialize_random();

	
	r = m1*m2;
	return 0;
}
