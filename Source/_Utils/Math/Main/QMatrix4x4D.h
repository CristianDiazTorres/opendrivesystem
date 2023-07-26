/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QMATRIX4X4D_H
#define QMATRIX4X4D_H

#include "Math/Internal/Internal.h"
#include <QtGui/qtguiglobal.h>
#include <QtGui/qvector3d.h>
#include <QtGui/qvector4d.h>
#include <QtGui/qquaternion.h>
#include <QtGui/qgenericmatrix.h>
#include <QtCore/qrect.h>

#ifndef QT_NO_MATRIX4X4D

class QMatrix;
class QTransform;
class QVariant;

class QMatrix4x4D
{
public:
    inline QMatrix4x4D() { setToIdentity(); }
    explicit QMatrix4x4D(Qt::Initialization) : flagBits(General) {}
    explicit QMatrix4x4D(const double *values);
    inline QMatrix4x4D(double m11, double m12, double m13, double m14,
                       double m21, double m22, double m23, double m24,
                       double m31, double m32, double m33, double m34,
                       double m41, double m42, double m43, double m44);

    template <int N, int M>
    explicit QMatrix4x4D(const QGenericMatrix<N, M, double>& matrix);

    QMatrix4x4D(const double *values, int cols, int rows);
    QMatrix4x4D(const QTransform& transform);
    QMatrix4x4D(const QMatrix& matrix);

    inline const double& operator()(int row, int column) const;
    inline double& operator()(int row, int column);

#ifndef QT_NO_VECTOR4D
    inline QVector4D column(int index) const;
    inline void setColumn(int index, const QVector4D& value);

    inline QVector4D row(int index) const;
    inline void setRow(int index, const QVector4D& value);
#endif

    inline bool isAffine() const;

    inline bool isIdentity() const;
    inline void setToIdentity();

    inline void fill(double value);

    double determinant() const;
    QMatrix4x4D inverted(bool *invertible = Q_NULLPTR) const;
    QMatrix4x4D transposed() const;
    QMatrix3x3 normalMatrix() const;

    inline QMatrix4x4D& operator+=(const QMatrix4x4D& other);
    inline QMatrix4x4D& operator-=(const QMatrix4x4D& other);
    inline QMatrix4x4D& operator*=(const QMatrix4x4D& other);
    inline QMatrix4x4D& operator*=(double factor);
    QMatrix4x4D& operator/=(double divisor);
    inline bool operator==(const QMatrix4x4D& other) const;
    inline bool operator!=(const QMatrix4x4D& other) const;

    friend QMatrix4x4D operator+(const QMatrix4x4D& m1, const QMatrix4x4D& m2);
    friend QMatrix4x4D operator-(const QMatrix4x4D& m1, const QMatrix4x4D& m2);
    friend QMatrix4x4D operator*(const QMatrix4x4D& m1, const QMatrix4x4D& m2);
#ifndef QT_NO_VECTOR3D
    friend QVector3D operator*(const QMatrix4x4D& matrix, const QVector3D& vector);
    friend QVector3D operator*(const QVector3D& vector, const QMatrix4x4D& matrix);
#endif
#ifndef QT_NO_VECTOR4D
    friend QVector4D operator*(const QVector4D& vector, const QMatrix4x4D& matrix);
    friend QVector4D operator*(const QMatrix4x4D& matrix, const QVector4D& vector);
#endif
    friend QPoint operator*(const QPoint& point, const QMatrix4x4D& matrix);
    friend QPointF operator*(const QPointF& point, const QMatrix4x4D& matrix);
    friend QMatrix4x4D operator-(const QMatrix4x4D& matrix);
    friend QPoint operator*(const QMatrix4x4D& matrix, const QPoint& point);
    friend QPointF operator*(const QMatrix4x4D& matrix, const QPointF& point);
    friend QMatrix4x4D operator*(double factor, const QMatrix4x4D& matrix);
    friend QMatrix4x4D operator*(const QMatrix4x4D& matrix, double factor);
    friend QMatrix4x4D operator/(const QMatrix4x4D& matrix, double divisor);

    friend inline bool qFuzzyCompare(const QMatrix4x4D& m1, const QMatrix4x4D& m2);

#ifndef QT_NO_VECTOR3D
    void scale(const QVector3D& vector);
    void translate(const QVector3D& vector);
    void rotate(double angle, const QVector3D& vector);
#endif
    void scale(double x, double y);
    void scale(double x, double y, double z);
    void scale(double factor);
    void translate(double x, double y);
    void translate(double x, double y, double z);
    void rotate(double angle, double x, double y, double z = 0.0f);
#ifndef QT_NO_QUATERNION
    void rotate(const QQuaternion& quaternion);
#endif

    void ortho(const QRect& rect);
    void ortho(const QRectF& rect);
    void ortho(double left, double right, double bottom, double top, double nearPlane, double farPlane);
    void frustum(double left, double right, double bottom, double top, double nearPlane, double farPlane);
    void perspective(double verticalAngle, double aspectRatio, double nearPlane, double farPlane);
#ifndef QT_NO_VECTOR3D
    void lookAt(const QVector3D& eye, const QVector3D& center, const QVector3D& up);
#endif
    void viewport(const QRectF &rect);
    void viewport(double left, double bottom, double width, double height, double nearPlane = 0.0f, double farPlane = 1.0f);
    void flipCoordinates();

    void copyDataTo(double *values) const;

    QMatrix toAffine() const;
    QTransform toTransform() const;
    QTransform toTransform(double distanceToPlane) const;

