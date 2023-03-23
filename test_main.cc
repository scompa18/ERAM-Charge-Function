#include <iostream>
#include <TF2.h>
#include <TCanvas.h>
#include <TApplication.h>
#include "ion_charge_function.h"

using namespace std;

int main(int argc, char *argv[]) {
    TApplication theApp("test_main", &argc, argv);

    cout << "This is a test" << endl;
    
    TF2 f("testF1", charge_density_function, -4., 4., -4., 4., 4);
    f.SetNpx(1000);
    f.SetNpy(1000);
    f.SetParameter(0, 1.);
    f.SetParameter(1, 0.1+4.);
    f.SetParameter(2, 0.);
    f.SetParameter(3, 1.);

    TCanvas c;
    f.Draw("colz");

    theApp.Run();

    return 0;
}
