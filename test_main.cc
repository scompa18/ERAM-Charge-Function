#include <iostream>
#include <TF1.h>
#include <TCanvas.h>
#include <TApplication.h>

using namespace std;

int main(int argc, char *argv[]) {
    TApplication theApp("test_main", &argc, argv);

    cout << "This is a test" << endl;
    
    TF1 f("testF1", "sin(x)", 0., 10.);

    TCanvas c;
    f.Draw();

    theApp.Run();

    return 0;
}
