#include "pxt.h"
#include "math.h"

using namespace pxt;

namespace QMC5883L {
    //%
    int cpp_division(int x, int _x, int y, int _y){
        int counta = 0;
        int a = _x;
        int countb = 0;
        int b = _y;
        while(a!=0) {
            a/=10;
            counta++;
        }
        while(b!=0) {
            b/=10;
            countb++;
        }
        float xx = _x / pow(10, counta);
        float yy = _y / pow(10, countb);
        xx = x + xx;
        yy = y + yy;

        int heading = 180.0 * atan2(yy, xx) / 3.14159265358979323846264338327950288;
        heading = heading < 0 ? heading + 360 : heading;
        return heading;
    }

}