    QPoint map(const QPoint& point) const;
    QPointF map(const QPointF& point) const;
#ifndef QT_NO_VECTOR3D
    QVector3D map(const QVector3D& point) const;
    QVector3D mapVector(const QVector3D& vector) const;
#endif
#ifndef QT_NO_VECTOR4D
    QVector4D map(const QVector4D& point) const;
#endif
    QRect mapRect(const QRect& rect) const;
    QRectF mapRect(const QRectF& rect) const;

    template <int N, int M>
    QGenericMatrix<N, M, double> toGenericMatrix() const;

    inline double *data();
    inline const double *data() const { return *m; }
    inline const double *constData() const { return *m; }

    void optimize();

    operator QVariant() const;

#ifndef QT_NO_DEBUG_STREAM
    friend QDebug operator<<(QDebug dbg, const QMatrix4x4D &m);
#endif

private:
    double m[4][4];          // Column-major order to match OpenGL.
    int flagBits;           // Flag bits from the enum below.

    // When matrices are multiplied, the flag bits are or-ed together.
    enum {
        Identity        = 0x0000, // Identity matrix
        Translation     = 0x0001, // Contains a translation
        Scale           = 0x0002, // Contains a scale
        Rotation2D      = 0x0004, // Contains a rotation about the Z axis
        Rotation        = 0x0008, // Contains an arbitrary rotation
        Perspective     = 0x0010, // Last row is different from (0, 0, 0, 1)
        General         = 0x001f  // General matrix, unknown contents
    };

    // Construct without initializing identity matrix.
    explicit QMatrix4x4D(int) { }

    QMatrix4x4D orthonormalInverse() const;

    void projectedRotate(double angle, double x, double y, double z);

    friend class QGraphicsRotation;
};

QT_WARNING_PUSH
QT_WARNING_DISABLE_CLANG("-Wfloat-equal")
QT_WARNING_DISABLE_GCC("-Wfloat-equal")
Q_DECLARE_TYPEINFO(QMatrix4x4D, Q_MOVABLE_TYPE);

inline QMatrix4x4D::QMatrix4x4D
(double m11, double m12, double m13, double m14,
 double m21, double m22, double m23, double m24,
 double m31, double m32, double m33, double m34,
 double m41, double m42, double m43, double m44)
{
    m[0][0] = m11; m[0][1] = m21; m[0][2] = m31; m[0][3] = m41;
    m[1][0] = m12; m[1][1] = m22; m[1][2] = m32; m[1][3] = m42;
    m[2][0] = m13; m[2][1] = m23; m[2][2] = m33; m[2][3] = m43;
    m[3][0] = m14; m[3][1] = m24; m[3][2] = m34; m[3][3] = m44;
    flagBits = General;
}

template <int N, int M>
Q_INLINE_TEMPLATE QMatrix4x4D::QMatrix4x4D
(const QGenericMatrix<N, M, double>& matrix)
{
    const double *values = matrix.constData();
    for (int matrixCol = 0; matrixCol < 4; ++matrixCol) {
        for (int matrixRow = 0; matrixRow < 4; ++matrixRow) {
            if (matrixCol < N && matrixRow < M)
                m[matrixCol][matrixRow] = values[matrixCol * M + matrixRow];
            else if (matrixCol == matrixRow)
                m[matrixCol][matrixRow] = 1.0f;
            else
                m[matrixCol][matrixRow] = 0.0f;
        }
    }
    flagBits = General;
}

template <int N, int M>
QGenericMatrix<N, M, double> QMatrix4x4D::toGenericMatrix() const
{
    QGenericMatrix<N, M, double> result;
    double *values = result.data();
    for (int matrixCol = 0; matrixCol < N; ++matrixCol) {
        for (int matrixRow = 0; matrixRow < M; ++matrixRow) {
            if (matrixCol < 4 && matrixRow < 4)
                values[matrixCol * M + matrixRow] = m[matrixCol][matrixRow];
            else if (matrixCol == matrixRow)
                values[matrixCol * M + matrixRow] = 1.0f;
            else
                values[matrixCol * M + matrixRow] = 0.0f;
        }
    }
    return result;
}

inline const double& QMatrix4x4D::operator()(int aRow, int aColumn) const
{
    Q_ASSERT(aRow >= 0 && aRow < 4 && aColumn >= 0 && aColumn < 4);
    return m[aColumn][aRow];
}

inline double& QMatrix4x4D::operator()(int aRow, int aColumn)
{
    Q_ASSERT(aRow >= 0 && aRow < 4 && aColumn >= 0 && aColumn < 4);
    flagBits = General;
    return m[aColumn][aRow];
}

#ifndef QT_NO_VECTOR4D
inline QVector4D QMatrix4x4D::column(int index) const
{
    Q_ASSERT(index >= 0 && index < 4);
    return QVector4D(m[index][0], m[index][1], m[index][2], m[index][3]);
}

inline void QMatrix4x4D::setColumn(int index, const QVector4D& value)
{
    Q_ASSERT(index >= 0 && index < 4);
    m[index][0] = value.x();
    m[index][1] = value.y();
    m[index][2] = value.z();
    m[index][3] = value.w();
    flagBits = General;
}

inline QVector4D QMatrix4x4D::row(int index) const
{
    Q_ASSERT(index >= 0 && index < 4);
    return QVector4D(m[0][index], m[1][index], m[2][index], m[3][index]);
}

inline void QMatrix4x4D::setRow(int index, const QVector4D& value)
{
    Q_ASSERT(index >= 0 && index < 4);
    m[0][index] = value.x();
    m[1][index] = value.y();
    m[2][index] = value.z();
    m[3][index] = value.w();
    flagBits = General;
}
#endif

QMatrix4x4D operator/(const QMatrix4x4D& matrix, double divisor);

