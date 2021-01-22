template<typename T> 
class Vec3 
{ 
public: 
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {} 
    T x, y, z, w; 
}; 
 
template<typename T> 
class Matrix44 
{ 
public: 
    T m[4][4]; 
    Vec3<T> multVecMatrix(const Vec3<T> &v) 
    { 
#ifdef ROWMAJOR 
        return Vec3<T>( 
            v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0], 
            v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1], 
            v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2]); 
#else 
        return Vec3<T>( 
            v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2], 
            v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2], 
            v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2]); 
#endif 
    } 
}; 
 
#include <cmath> 
#include <cstdlib> 
#include <cstdio> 
#include <ctime> 
 
#define MAX_ITER 10e8 
//#define ROWMAJOR
 
int main(int argc, char **argv) 
{ 
    clock_t start = clock(); 
    Vec3<float> v(1, 2, 3); 
    Matrix44<float> M; 
    float *tmp = &M.m[0][0]; 
    for (int i = 0; i < 16; i++) *(tmp + i) = drand48(); 
    for (int i = 0; i < MAX_ITER; ++i) { 
        Vec3<float> vt = M.multVecMatrix(v); 
    } 
    fprintf(stderr, "Clock time %f\n", (clock() - start) / float(CLOCKS_PER_SEC)); 
    return 0; 
} 
