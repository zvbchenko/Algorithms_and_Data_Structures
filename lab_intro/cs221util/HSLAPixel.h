#ifndef CS221UTIL_HSLAPixel_H
#define CS221UTIL_HSLAPixel_H
namespace cs221util {
    class HSLAPixel{
    public:
        HSLAPixel();
        HSLAPixel(double hue, double saturation, double luminance);
        HSLAPixel(double hue, double saturation, double luminance, double alpha);
        double h;
        double s;
        double l;
        double a;
    };
    
    }
#endif