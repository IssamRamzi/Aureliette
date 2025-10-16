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
    Vec2(T v) : x(v), y(v) {}
    Vec2(T _x, T _y) : x(_x), y(_y) {}
    ~Vec2() {}

    static const Vec2<T> ZERO;
    static const Vec2<T> ONE;


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

    Vec2& operator=(const Vec2& another) {
        x = another.x, y = another.y;
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

    double dot(Vec2 another) {
        return x*another.x + y*another.y;
    }

    static double dot(Vec2 vec1, Vec2 vec2) {
        return vec1.x*vec2.x + vec1.y*vec2.y;
    }

    double length() {
        return sqrt(x*x + y*y);
    }

    static double length(Vec2 vec) {
        return sqrt(vec.x*vec.x + vec.y*vec.y);
    }

    Vec2 normalize() const{
        double l = length();
        x /= l, y /= l;
        return *this;
    }

    static Vec2 normalize(Vec2 vec) {
        double l = length(vec);
        vec.x /= l, vec.y /= l;
        return vec;
    }

    double distance(Vec2 vec) {
        return length(vec - *this);
    }

    static double distance(Vec2 vec, Vec2 vec2) {
        return length(vec - vec2);
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

template<typename T>
const Vec2<T> Vec2<T>::ZERO = {0,0};
template<typename T>
const Vec2<T> Vec2<T>::ONE = {1,1};

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

    static const Vec3<T> ZERO;
    static const Vec3<T> ONE;
    static const Vec3<T> UP;
    static const Vec3<T> DOWN;
    static const Vec3<T> LEFT;
    static const Vec3<T> RIGHT;
    static const Vec3<T> FORWARD;
    static const Vec3<T> BACK;

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

    Vec3& operator=(const Vec3& another) {
        x = another.x, y = another.y, z = another.z;
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

    double dot(Vec3 another) {
        return x*another.x + y*another.y + z*another.z;
    }

    static double dot(Vec3 vec1, Vec3 vec2) {
        return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
    }

    double length() {
        return sqrt(x*x + y*y + z*z);
    }

    static double length(Vec3 v) {
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    }

    Vec3 normalize() {
        double l = length();
        x /= l, y /= l, z /= l;
        return *this;
    }

    static Vec3 normalize(Vec3 v) {
        float l = length(v);
        return {v.x / l, v.y / l, v.z / l};
    }

    double distance(Vec3 vec) {
        return length(vec - *this);
    }

    static double distance(Vec3 vec, Vec3 vec2) {
        return length(vec - vec2);
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

template<typename T>
const Vec3<T> Vec3<T>::ZERO = {0,0,0};
template<typename T>
const Vec3<T> Vec3<T>::ONE = {1,1,1};
template<typename T>
const Vec3<T> Vec3<T>::UP = {0,1,0};
template<typename T>
const Vec3<T> Vec3<T>::DOWN = {0, -1, 0};
template<typename T>
const Vec3<T> Vec3<T>::LEFT = {-1, 0, 0};
template<typename T>
const Vec3<T> Vec3<T>::RIGHT = {1, 0, 0};
template<typename T>
const Vec3<T> Vec3<T>::FORWARD = {0,0,1};
template<typename T>
const Vec3<T> Vec3<T>::BACK = {0,0,-1};


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

    static const Vec4<T> ZERO;
    static const Vec4<T> ONE;

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

    Vec4& operator=(const Vec4& another) {
        x = another.x, y = another.y, z = another.z, w = another.w;
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

    double dot(Vec4 another) {
        return x*another.x + y*another.y + z*another.z + w*another.w;
    }

    static double dot(Vec4 vec1, Vec4 vec2) {
        return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z + vec1.w*vec2.w;
    }

    double length() {
        return sqrt(x*x + y*y + z*z + w*w);
    }

    static double length(Vec4 v) {
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
    }

    Vec4 normalize() {
        double l = length();
        x /= l, y /= l, z /= l, w /= l;
        return *this;
    }

    static Vec4 normalize(Vec4 v) {
        float length = length(v);
        return {v.x / length, v.y / length, v.z / length, v.w / length};
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

template<typename T>
const Vec4<T> Vec4<T>::ZERO = {0,0,0,0};
template<typename T>
const Vec4<T> Vec4<T>::ONE = {1,1,1,1};


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

    T det() {
        T a = data[0] * (
        data[5] * (data[10] * data[15] - data[11] * data[14]) -
        data[6] * (data[9] * data[15] - data[11] * data[13]) +
        data[7] * (data[9] * data[14] - data[10] * data[13])
        );
        T b = data[1] * (
            data[4] * (data[10] * data[15] - data[11] * data[14]) -
            data[6] * (data[8] * data[15] - data[11] * data[12]) +
            data[7] * (data[8] * data[14] - data[10] * data[12])
        );
        T c = data[2] * (
            data[4] * (data[9] * data[15] - data[11] * data[13]) -
            data[5] * (data[8] * data[15] - data[11] * data[12]) +
            data[7] * (data[8] * data[13] - data[9] * data[12])
        );
        T d = data[3] * (
            data[4] * (data[9] * data[14] - data[10] * data[13]) -
            data[5] * (data[8] * data[14] - data[10] * data[12]) +
            data[6] * (data[8] * data[13] - data[9] * data[12])
        );

        return a - b + c - d;
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

    static Matrix4 rotation(float angle, Vec3<T> axes) { // (1, 0, 0) pr X, (0, 0, 1) pr z etc
        // TODO axes = Vec3<T>::normalize(axes);
        Matrix4 res(1);
        float r = deg_to_radians(angle);
        float s = sin(r);
        float c = cos(r);

        float x = axes.x;
        float y = axes.y;
        float z = axes.z;

        res.data[0] = x * x * (1 - c) + c;
        res.data[1] = x * y * (1 - c) - z * s;
        res.data[2] = x * z * (1 - c) + y * s;

        res.data[0 + 4] = x * y * (1 - c) + z * s;
        res.data[1 + 4] = c + y * y * (1 - c);
        res.data[2 + 4] = y * z * (1 - c) - x * s;

        res.data[0 + 8] = x * z * (1 - c) - y * s;
        res.data[1 + 8] = z * y * (1 - c) + x * s;
        res.data[2 + 8] = c + z * z * (1 - c);

        return res;
    }

};