inline bool QMatrix4x4D::isAffine() const
{
    return m[0][3] == 0.0f && m[1][3] == 0.0f && m[2][3] == 0.0f && m[3][3] == 1.0f;
}

inline bool QMatrix4x4D::isIdentity() const
{
    if (flagBits == Identity)
        return true;
    if (m[0][0] != 1.0f || m[0][1] != 0.0f || m[0][2] != 0.0f)
        return false;
    if (m[0][3] != 0.0f || m[1][0] != 0.0f || m[1][1] != 1.0f)
        return false;
    if (m[1][2] != 0.0f || m[1][3] != 0.0f || m[2][0] != 0.0f)
        return false;
    if (m[2][1] != 0.0f || m[2][2] != 1.0f || m[2][3] != 0.0f)
        return false;
    if (m[3][0] != 0.0f || m[3][1] != 0.0f || m[3][2] != 0.0f)
        return false;
    return (m[3][3] == 1.0f);
}

inline void QMatrix4x4D::setToIdentity()
{
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    flagBits = Identity;
}

inline void QMatrix4x4D::fill(double value)
{
    m[0][0] = value;
    m[0][1] = value;
    m[0][2] = value;
    m[0][3] = value;
    m[1][0] = value;
    m[1][1] = value;
    m[1][2] = value;
    m[1][3] = value;
    m[2][0] = value;
    m[2][1] = value;
    m[2][2] = value;
    m[2][3] = value;
    m[3][0] = value;
    m[3][1] = value;
    m[3][2] = value;
    m[3][3] = value;
    flagBits = General;
}

inline QMatrix4x4D& QMatrix4x4D::operator+=(const QMatrix4x4D& other)
{
    m[0][0] += other.m[0][0];
    m[0][1] += other.m[0][1];
    m[0][2] += other.m[0][2];
    m[0][3] += other.m[0][3];
    m[1][0] += other.m[1][0];
    m[1][1] += other.m[1][1];
    m[1][2] += other.m[1][2];
    m[1][3] += other.m[1][3];
    m[2][0] += other.m[2][0];
    m[2][1] += other.m[2][1];
    m[2][2] += other.m[2][2];
    m[2][3] += other.m[2][3];
    m[3][0] += other.m[3][0];
    m[3][1] += other.m[3][1];
    m[3][2] += other.m[3][2];
    m[3][3] += other.m[3][3];
    flagBits = General;
    return *this;
}

inline QMatrix4x4D& QMatrix4x4D::operator-=(const QMatrix4x4D& other)
{
    m[0][0] -= other.m[0][0];
    m[0][1] -= other.m[0][1];
    m[0][2] -= other.m[0][2];
    m[0][3] -= other.m[0][3];
    m[1][0] -= other.m[1][0];
    m[1][1] -= other.m[1][1];
    m[1][2] -= other.m[1][2];
    m[1][3] -= other.m[1][3];
    m[2][0] -= other.m[2][0];
    m[2][1] -= other.m[2][1];
    m[2][2] -= other.m[2][2];
    m[2][3] -= other.m[2][3];
    m[3][0] -= other.m[3][0];
    m[3][1] -= other.m[3][1];
    m[3][2] -= other.m[3][2];
    m[3][3] -= other.m[3][3];
    flagBits = General;
    return *this;
}

inline QMatrix4x4D& QMatrix4x4D::operator*=(const QMatrix4x4D& o)
{
    const QMatrix4x4D other = o; // prevent aliasing when &o == this ### Qt 6: take o by value
    flagBits |= other.flagBits;

    if (flagBits < Rotation2D) {
        m[3][0] += m[0][0] * other.m[3][0];
        m[3][1] += m[1][1] * other.m[3][1];
        m[3][2] += m[2][2] * other.m[3][2];

        m[0][0] *= other.m[0][0];
        m[1][1] *= other.m[1][1];
        m[2][2] *= other.m[2][2];
        return *this;
    }

    double m0, m1, m2;
    m0 = m[0][0] * other.m[0][0]
            + m[1][0] * other.m[0][1]
            + m[2][0] * other.m[0][2]
            + m[3][0] * other.m[0][3];
    m1 = m[0][0] * other.m[1][0]
            + m[1][0] * other.m[1][1]
            + m[2][0] * other.m[1][2]
            + m[3][0] * other.m[1][3];
    m2 = m[0][0] * other.m[2][0]
            + m[1][0] * other.m[2][1]
            + m[2][0] * other.m[2][2]
            + m[3][0] * other.m[2][3];
    m[3][0] = m[0][0] * other.m[3][0]
            + m[1][0] * other.m[3][1]
            + m[2][0] * other.m[3][2]
            + m[3][0] * other.m[3][3];
    m[0][0] = m0;
    m[1][0] = m1;
    m[2][0] = m2;

    m0 = m[0][1] * other.m[0][0]
            + m[1][1] * other.m[0][1]
            + m[2][1] * other.m[0][2]
            + m[3][1] * other.m[0][3];
    m1 = m[0][1] * other.m[1][0]
            + m[1][1] * other.m[1][1]
            + m[2][1] * other.m[1][2]
            + m[3][1] * other.m[1][3];
    m2 = m[0][1] * other.m[2][0]
            + m[1][1] * other.m[2][1]
            + m[2][1] * other.m[2][2]
            + m[3][1] * other.m[2][3];
    m[3][1] = m[0][1] * other.m[3][0]
            + m[1][1] * other.m[3][1]
            + m[2][1] * other.m[3][2]
            + m[3][1] * other.m[3][3];
    m[0][1] = m0;
    m[1][1] = m1;
    m[2][1] = m2;

    m0 = m[0][2] * other.m[0][0]
            + m[1][2] * other.m[0][1]
            + m[2][2] * other.m[0][2]
            + m[3][2] * other.m[0][3];
    m1 = m[0][2] * other.m[1][0]
            + m[1][2] * other.m[1][1]
            + m[2][2] * other.m[1][2]
            + m[3][2] * other.m[1][3];
    m2 = m[0][2] * other.m[2][0]
            + m[1][2] * other.m[2][1]
            + m[2][2] * other.m[2][2]
            + m[3][2] * other.m[2][3];
    m[3][2] = m[0][2] * other.m[3][0]
            + m[1][2] * other.m[3][1]
            + m[2][2] * other.m[3][2]
            + m[3][2] * other.m[3][3];
    m[0][2] = m0;
    m[1][2] = m1;
    m[2][2] = m2;

    m0 = m[0][3] * other.m[0][0]
            + m[1][3] * other.m[0][1]
            + m[2][3] * other.m[0][2]
            + m[3][3] * other.m[0][3];
    m1 = m[0][3] * other.m[1][0]
            + m[1][3] * other.m[1][1]
            + m[2][3] * other.m[1][2]
            + m[3][3] * other.m[1][3];
    m2 = m[0][3] * other.m[2][0]
            + m[1][3] * other.m[2][1]
            + m[2][3] * other.m[2][2]
            + m[3][3] * other.m[2][3];
    m[3][3] = m[0][3] * other.m[3][0]
            + m[1][3] * other.m[3][1]
            + m[2][3] * other.m[3][2]
            + m[3][3] * other.m[3][3];
    m[0][3] = m0;
    m[1][3] = m1;
    m[2][3] = m2;
    return *this;
}

