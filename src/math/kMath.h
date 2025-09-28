#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <stdint.h>

#define PI 3.141592653589793

    static float deg_to_radians(float deg){
        return deg * PI * 1 / 180;
    }



/*
=====================================================================================

VEC2

=====================================================================================
*/

template<typename T>
struct Vec2 {
    T x, y;

    Vec2() : x(0), y(0) {}
    Vec2(T _x, T _y) : x(_x), y(_y) {}
    ~Vec2() {}

    Vec2& add(const Vec2& another) {
        x += another.x;
        y += another.y;
        return *this;
    }

    Vec2& add(T scalar) {
        x += scalar;
        y += scalar;
        return *this;
    }

    Vec2& substract(const Vec2& another) {
        x -= another.x;
        y -= another.y;
        return *this;
    }

    Vec2& substract(T scalar) {
        x -= scalar;
        y -= scalar;
        return *this;
    }

    Vec2& multiply(const Vec2& another) {
        x *= another.x;
        y *= another.y;
        return *this;
    }

    Vec2& multiply(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2& divide(const Vec2& another) {
        x /= another.x;
        y /= another.y;
        return *this;
    }

    Vec2& divide(T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Vec2& operator+=(const Vec2& another) {
        return this->add(another);
    }

    Vec2& operator-=(const Vec2& another) {
        return this->substract(another);
    }

    Vec2& operator*=(const Vec2& another) {
        return this->multiply(another);
    }

    Vec2& operator/=(const Vec2& another) {
        return this->divide(another);
    }

    bool operator==(const Vec2& another) const {
        return x == another.x && y == another.y;
    }
};

template<typename T>
Vec2<T> operator+(const Vec2<T>& a, const Vec2<T>& b) {
    return Vec2<T>(a.x + b.x, a.y + b.y);
}

template<typename T>
Vec2<T> operator-(const Vec2<T>& a, const Vec2<T>& b) {
    return Vec2<T>(a.x - b.x, a.y - b.y);
}

template<typename T>
Vec2<T> operator*(const Vec2<T>& a, const Vec2<T>& b) {
    return Vec2<T>(a.x * b.x, a.y * b.y);
}

template<typename T>
Vec2<T> operator/(const Vec2<T>& a, const Vec2<T>& b) {
    return Vec2<T>(a.x / b.x, a.y / b.y);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec) {
    os << "Vec2(" << vec.x << ", " << vec.y << ")" << std::endl;
    return os;
}

/*
=====================================================================================

VEC3

=====================================================================================
*/

template<typename T>
struct Vec3 {
    T x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    ~Vec3() {}

    Vec3& add(const Vec3& another) {
        x += another.x;
        y += another.y;
        z += another.z;
        return *this;
    }

    Vec3& add(T scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
        return *this;
    }

    Vec3& substract(const Vec3& another) {
        x -= another.x;
        y -= another.y;
        z -= another.z;
        return *this;
    }

    Vec3& substract(T scalar) {
        x -= scalar;
        y -= scalar;
        z -= scalar;
        return *this;
    }

    Vec3& multiply(const Vec3& another) {
        x *= another.x;
        y *= another.y;
        z *= another.z;
        return *this;
    }

    Vec3& multiply(T scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3& divide(const Vec3& another) {
        x /= another.x;
        y /= another.y;
        z /= another.z;
        return *this;
    }

    Vec3& divide(T scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vec3& operator+=(const Vec3& another) {
        return this->add(another);
    }

    Vec3& operator-=(const Vec3& another) {
        return this->substract(another);
    }

    Vec3& operator*=(const Vec3& another) {
        return this->multiply(another);
    }

    Vec3& operator/=(const Vec3& another) {
        return this->divide(another);
    }

    bool operator==(const Vec3& another) const {
        return x == another.x && y == another.y && z == another.z;
    }
};

template<typename T>
Vec3<T> operator+(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
}

template<typename T>
Vec3<T> operator-(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
}

template<typename T>
Vec3<T> operator*(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a.x * b.x, a.y * b.y, a.z * b.z);
}

template<typename T>
Vec3<T> operator/(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(a.x / b.x, a.y / b.y, a.z / b.z);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec3<T>& vec) {
    os << "Vec3(" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;
    return os;
}


/*
=====================================================================================

VEC4

=====================================================================================
*/

template<typename T>
struct Vec4 {
    T x, y, z, w; 

    Vec4() : x(0), y(0), z(0), w(0) {}
    Vec4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
    ~Vec4() {}

    Vec4& add(const Vec4& another) {
        x += another.x;
        y += another.y;
        z += another.z;
        w += another.w;
        return *this;
    }

    Vec4& add(T scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
        w += scalar;
        return *this;
    }

    Vec4& substract(const Vec4& another) {
        x -= another.x;
        y -= another.y;
        z -= another.z;
        w -= another.w;
        return *this;
    }

    Vec4& substract(T scalar) {
        x -= scalar;
        y -= scalar;
        z -= scalar;
        w -= scalar;
        return *this;
    }

    Vec4& multiply(const Vec4& another) {
        x *= another.x;
        y *= another.y;
        z *= another.z;
        w *= another.w;
        return *this;
    }

    Vec4& multiply(T scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vec4& divide(const Vec4& another) {
        x /= another.x;
        y /= another.y;
        z /= another.z;
        w /= another.w;
        return *this;
    }

    Vec4& divide(T scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    Vec4& operator+=(const Vec4& another) {
        return this->add(another);
    }

    Vec4& operator-=(const Vec4& another) {
        return this->substract(another);
    }

    Vec4& operator*=(const Vec4& another) { // TODO
        return this->multiply(another);
    }

    Vec4& operator/=(const Vec4& another) {
        return this->divide(another);
    }

    bool operator==(const Vec4& another) const {
        return x == another.x && y == another.y && z == another.z && w == another.w;
    }
};

template<typename T>
Vec4<T> operator+(const Vec4<T>& a, const Vec4<T>& b) {
    return Vec4<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

template<typename T>
Vec4<T> operator-(const Vec4<T>& a, const Vec4<T>& b) {
    return Vec4<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

template<typename T>
Vec4<T> operator*(const Vec4<T>& a, const Vec4<T>& b) {
    return Vec4<T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

template<typename T>
Vec4<T> operator/(const Vec4<T>& a, const Vec4<T>& b) {
    return Vec4<T>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec4<T>& vec) {
    os << "Vec4(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")" << std::endl;
    return os;
}


/*
=====================================================================================

Matrix

=====================================================================================
*/

template<uint8_t nR, uint8_t nC, typename T>
struct Matrix
{
    T data[nR * nC];
    uint8_t n, m;

    Matrix(T* _data) {
        n = nR;
        m = nC;
        int size = sizeof(T) * n * m;
        if (_data != nullptr)
            memcpy(data, _data, size); 
        else {
            for (int i = 0; i < n * m; i++) {
                data[i] = (T)0;
            }
        }
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    Matrix operator +(T scalar) {
        Matrix<nR, nC, T> res = Matrix<nR, nC, T>(data);
        for (size_t i = 0; i < nR * nC; i++)
        {
            res[i] += scalar;
        }
        return res;
    }

    Matrix operator +(Matrix& another) {
        Matrix<nR, nC, T> res = Matrix<nR, nC, T>(data);
        for (uint8_t i = 0; i < nR * nC; i++) {
            res.data[i] = data[i] + another.data[i];
        }
        return res;
    }

    Matrix operator *(T scalar) {
        Matrix<nR, nC, T> res = Matrix<nR, nC, T>(data);
        for (size_t i = 0; i < nR * nC; i++)
        {
            res[i] *= scalar;
        }
        return res;
    }

    Matrix operator -(T scalar) {
        Matrix<nR, nC, T> res = Matrix<nR, nC, T>(data);
        for (size_t i = 0; i < nR * nC; i++)
        {
            res[i] -= scalar;
        }
        return res;
    }

    Matrix operator /(T scalar) {
        Matrix<nR, nC, T> res = Matrix<nR, nC, T>(data);
        for (size_t i = 0; i < nR * nC; i++)
        {
            res[i] /= scalar;
        }
        return res;
    }

    void operator +=(T scalar) {
        for (uint8_t i = 0; i < nR * nC; i++) {
            data[i] += scalar;
        }
    }

    void operator *=(T scalar) {
        for (uint8_t i = 0; i < nR * nC; i++) {
            data[i] *= scalar;
        }
    }

    Matrix operator *(Matrix& another) {
        Matrix<nR, nC, T> res = Matrix<nR, nC, T>(nullptr);
        for (uint8_t i = 0; i < nR; i++) {
            for (uint8_t j = 0; j < nR; j++) {
                T value = 0;
                for (uint8_t k = 0; k < m; k++) {
                    value += data[m * i + k] * another.data[j + k * nC];
                };
                res.data[i * nC + j] = value;
            }
        }
        return res;
    }

    static Matrix identity() {
        if (nR != nC) {
            std::cout << "Row != Columns, No identity Matrix" << std::endl;
            Matrix<nR, nC, T> empty(nullptr);
            return empty;
        }
        Matrix<nR, nC, T> res = Matrix<nR, nC, T>(nullptr);
        for (uint8_t i = 0; i < nR; i++) {
            res.data[i * nC + i] = 1; 
        }
        return res;
    }
};


/*
=====================================================================================

Matrix2

=====================================================================================
*/

template<typename T>
struct Matrix2 {
    T data[4];

    Matrix2(T diagonale) {
        data[0] = diagonale;
        data[1] = 0;
        data[2] = 0;
        data[3] = diagonale;
    }

    Matrix2 operator*(Matrix2& another) {
        Matrix2<T> res(0);
        // R0
        res.data[0] = data[0] * another.data[0] + data[1] * another.data[2];
        res.data[1] = data[0] * another.data[1] + data[1] * another.data[3];

        // R1
        res.data[2] = data[2] * another.data[0] + data[3] * another.data[2];
        res.data[3] = data[2] * another.data[1] + data[3] * another.data[3];

        return res; 
    }

    T det() {
        return data[0] * data[3] - data[1] * data[2];
    }
};


/*
=====================================================================================

Matrix3

=====================================================================================
*/

template<typename T>
struct Matrix3 {
    T data[3 * 3];

    Matrix3(T diagonale) {
        for (int i = 0; i < 9; i++) {
            data[i] = 0;
        }
        data[0] = diagonale;
        data[4] = diagonale;
        data[8] = diagonale;
    }

    Matrix3 operator*(Matrix3& another) {
        Matrix3<T> res(0);
        for (uint8_t i = 0; i < 3; i++) {
            for (uint8_t j = 0; j < 3; j++) {
                T value = 0;
                for (uint8_t k = 0; k < 3; k++) {
                    value += data[3 * i + k] * another.data[j + k * 3];
                }
                res.data[i * 3 + j] = value;
            }
        }
        return res;
    }

    T det() {
        T a = data[0] * (data[4] * data[8] - data[5] * data[7]);
        T b = data[1] * (data[3] * data[8] - data[5] * data[6]);
        T c = data[2] * (data[3] * data[7] - data[4] * data[6]);
        return a - b + c;
    }

    
};


/*
=====================================================================================

Matrix4

=====================================================================================
*/

template<typename T>
struct Matrix4 {
    T data[4 * 4];

    Matrix4(T diagonals) {
        for (int i = 0; i < 16; i++) {
            data[i] = 0;
        }
        data[0] = diagonals;
        data[5] = diagonals;
        data[10] = diagonals;
        data[15] = diagonals;
    }

    Matrix4 operator*(Matrix4 another) {
        Matrix4<T> res(0);
        for (uint8_t i = 0; i < 4; i++) {
            for (uint8_t j = 0; j < 4; j++) {
                T value = 0;
                for (uint8_t k = 0; k < 4; k++) {
                    value += data[4 * i + k] * another.data[j + k * 4];
                }
                res.data[i * 4 + j] = value;
            }
        }
        return res;
    }


    friend std::ostream& operator<<(std::ostream& os, Matrix4<T>& matrix) {
        for (int i = 0; i < 16; i++) {
            os << matrix.data[i] << " ";
            if ((i + 1) % 4 == 0 ) os << std::endl;
        }
        return os;
    }

    // TODO
    T det() {
        T a = data[0] * (data[4] * data[8] - data[5] * data[7]);
        T b = data[1] * (data[3] * data[8] - data[5] * data[6]);
        T c = data[2] * (data[3] * data[7] - data[4] * data[6]);
        return a - b + c;
    }

    Vec4<T> getColumn(uint8_t col) {
        if (col >= 4) return Vec4<T>(0, 0, 0, 0);
        return Vec4<T>(
            data[col * 4 + 0],
            data[col * 4 + 1],
            data[col * 4 + 2],
            data[col * 4 + 3]
        );
    }

    Vec4<T> getRow(uint8_t row) {
        if (row >= 4) return Vec4<T>(0, 0, 0, 0);

        return Vec4<T>(
            data[row * 4 + 0],
            data[row * 4 + 1],
            data[row * 4 + 2],
            data[row * 4 + 3]
        );
    }


    static Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far) { // pour rep un 3D obj en 2D obj
        Matrix4 res(0);
        res.data[0] = 2.0f / (right - left);
        res.data[5] = 2.0f / (top - bottom);
        res.data[10] = -2.0f / (far - near);
        res.data[15] = 1.0f;

        res.data[12] = -(right + left) / (right - left);
        res.data[13] = -(top + bottom) / (top - bottom);
        res.data[14] = -(far + near) / (far - near);

        return res;
    }

    static Matrix4 perspective(float fov, float aspectRatio, float near, float far) {
        Matrix4 res(1.0);
        float q = 1.0 / tan(deg_to_radians(fov) / 2.0f);
        float a = q / aspectRatio;

        float b = (near + far) / (near - far);
        float c = (2.0 * near * far) / (near - far);

        res.data[0 + 0 * 4] = a; 
        res.data[1 + 1 * 4] = q;
        res.data[2 + 2 * 4] = b;
        res.data[3 + 2 * 4] = -1;
        res.data[2 + 3 * 4] = c;

        return res;
    }

    static Matrix4 translation(Vec3<T>& vec) {
        Matrix4 res(1);
        res.data[0 + 3 * 4] = vec.x;
        res.data[1 + 3 * 4] = vec.y;
        res.data[2 + 3 * 4] = vec.z;
        return res;
    }

    static Matrix4 scale(Vec3<T>& scale) {
        Matrix4 res(1);
        res.data[0 + 0 * 4] = scale.x;
        res.data[1 + 1 * 4] = scale.y;
        res.data[2 + 2 * 4] = scale.z;
        return res;
    }

    static Matrix4 rotation(float angle, Vec3<T> axes) { // (1, 0, 0) for X, (0, 0, 1) for z etc
        Matrix4 res(1);
        float r = deg_to_radians(angle);
        float s = sin(r);
        float c = cos(r);

        float x = axes.x;
        float y = axes.y;
        float z = axes.z;

        res.data[0 + 0 * 4] = x * x * (1.0 - c) + c;
        res.data[1 + 0 * 4] = y * x * (1.0 - c) + z * s;
        res.data[2 + 0 * 4] = z * x * (1.0 - c) - y * s;

        res.data[0 + 1 * 4] = x * y * (1.0 - c) - z * s;
        res.data[1 + 1 * 4] = y * y *  (1.0 - c) + c;
        res.data[2 + 1 * 4] = z * y * (1.0 - c) + x * s;

        res.data[0 + 2 * 4] = x * z * (1.0 - c) + y * s;
        res.data[1 + 2 * 4] = y * z * (1.0 - c) - x * s;
        res.data[2 + 2 * 4] = z * z * (1.0 - c) + s;

        return res;
    }
};