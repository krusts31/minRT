template<typename T> 
Vec3<T> sphericalToCartesian(const T &theta, const T &phi) 
{ 
    return Vec3<T>(cos(phi) * sin(theta), sin(phi) * sin(theta), cos(theta)); 
};