inline QMatrix4x4D& QMatrix4x4D::operator*=(double factor)
{
    m[0][0] *= factor;
    m[0][1] *= factor;
    m[0][2] *= factor;
    m[0][3] *= factor;
    m[1][0] *= factor;
    m[1][1] *= factor;
    m[1][2] *= factor;
    m[1][3] *= factor;
    m[2][0] *= factor;
    m[2][1] *= factor;
    m[2][2] *= factor;
    m[2][3] *= factor;
    m[3][0] *= factor;
    m[3][1] *= factor;
    m[3][2] *= factor;
    m[3][3] *= factor;
    flagBits = General;
    return *this;
}

inline bool QMatrix4x4D::operator==(const QMatrix4x4D& other) const
{
    return m[0][0] == other.m[0][0] &&
            m[0][1] == other.m[0][1] &&
            m[0][2] == other.m[0][2] &&
            m[0][3] == other.m[0][3] &&
            m[1][0] == other.m[1][0] &&
            m[1][1] == other.m[1][1] &&
            m[1][2] == other.m[1][2] &&
            m[1][3] == other.m[1][3] &&
            m[2][0] == other.m[2][0] &&
            m[2][1] == other.m[2][1] &&
            m[2][2] == other.m[2][2] &&
            m[2][3] == other.m[2][3] &&
            m[3][0] == other.m[3][0] &&
            m[3][1] == other.m[3][1] &&
            m[3][2] == other.m[3][2] &&
            m[3][3] == other.m[3][3];
}

inline bool QMatrix4x4D::operator!=(const QMatrix4x4D& other) const
{
    return m[0][0] != other.m[0][0] ||
            m[0][1] != other.m[0][1] ||
            m[0][2] != other.m[0][2] ||
            m[0][3] != other.m[0][3] ||
            m[1][0] != other.m[1][0] ||
            m[1][1] != other.m[1][1] ||
            m[1][2] != other.m[1][2] ||
            m[1][3] != other.m[1][3] ||
            m[2][0] != other.m[2][0] ||
            m[2][1] != other.m[2][1] ||
            m[2][2] != other.m[2][2] ||
            m[2][3] != other.m[2][3] ||
            m[3][0] != other.m[3][0] ||
            m[3][1] != other.m[3][1] ||
            m[3][2] != other.m[3][2] ||
            m[3][3] != other.m[3][3];
}

inline QMatrix4x4D operator+(const QMatrix4x4D& m1, const QMatrix4x4D& m2)
{
    QMatrix4x4D m(1);
    m.m[0][0] = m1.m[0][0] + m2.m[0][0];
    m.m[0][1] = m1.m[0][1] + m2.m[0][1];
    m.m[0][2] = m1.m[0][2] + m2.m[0][2];
    m.m[0][3] = m1.m[0][3] + m2.m[0][3];
    m.m[1][0] = m1.m[1][0] + m2.m[1][0];
    m.m[1][1] = m1.m[1][1] + m2.m[1][1];
    m.m[1][2] = m1.m[1][2] + m2.m[1][2];
    m.m[1][3] = m1.m[1][3] + m2.m[1][3];
    m.m[2][0] = m1.m[2][0] + m2.m[2][0];
    m.m[2][1] = m1.m[2][1] + m2.m[2][1];
    m.m[2][2] = m1.m[2][2] + m2.m[2][2];
    m.m[2][3] = m1.m[2][3] + m2.m[2][3];
    m.m[3][0] = m1.m[3][0] + m2.m[3][0];
    m.m[3][1] = m1.m[3][1] + m2.m[3][1];
    m.m[3][2] = m1.m[3][2] + m2.m[3][2];
    m.m[3][3] = m1.m[3][3] + m2.m[3][3];
    m.flagBits = QMatrix4x4D::General;
    return m;
}

