#ifndef __COMMON_H__
#define __COMMON_H__

#include <QString>
#include <QVector>
#include <QMap>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QDomElement>

#define RADIAN_IN_DEGREE		0.01745329251994329576923690768489
#define DEGREE_IN_RADIAN		57.295779513082320876798154814105

#define DEG_TO_RAD(x)           ((x) * RADIAN_IN_DEGREE)
#define RAD_TO_DEG(x)           ((x) * DEGREE_IN_RADIAN)

#define CONST                   const
#define ConstQMap               CONST QMap
#define MyCout                  qDebug()
#define MyEndl                  "\n"
#define EigenMatrix             Eigen::Matrix

typedef CONST void				ConstVoid;
typedef CONST bool				ConstBool;
typedef CONST int				ConstInt;
typedef CONST uint8_t			ConstUInt8;
typedef CONST size_t			ConstSizeT;
typedef CONST char				ConstChar;
typedef CONST wchar_t			ConstWChar;
typedef CONST QString			ConstQString;
typedef CONST QString			ConstQString;
typedef std::exception          MyException;
typedef CONST MyException		ConstMyException;
typedef QVector<double>         DoubleVec;
typedef CONST DoubleVec			ConstDoubleVec;
typedef QVector<QString>		QStringVec;
typedef CONST QStringVec		ConstQStringVec;
typedef QVector<uint8_t>		uint8vec;
typedef CONST uint8vec			ConstUInt8Vec;

typedef CONST QJsonValue		ConstQJsonValue;
typedef CONST QJsonArray		ConstQJsonArray;
typedef CONST QJsonObject		ConstQJsonObject;

namespace Common
{
    template <typename T>
    inline QJsonArray ToQJsonArrayOfObject(const QVector<T>& data)
    {
        QJsonArray result;
        for (int i = 0; i < data.size(); i++)
            result.append((QJsonObject)data[i]);
        return result;
    }

    template <typename T>
    inline QJsonArray ToQJsonArrayOfArray(const QVector<T>& data)
    {
        QJsonArray result;
        for (int i = 0; i < data.size(); i++)
            result.append((QJsonArray)data[i]);
        return result;
    }

#define DOM_SUCCESS 0
#define DOM_FAILED 1

    class DomElement : public QDomElement
    {
    public:
        DomElement(){}

        DomElement(const QDomElement& other)
            : QDomElement(other)
        {
        }

        int QueryStringAttribute(const QString& attr_name, QString* out_value) const
        {
            if (!hasAttribute(attr_name))
                return DOM_FAILED;
            *out_value = attribute(attr_name);
            return DOM_SUCCESS;
        }

        int QueryBoolAttribute(const QString& attr_name, bool* out_value) const
        {
            if (!hasAttribute(attr_name))
                return DOM_FAILED;
            *out_value = attribute(attr_name) == "true";
            return DOM_SUCCESS;
        }

        int QueryIntAttribute(const QString& attr_name, int* out_value) const
        {
            if (!hasAttribute(attr_name))
                return DOM_FAILED;
            *out_value = attribute(attr_name).toInt();
            return DOM_SUCCESS;
        }

        int QueryFloatAttribute(const QString& attr_name, float* out_value) const
        {
            if (!hasAttribute(attr_name))
                return DOM_FAILED;
            *out_value = attribute(attr_name).toFloat();
            return DOM_SUCCESS;
        }

        int QueryDoubleAttribute(const QString& attr_name, double* out_value) const
        {
            if (!hasAttribute(attr_name))
                return DOM_FAILED;
            *out_value = attribute(attr_name).toDouble();
            return DOM_SUCCESS;
        }

        void setBoolAttribute(const QString& attr_name, bool value)
        {
            if (value)
                setAttribute(attr_name, "true");
            else
                setAttribute(attr_name, "false");
        }

        void setDoubleAttribute(const QString& attr_name, double value)
        {
            QString str = QString::number(value, 'e', 16);
            int e_pos = str.indexOf('e');
            if (e_pos >= 0 && e_pos == str.size() - 3)
                str.insert(str.size() - 1, "0");
            setAttribute(attr_name, str);
        }
    };
}

// const
// CONST
// std
// QVector
// namespace
// using
// ' '

#endif // __COMMON_H__
