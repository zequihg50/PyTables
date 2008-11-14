/* These functions are not included in some non-POSIX compilers,
  like MSVC 7.1  */


inline double log1p(double x)
{
    double u = 1. + x;
    if (u == 1.0) {
        return x;
    } else {
        return log(u) * x / (u-1.);
    }
}

inline static double expm1(double x)
{
    double u = exp(x);
    if (u == 1.0) {
        return x;
    } else if (u-1.0 == -1.0) {
        return -1;
    } else {
        return (u-1.0) * x/log(u);
    }
}

inline static double asinh(double xx)
{
    double x, d;
    int sign;
    if (xx < 0.0) {
        sign = -1;
        x = -xx;
    }
    else {
        sign = 1;
        x = xx;
    }
    if (x > 1e8) {
        d = x;
    } else {
        d = sqrt(x*x + 1);
    }
    return sign*log1p(x*(1.0 + x/(d+1)));
}

inline static double acosh(double x)
{
    return 2*log(sqrt((x+1.0)/2)+sqrt((x-1.0)/2));
}

inline static double atanh(double x)
{
    return 0.5*log((1.0+x)/(1.0-x));
}