inline QMatrix4x4D operator-(const QMatrix4x4D& m1, const QMatrix4x4D& m2)
{
    QMatrix4x4D m(1);
    m.m[0][0] = m1.m[0][0] - m2.m[0][0];
    m.m[0][1] = m1.m[0][1] - m2.m[0][1];
    m.m[0][2] = m1.m[0][2] - m2.m[0][2];
    m.m[0][3] = m1.m[0][3] - m2.m[0][3];
    m.m[1][0] = m1.m[1][0] - m2.m[1][0];
    m.m[1][1] = m1.m[1][1] - m2.m[1][1];
    m.m[1][2] = m1.m[1][2] - m2.m[1][2];
    m.m[1][3] = m1.m[1][3] - m2.m[1][3];
    m.m[2][0] = m1.m[2][0] - m2.m[2][0];
    m.m[2][1] = m1.m[2][1] - m2.m[2][1];
    m.m[2][2] = m1.m[2][2] - m2.m[2][2];
    m.m[2][3] = m1.m[2][3] - m2.m[2][3];
    m.m[3][0] = m1.m[3][0] - m2.m[3][0];
    m.m[3][1] = m1.m[3][1] - m2.m[3][1];
    m.m[3][2] = m1.m[3][2] - m2.m[3][2];
    m.m[3][3] = m1.m[3][3] - m2.m[3][3];
    m.flagBits = QMatrix4x4D::General;
    return m;
}

inline QMatrix4x4D operator*(const QMatrix4x4D& m1, const QMatrix4x4D& m2)
{
    int flagBits = m1.flagBits | m2.flagBits;
    if (flagBits < QMatrix4x4D::Rotation2D) {
        QMatrix4x4D m = m1;
        m.m[3][0] += m.m[0][0] * m2.m[3][0];
        m.m[3][1] += m.m[1][1] * m2.m[3][1];
        m.m[3][2] += m.m[2][2] * m2.m[3][2];

        m.m[0][0] *= m2.m[0][0];
        m.m[1][1] *= m2.m[1][1];
        m.m[2][2] *= m2.m[2][2];
        m.flagBits = flagBits;
        return m;
    }

    QMatrix4x4D m(1);
    m.m[0][0] = m1.m[0][0] * m2.m[0][0]
            + m1.m[1][0] * m2.m[0][1]
            + m1.m[2][0] * m2.m[0][2]
            + m1.m[3][0] * m2.m[0][3];
    m.m[0][1] = m1.m[0][1] * m2.m[0][0]
            + m1.m[1][1] * m2.m[0][1]
            + m1.m[2][1] * m2.m[0][2]
            + m1.m[3][1] * m2.m[0][3];
    m.m[0][2] = m1.m[0][2] * m2.m[0][0]
            + m1.m[1][2] * m2.m[0][1]
            + m1.m[2][2] * m2.m[0][2]
            + m1.m[3][2] * m2.m[0][3];
    m.m[0][3] = m1.m[0][3] * m2.m[0][0]
            + m1.m[1][3] * m2.m[0][1]
            + m1.m[2][3] * m2.m[0][2]
            + m1.m[3][3] * m2.m[0][3];

    m.m[1][0] = m1.m[0][0] * m2.m[1][0]
            + m1.m[1][0] * m2.m[1][1]
            + m1.m[2][0] * m2.m[1][2]
            + m1.m[3][0] * m2.m[1][3];
    m.m[1][1] = m1.m[0][1] * m2.m[1][0]
            + m1.m[1][1] * m2.m[1][1]
            + m1.m[2][1] * m2.m[1][2]
            + m1.m[3][1] * m2.m[1][3];
    m.m[1][2] = m1.m[0][2] * m2.m[1][0]
            + m1.m[1][2] * m2.m[1][1]
            + m1.m[2][2] * m2.m[1][2]
            + m1.m[3][2] * m2.m[1][3];
    m.m[1][3] = m1.m[0][3] * m2.m[1][0]
            + m1.m[1][3] * m2.m[1][1]
            + m1.m[2][3] * m2.m[1][2]
            + m1.m[3][3] * m2.m[1][3];

    m.m[2][0] = m1.m[0][0] * m2.m[2][0]
            + m1.m[1][0] * m2.m[2][1]
            + m1.m[2][0] * m2.m[2][2]
            + m1.m[3][0] * m2.m[2][3];
    m.m[2][1] = m1.m[0][1] * m2.m[2][0]
            + m1.m[1][1] * m2.m[2][1]
            + m1.m[2][1] * m2.m[2][2]
            + m1.m[3][1] * m2.m[2][3];
    m.m[2][2] = m1.m[0][2] * m2.m[2][0]
            + m1.m[1][2] * m2.m[2][1]
            + m1.m[2][2] * m2.m[2][2]
            + m1.m[3][2] * m2.m[2][3];
    m.m[2][3] = m1.m[0][3] * m2.m[2][0]
            + m1.m[1][3] * m2.m[2][1]
            + m1.m[2][3] * m2.m[2][2]
            + m1.m[3][3] * m2.m[2][3];

    m.m[3][0] = m1.m[0][0] * m2.m[3][0]
            + m1.m[1][0] * m2.m[3][1]
            + m1.m[2][0] * m2.m[3][2]
            + m1.m[3][0] * m2.m[3][3];
    m.m[3][1] = m1.m[0][1] * m2.m[3][0]
            + m1.m[1][1] * m2.m[3][1]
            + m1.m[2][1] * m2.m[3][2]
            + m1.m[3][1] * m2.m[3][3];
    m.m[3][2] = m1.m[0][2] * m2.m[3][0]
            + m1.m[1][2] * m2.m[3][1]
            + m1.m[2][2] * m2.m[3][2]
            + m1.m[3][2] * m2.m[3][3];
    m.m[3][3] = m1.m[0][3] * m2.m[3][0]
            + m1.m[1][3] * m2.m[3][1]
            + m1.m[2][3] * m2.m[3][2]
            + m1.m[3][3] * m2.m[3][3];
    m.flagBits = flagBits;
    return m;
}

