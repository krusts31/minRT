Matrix44 transpose() const 
{ 
    Matrix44 transpMat; 
    for (uint8_t i = 0; i < 4; ++i) { 
        for (uint8_t j = 0; j < 4; ++j) { 
            transpMat[i][j] = m[j][i]; 
        } 
    } 
 
    return transpMat; 
} 
