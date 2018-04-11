#include <iostream>
#include <cstdlib>

double **matrix_product(int n_col_1, int n_col_2, int n_lin_1, int n_lin_2, double **A, double **B){
  double **resultado = new double*[n_lin_1];
  for(int i = 0; i < n_lin_1; i++){
    resultado[i] = new double[n_col_2];
  }
  
  for(int i_1 = 0; i_1 < n_lin_1; i_1++){
    for(int j_2 = 0; j_2 < n_col_2; j_2++){
      double suma = 0;
      for(int j = 0; j < n_col_1; j++){
	for(int i = 0; i<n_lin_2; i++){
	  suma += A[i_1][j]*B[i][j_2];
	}
      }
      resultado[i_1][j_2] = suma;
      std::cout << suma << " ";
    }
    std::cout<<std::endl;
  }
  
  return resultado;
}

double **get_matrix(int M, int N){
  std::cout << M << " " << N << std::endl;
  double **matriz = new double*[M];
  for(int i = 0; i < M; i++){
    matriz[i] = new double[N]; 
  }

  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      std::cout << "Ingrese la posicion" << i << "," << j <<std::endl;
      double par;
      std::cin >> par;
      matriz[i][j] = par;
    }
  }
  
  std::cout << "Esta es la matriz que ingreso" << std::endl;

  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      std::cout << matriz[i][j] << " ";
    }
    std::cout<<std::endl;
  }
  return matriz;
}


int main(){
  int filas_a;
  int filas_b;
  int col_a;
  int col_b;
  std::cout<< "Ingrese filas de A" <<std::endl;
  std::cin >> filas_a;
  std::cout<< "Ingrese filas de B" <<std::endl;
  std::cin >> filas_b;
  std::cout << "Ingrese columnas de A" <<std::endl;
  std::cin >> col_a;
  std::cout<< "Ingrese columnas de B" <<std::endl;
  std::cin >> col_b;
  double **A = get_matrix(filas_a, col_a);
  double **B = get_matrix(filas_b,col_b);
  std::cout << "El producto de A  y B es" << std::endl;
  double **C = matrix_product(col_a,col_b,filas_a,filas_b, A, B);
  
}