#ifndef QT_NO_VECTOR3D

inline QVector3D operator*(const QVector3D& vector, const QMatrix4x4D& matrix)
{
    double x, y, z, w;
    x = vector.x() * matrix.m[0][0] +
            vector.y() * matrix.m[0][1] +
            vector.z() * matrix.m[0][2] +
            matrix.m[0][3];
    y = vector.x() * matrix.m[1][0] +
            vector.y() * matrix.m[1][1] +
            vector.z() * matrix.m[1][2] +
            matrix.m[1][3];
    z = vector.x() * matrix.m[2][0] +
            vector.y() * matrix.m[2][1] +
            vector.z() * matrix.m[2][2] +
            matrix.m[2][3];
    w = vector.x() * matrix.m[3][0] +
            vector.y() * matrix.m[3][1] +
            vector.z() * matrix.m[3][2] +
            matrix.m[3][3];
    if (w == 1.0f)
        return QVector3D(x, y, z);
    else
        return QVector3D(x / w, y / w, z / w);
}

inline QVector3D operator*(const QMatrix4x4D& matrix, const QVector3D& vector)
{
    double x, y, z, w;
    if (matrix.flagBits == QMatrix4x4D::Identity) {
        return vector;
    } else if (matrix.flagBits < QMatrix4x4D::Rotation2D) {
        // Translation | Scale
        return QVector3D(vector.x() * matrix.m[0][0] + matrix.m[3][0],
                vector.y() * matrix.m[1][1] + matrix.m[3][1],
                vector.z() * matrix.m[2][2] + matrix.m[3][2]);
    } else if (matrix.flagBits < QMatrix4x4D::Rotation) {
        // Translation | Scale | Rotation2D
        return QVector3D(vector.x() * matrix.m[0][0] + vector.y() * matrix.m[1][0] + matrix.m[3][0],
                vector.x() * matrix.m[0][1] + vector.y() * matrix.m[1][1] + matrix.m[3][1],
                vector.z() * matrix.m[2][2] + matrix.m[3][2]);
    } else {
        x = vector.x() * matrix.m[0][0] +
                vector.y() * matrix.m[1][0] +
                vector.z() * matrix.m[2][0] +
                matrix.m[3][0];
        y = vector.x() * matrix.m[0][1] +
                vector.y() * matrix.m[1][1] +
                vector.z() * matrix.m[2][1] +
                matrix.m[3][1];
        z = vector.x() * matrix.m[0][2] +
                vector.y() * matrix.m[1][2] +
                vector.z() * matrix.m[2][2] +
                matrix.m[3][2];
        w = vector.x() * matrix.m[0][3] +
                vector.y() * matrix.m[1][3] +
                vector.z() * matrix.m[2][3] +
                matrix.m[3][3];
        if (w == 1.0f)
            return QVector3D(x, y, z);
        else
            return QVector3D(x / w, y / w, z / w);
    }
}

#endif

#ifndef QT_NO_VECTOR4D

inline QVector4D operator*(const QVector4D& vector, const QMatrix4x4D& matrix)
{
    double x, y, z, w;
    x = vector.x() * matrix.m[0][0] +
            vector.y() * matrix.m[0][1] +
            vector.z() * matrix.m[0][2] +
            vector.w() * matrix.m[0][3];
    y = vector.x() * matrix.m[1][0] +
            vector.y() * matrix.m[1][1] +
            vector.z() * matrix.m[1][2] +
            vector.w() * matrix.m[1][3];
    z = vector.x() * matrix.m[2][0] +
            vector.y() * matrix.m[2][1] +
            vector.z() * matrix.m[2][2] +
            vector.w() * matrix.m[2][3];
    w = vector.x() * matrix.m[3][0] +
            vector.y() * matrix.m[3][1] +
            vector.z() * matrix.m[3][2] +
            vector.w() * matrix.m[3][3];
    return QVector4D(x, y, z, w);
}

inline QVector4D operator*(const QMatrix4x4D& matrix, const QVector4D& vector)
{
    double x, y, z, w;
    x = vector.x() * matrix.m[0][0] +
            vector.y() * matrix.m[1][0] +
            vector.z() * matrix.m[2][0] +
            vector.w() * matrix.m[3][0];
    y = vector.x() * matrix.m[0][1] +
            vector.y() * matrix.m[1][1] +
            vector.z() * matrix.m[2][1] +
            vector.w() * matrix.m[3][1];
    z = vector.x() * matrix.m[0][2] +
            vector.y() * matrix.m[1][2] +
            vector.z() * matrix.m[2][2] +
            vector.w() * matrix.m[3][2];
    w = vector.x() * matrix.m[0][3] +
            vector.y() * matrix.m[1][3] +
            vector.z() * matrix.m[2][3] +
            vector.w() * matrix.m[3][3];
    return QVector4D(x, y, z, w);
}

#endif

inline QPoint operator*(const QPoint& point, const QMatrix4x4D& matrix)
{
    double xin, yin;
    double x, y, w;
    xin = point.x();
    yin = point.y();
    x = xin * matrix.m[0][0] +
            yin * matrix.m[0][1] +
            matrix.m[0][3];
    y = xin * matrix.m[1][0] +
            yin * matrix.m[1][1] +
            matrix.m[1][3];
    w = xin * matrix.m[3][0] +
            yin * matrix.m[3][1] +
            matrix.m[3][3];
    if (w == 1.0f)
        return QPoint(qRound(x), qRound(y));
    else
        return QPoint(qRound(x / w), qRound(y / w));
}

