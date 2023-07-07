#include <iostream>
#include <random>
#include <iomanip>


// structure to calculate pi via monte-carlo
struct monte_pi {

        // constructor
        monte_pi(int num_samples_in){
                num_samples = num_samples_in;
        }

        // // function which calls method to estimate pi
        double estimate_pi(){

                // create random number normal distribution
                std::random_device local_rand; // PRNG
                std::mt19937 local_gen(local_rand()); // Mersenne Twister PRNG
                std::uniform_real_distribution<double> my_distro(-1.0, 1.0); // 2x2 box

                // generate random x and y sample points
                for(int i =0; i < num_samples; i++) {

                        x = my_distro(local_gen);
                        y = my_distro(local_gen);

                        sum+= x;

                        // if random points hit inside circle, incriment hits
                        if(x*x + y*y <= 1) {circle_hits++;}
                }

                // note: circle_hits / samples ~ circle_area / square_area ~ pi * r^2 / 2^2
                return pi_calc = 4.0 * static_cast<double>(circle_hits) / static_cast<double>(num_samples);
        }

        // getter - print answer
        void print_answer(){
                std::cout << "monte-carlo method called... " << '\n';
                std::cout << std::setprecision(16) << "pi: " << pi_calc << '\n';
        }

        ~monte_pi() = default;

protected:
        int num_samples{}, circle_hits{};
        double x{}, y{}, pi_calc{}, sum{};
};



// main
int main() {

        // -----
        //
        // READ ME
        //
        // this algorithm approximates pi via simple monte-carlo, it defines a square region of interest (ROI) and inside this a circle (ROI),
        // considering: circle_hits / monte_carlo_samples ~ circle_area / square_area ~ pi * r^2 / 2^2,
        // the value of pi is hence determined.
        //
        // to use this code, specify the number of monte-carlo events, as below...
        // note: more monte-carlo events will create a better approximation to pi,
        //
        //  specify the number of monte-carlo events here
        int num_samples = 10000000;

        // create a monte-carlo structure
        monte_pi pi_1 = monte_pi(num_samples);

        // call member function to estimate pi
        pi_1.estimate_pi();

        // call member function to print answer
        pi_1.print_answer();


        std::cout << "done." << '\n';
        return 0;
}
