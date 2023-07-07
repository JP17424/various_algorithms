#include <iostream>
#include <random>
#include <iomanip>


// structure to calculate 'e', eulers number, ~2.718... using a taylor series expansion of e^x
struct taylor_series {

        // constructor
        taylor_series(int terms_in){
                terms = terms_in;
        }

        // function to get factorial(s)
        double factorial(int n) {

                double factorial = 1;

                for (int i = 2; i <= n; ++i) {
                        factorial *= i;
                }
                return factorial;
        }

        // function to estimate eulers number
        double estimate_euler() {

                for (int n = 1; n <= terms; ++n) {
                        answer += 1 / factorial(n);
                }

                return answer;
        }

        // getter - print answer
        void print_answer(){
                std::cout << "taylor series called... " << '\n';
                std::cout << std::setprecision(16) << "eulers number: " << answer << '\n';
        }

        ~taylor_series() = default;

protected:
        int terms{};
        double answer = 1;
};

// main
int main(){


        // -----
        //
        // READ ME
        //
        // this algorithm approximates 'e', eulers number, ~2.718... using a taylor series expansion of e^x,
        // hence, e^1 is taylor expanded to a specified number of terms, such that e^x = 1 + x/1! + x^2/2! + x^3/3! + ...
        //
        // to use this code, specify the number of terms to which you want to expand e^1, as below.
        // note:  increasing the number of terms will produce a more precise approximation
        //
        // specify number of terms here
        int terms = 100;

        // create taylor series structure
        taylor_series e_1 = taylor_series(terms);

        // call member function to estimate eulers number
        e_1.estimate_euler();

        // call member function to print answer
        e_1.print_answer();


        return 0;
}