inline QPointF operator*(const QPointF& point, const QMatrix4x4D& matrix)
{
    double xin, yin;
    double x, y, w;
    xin = point.x();
    yin = point.y();
    x = xin * matrix.m[0][0] +
            yin * matrix.m[0][1] +
            matrix.m[0][3];
    y = xin * matrix.m[1][0] +
            yin * matrix.m[1][1] +
            matrix.m[1][3];
    w = xin * matrix.m[3][0] +
            yin * matrix.m[3][1] +
            matrix.m[3][3];
    if (w == 1.0f) {
        return QPointF(qreal(x), qreal(y));
    } else {
        return QPointF(qreal(x / w), qreal(y / w));
    }
}

inline QPoint operator*(const QMatrix4x4D& matrix, const QPoint& point)
{
    double xin, yin;
    double x, y, w;
    xin = point.x();
    yin = point.y();
    if (matrix.flagBits == QMatrix4x4D::Identity) {
        return point;
    } else if (matrix.flagBits < QMatrix4x4D::Rotation2D) {
        // Translation | Scale
        return QPoint(qRound(xin * matrix.m[0][0] + matrix.m[3][0]),
                qRound(yin * matrix.m[1][1] + matrix.m[3][1]));
    } else if (matrix.flagBits < QMatrix4x4D::Perspective) {
        return QPoint(qRound(xin * matrix.m[0][0] + yin * matrix.m[1][0] + matrix.m[3][0]),
                qRound(xin * matrix.m[0][1] + yin * matrix.m[1][1] + matrix.m[3][1]));
    } else {
        x = xin * matrix.m[0][0] +
                yin * matrix.m[1][0] +
                matrix.m[3][0];
        y = xin * matrix.m[0][1] +
                yin * matrix.m[1][1] +
                matrix.m[3][1];
        w = xin * matrix.m[0][3] +
                yin * matrix.m[1][3] +
                matrix.m[3][3];
        if (w == 1.0f)
            return QPoint(qRound(x), qRound(y));
        else
            return QPoint(qRound(x / w), qRound(y / w));
    }
}

inline QPointF operator*(const QMatrix4x4D& matrix, const QPointF& point)
{
    qreal xin, yin;
    qreal x, y, w;
    xin = point.x();
    yin = point.y();
    if (matrix.flagBits == QMatrix4x4D::Identity) {
        return point;
    } else if (matrix.flagBits < QMatrix4x4D::Rotation2D) {
        // Translation | Scale
        return QPointF(xin * qreal(matrix.m[0][0]) + qreal(matrix.m[3][0]),
                yin * qreal(matrix.m[1][1]) + qreal(matrix.m[3][1]));
    } else if (matrix.flagBits < QMatrix4x4D::Perspective) {
        return QPointF(xin * qreal(matrix.m[0][0]) + yin * qreal(matrix.m[1][0]) +
                qreal(matrix.m[3][0]),
                xin * qreal(matrix.m[0][1]) + yin * qreal(matrix.m[1][1]) +
                qreal(matrix.m[3][1]));
    } else {
        x = xin * qreal(matrix.m[0][0]) +
                yin * qreal(matrix.m[1][0]) +
                qreal(matrix.m[3][0]);
        y = xin * qreal(matrix.m[0][1]) +
                yin * qreal(matrix.m[1][1]) +
                qreal(matrix.m[3][1]);
        w = xin * qreal(matrix.m[0][3]) +
                yin * qreal(matrix.m[1][3]) +
                qreal(matrix.m[3][3]);
        if (w == 1.0) {
            return QPointF(qreal(x), qreal(y));
        } else {
            return QPointF(qreal(x / w), qreal(y / w));
        }
    }
}

inline QMatrix4x4D operator-(const QMatrix4x4D& matrix)
{
    QMatrix4x4D m(1);
    m.m[0][0] = -matrix.m[0][0];
    m.m[0][1] = -matrix.m[0][1];
    m.m[0][2] = -matrix.m[0][2];
    m.m[0][3] = -matrix.m[0][3];
    m.m[1][0] = -matrix.m[1][0];
    m.m[1][1] = -matrix.m[1][1];
    m.m[1][2] = -matrix.m[1][2];
    m.m[1][3] = -matrix.m[1][3];
    m.m[2][0] = -matrix.m[2][0];
    m.m[2][1] = -matrix.m[2][1];
    m.m[2][2] = -matrix.m[2][2];
    m.m[2][3] = -matrix.m[2][3];
    m.m[3][0] = -matrix.m[3][0];
    m.m[3][1] = -matrix.m[3][1];
    m.m[3][2] = -matrix.m[3][2];
    m.m[3][3] = -matrix.m[3][3];
    m.flagBits = QMatrix4x4D::General;
    return m;
}

inline QMatrix4x4D operator*(double factor, const QMatrix4x4D& matrix)
{
    QMatrix4x4D m(1);
    m.m[0][0] = matrix.m[0][0] * factor;
    m.m[0][1] = matrix.m[0][1] * factor;
    m.m[0][2] = matrix.m[0][2] * factor;
    m.m[0][3] = matrix.m[0][3] * factor;
    m.m[1][0] = matrix.m[1][0] * factor;
    m.m[1][1] = matrix.m[1][1] * factor;
    m.m[1][2] = matrix.m[1][2] * factor;
    m.m[1][3] = matrix.m[1][3] * factor;
    m.m[2][0] = matrix.m[2][0] * factor;
    m.m[2][1] = matrix.m[2][1] * factor;
    m.m[2][2] = matrix.m[2][2] * factor;
    m.m[2][3] = matrix.m[2][3] * factor;
    m.m[3][0] = matrix.m[3][0] * factor;
    m.m[3][1] = matrix.m[3][1] * factor;
    m.m[3][2] = matrix.m[3][2] * factor;
    m.m[3][3] = matrix.m[3][3] * factor;
    m.flagBits = QMatrix4x4D::General;
    return m;
}

