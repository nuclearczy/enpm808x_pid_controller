#include <PID.h>
#include <iostream>

int main() {
    PID pid1(2);
    PID pid2(2, 2);
    PID pid3(2, 2, 2);    
    PID pid4(2, 2, 2, 2);    

    return 0;
}
