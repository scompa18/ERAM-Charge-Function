#include "ion_charge_function.h"
#include "gsl/gsl_specfunc.h"
#include <cmath>

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
    return gsl_sf_expint_Ei(x);
}