inline QMatrix4x4D operator*(const QMatrix4x4D& matrix, double factor)
{
    QMatrix4x4D m(1);
    m.m[0][0] = matrix.m[0][0] * factor;
    m.m[0][1] = matrix.m[0][1] * factor;
    m.m[0][2] = matrix.m[0][2] * factor;
    m.m[0][3] = matrix.m[0][3] * factor;
    m.m[1][0] = matrix.m[1][0] * factor;
    m.m[1][1] = matrix.m[1][1] * factor;
    m.m[1][2] = matrix.m[1][2] * factor;
    m.m[1][3] = matrix.m[1][3] * factor;
    m.m[2][0] = matrix.m[2][0] * factor;
    m.m[2][1] = matrix.m[2][1] * factor;
    m.m[2][2] = matrix.m[2][2] * factor;
    m.m[2][3] = matrix.m[2][3] * factor;
    m.m[3][0] = matrix.m[3][0] * factor;
    m.m[3][1] = matrix.m[3][1] * factor;
    m.m[3][2] = matrix.m[3][2] * factor;
    m.m[3][3] = matrix.m[3][3] * factor;
    m.flagBits = QMatrix4x4D::General;
    return m;
}

inline bool qFuzzyCompare(const QMatrix4x4D& m1, const QMatrix4x4D& m2)
{
    return qFuzzyCompare(m1.m[0][0], m2.m[0][0]) &&
            qFuzzyCompare(m1.m[0][1], m2.m[0][1]) &&
            qFuzzyCompare(m1.m[0][2], m2.m[0][2]) &&
            qFuzzyCompare(m1.m[0][3], m2.m[0][3]) &&
            qFuzzyCompare(m1.m[1][0], m2.m[1][0]) &&
            qFuzzyCompare(m1.m[1][1], m2.m[1][1]) &&
            qFuzzyCompare(m1.m[1][2], m2.m[1][2]) &&
            qFuzzyCompare(m1.m[1][3], m2.m[1][3]) &&
            qFuzzyCompare(m1.m[2][0], m2.m[2][0]) &&
            qFuzzyCompare(m1.m[2][1], m2.m[2][1]) &&
            qFuzzyCompare(m1.m[2][2], m2.m[2][2]) &&
            qFuzzyCompare(m1.m[2][3], m2.m[2][3]) &&
            qFuzzyCompare(m1.m[3][0], m2.m[3][0]) &&
            qFuzzyCompare(m1.m[3][1], m2.m[3][1]) &&
            qFuzzyCompare(m1.m[3][2], m2.m[3][2]) &&
            qFuzzyCompare(m1.m[3][3], m2.m[3][3]);
}

inline QPoint QMatrix4x4D::map(const QPoint& point) const
{
    return *this * point;
}

inline QPointF QMatrix4x4D::map(const QPointF& point) const
{
    return *this * point;
}

#ifndef QT_NO_VECTOR3D

inline QVector3D QMatrix4x4D::map(const QVector3D& point) const
{
    return *this * point;
}

inline QVector3D QMatrix4x4D::mapVector(const QVector3D& vector) const
{
    if (flagBits < Scale) {
        // Translation
        return vector;
    } else if (flagBits < Rotation2D) {
        // Translation | Scale
        return QVector3D(vector.x() * m[0][0],
                vector.y() * m[1][1],
                vector.z() * m[2][2]);
    } else {
        return QVector3D(vector.x() * m[0][0] +
                vector.y() * m[1][0] +
                vector.z() * m[2][0],
                vector.x() * m[0][1] +
                vector.y() * m[1][1] +
                vector.z() * m[2][1],
                vector.x() * m[0][2] +
                vector.y() * m[1][2] +
                vector.z() * m[2][2]);
    }
}

#endif

#ifndef QT_NO_VECTOR4D

inline QVector4D QMatrix4x4D::map(const QVector4D& point) const
{
    return *this * point;
}

#endif

inline double *QMatrix4x4D::data()
{
    // We have to assume that the caller will modify the matrix elements,
    // so we flip it over to "General" mode.
    flagBits = General;
    return *m;
}

inline void QMatrix4x4D::viewport(const QRectF &rect)
{
    viewport(rect.x(), rect.y(), rect.width(), rect.height());
}

QT_WARNING_POP

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QMatrix4x4D &m);
#endif

#ifndef QT_NO_DATASTREAM
QDataStream &operator<<(QDataStream &, const QMatrix4x4D &);
QDataStream &operator>>(QDataStream &, QMatrix4x4D &);
#endif

#if QT_DEPRECATED_SINCE(5, 0)
template <int N, int M>
QT_DEPRECATED QMatrix4x4D qGenericMatrixToMatrix4x4(const QGenericMatrix<N, M, double>& matrix)
{
    return QMatrix4x4D(matrix.constData(), N, M);
}

template <int N, int M>
QT_DEPRECATED QGenericMatrix<N, M, double> qGenericMatrixFromMatrix4x4(const QMatrix4x4D& matrix)
{
    QGenericMatrix<N, M, double> result;
    const double *m = matrix.constData();
    double *values = result.data();
    for (int col = 0; col < N; ++col) {
        for (int row = 0; row < M; ++row) {
            if (col < 4 && row < 4)
                values[col * M + row] = m[col * 4 + row];
            else if (col == row)
                values[col * M + row] = 1.0f;
            else
                values[col * M + row] = 0.0f;
        }
    }
    return result;
}
#endif

#endif

#endif
