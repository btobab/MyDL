#include <matrix.h>
#include <matrix_grad.h>
#include <iostream>

#define loop 10000
#define test true
#define DL false
#define LEARNING_RATE 1e-6

int main() {
#if test
    Matrix_grad mag1 = Matrix_grad(3, 2, 1.1, 1.0);
    Matrix_grad mag2 = -mag1;
    // mag2.print_matrix();
    // mag1.print_matrix();
    Matrix ma3 = Matrix(3, 3, 1.0, 2.0);
    Matrix ma4 = ma3;
    ma4 -= ma3;
    Matrix ma5 = ma4 * ma3;
    ma3.print();
    ma4.print();
    ma5.print();
    std::cout << "test" << std::endl;
    std::cout << "#####################" << std::endl;
#endif

#if DL
    Matrix_grad x, k, b, y;
    x = Matrix_grad(10, 2, 5.2, 1.0);
    k = Matrix_grad(5.2, 2, 3);
    b = Matrix_grad(1.5, 1, 3);
    y = x * k + b;
    Matrix_grad k_hat, b_hat, y_hat, div, result;
    k_hat = Matrix_grad(3.0, 2, 3);
    b_hat = Matrix_grad(1.0, 1, 3);

    for (int ix = 0; ix < loop; ++ix) {
        y_hat = x * k_hat - b_hat;
        div = y - y_hat;
        result = div.T() * div;
        Matrix_grad::forward();
        k_hat.update(LEARNING_RATE);
        b_hat.update(LEARNING_RATE);

        if (ix % 100 == 0) {
            std::cout << "loop: " << ix << std::endl;
            k_hat.print_matrix();
            b_hat.print_matrix();
        }
        Matrix_grad::clear_gradient();
    }
    k_hat.print_matrix();
    b_hat.print_matrix();
#endif
}