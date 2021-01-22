Matrix44 operator * (const Matrix44& rhs) const 
{ 
    Matrix44 mult; 
    for (uint8_t i = 0; i < 4; ++i) { 
        for (uint8_t j = 0; j < 4; ++j) { 
            mult[i][j] = m[i][0] * rhs[0][j] + 
                         m[i][1] * rhs[1][j] + 
                         m[i][2] * rhs[2][j] + 
                         m[i][3] * rhs[3][j]; 
        } 
    } 
 
    return mult; 
}
