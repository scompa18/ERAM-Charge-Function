#include <iostream>
#include <TF2.h>
#include <TCanvas.h>
#include <TApplication.h>
#include "ion_charge_function.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "This is a test" << endl;
    
    // This should be the integral of Ei(-(x^2+y^2)) in a
    // square of side one centered around the origin
    cout << ion_charge_function(
        -3.58, -3.43, // Center of pad
        1.118, 1.009, // random pad length
        142e-6,   // k such that it kills the factor of four
        10,     // t that does not bother
        2.,     // m that does not bother
        1000.      // T that does not bother us
    ) << endl;

    return 0;
}
