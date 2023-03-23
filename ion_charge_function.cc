#include "ion_charge_function.h"
#include "gsl/gsl_specfunc.h"
#include <cmath>
#include <TF2.h>

// Function range will be set in
// x [-max_x_size, max_x_size]
// y [-max_y_size, max_y_size]
#define max_x_size 100.
#define max_y_size 100.

// Charge density function, vector parameters to be compatible with TF2
double charge_density_function(double *xu, double *par) {
    // Unpack inputs
    double x = xu[0];
    double y = xu[1];
    double k = par[0];
    double t = par[1];
    double m = par[2];
    double T = par[3];

    if (t < 0.) return 0.;

    // Compute r squared and denominator
    double r2 = x*x + y*y;

    // If r2 is zero GSL does not like it
    if (r2 == 0.) r2 = 1e-100;

    double denominator = 4. * M_PI * k * T * (m + 1.);

    // If you check in the thesis this part is common to
    // both formulas
    double numerator = gsl_sf_expint_Ei(
        -r2/(4.*k*t)
    );

    // Compute numerator
    if (t > T) {
        numerator -= gsl_sf_expint_Ei(
            -r2/(4.*k*(t-T))
        );
    }

    return numerator/denominator;
}

double ion_charge_function(double x, double y, double l_x, double l_y, double k, double t, double m, double T) {
    // Static so you don't waste a ton of time recreating the same function
    static TF2 f("testF1", charge_density_function, -max_x_size, max_x_size, -max_y_size, max_y_size, 4);

    // Setup function as we would want
    f.SetParameter(0, k);
    f.SetParameter(1, t);
    f.SetParameter(2, m);
    f.SetParameter(3, T);

    // Compute integral
    return f.Integral(
        x - l_x/2.,
        x + l_x/2.,
        y - l_y/2.,
        y + l_y/2.
    );
}