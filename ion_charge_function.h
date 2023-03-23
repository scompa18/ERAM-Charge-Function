#ifndef ion_charge_function_h
#define ion_charge_function_h

/*
* The function is structured as follows:
* x,y are the coordinates of the deposited charge w.r.t. the center of the pad
* l_x and l_y are the size of the pad along the x and y axis
* k is 1/RC
* t is the time since the deposition of the charge
* m is the geometric factor, see L. Scomparin master thesis page 52
* T is the ion drift time
*/

double ion_charge_function(double x, double y, double l_x, double l_y, double k, double t, double m, double T);

#endif