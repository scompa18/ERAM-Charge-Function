#include "ion_charge_function.h"
#include "gsl/gsl_specfunc.h"

double ion_charge_function(double x, double y, double l_x, double l_y, double k, double t, double m, double T) {
    return gsl_sf_expint_Ei(x);
}