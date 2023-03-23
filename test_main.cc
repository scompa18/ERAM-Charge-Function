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
        0., 1., // Center of pad
        1., 1., // random pad length
        0.24,   // k such that it kills the factor of four
        1.1,    // t that does not bother
        0.,     // m that does not bother
        1.      // T that does not bother us
    ) << endl;

    return 0;
}
