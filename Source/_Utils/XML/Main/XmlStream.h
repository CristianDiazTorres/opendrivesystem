/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
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

#include <QtCore/qiodevice.h>

#ifndef QT_NO_XMLSTREAM

#include <QtCore/qstring.h>
#include <QtCore/qvector.h>
#include <QtCore/qscopedpointer.h>

QT_BEGIN_NAMESPACE


class XmlStreamStringRef {
    QString m_string;
    int m_position, m_size;
public:
    inline XmlStreamStringRef():m_position(0), m_size(0){}
    inline XmlStreamStringRef(const QStringRef &aString)
        :m_string(aString.string()?*aString.string():QString()), m_position(aString.position()), m_size(aString.size()){}
    XmlStreamStringRef(const QString &aString) : m_string(aString), m_position(0), m_size(m_string.size()) {}
#ifdef Q_COMPILER_RVALUE_REFS
    XmlStreamStringRef(QString &&aString) Q_DECL_NOTHROW : m_string(std::move(aString)), m_position(0), m_size(m_string.size()) {}
#endif

#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    XmlStreamStringRef(const XmlStreamStringRef &other) // = default
        : m_string(other.m_string), m_position(other.m_position), m_size(other.m_size) {}
#ifdef Q_COMPILER_RVALUE_REFS
    XmlStreamStringRef(XmlStreamStringRef &&other) Q_DECL_NOTHROW // = default
        : m_string(std::move(other.m_string)), m_position(other.m_position), m_size(other.m_size) {}
    XmlStreamStringRef &operator=(XmlStreamStringRef &&other) Q_DECL_NOTHROW // = default
    { swap(other); return *this; }
#endif
    XmlStreamStringRef &operator=(const XmlStreamStringRef &other) // = default
    { m_string = other.m_string; m_position = other.m_position; m_size = other.m_size; return *this; }
    inline ~XmlStreamStringRef() {} // ### this prevents (or deprecates) all the move/copy special member functions,
                                     // ### that's why we need to provide them by hand above. We can't remove it in
                                     // ### Qt 5, since that would change the way its passed to functions. In Qt 6, remove all.
#endif // Qt < 6.0

    void swap(XmlStreamStringRef &other) Q_DECL_NOTHROW
    {
        qSwap(m_string, other.m_string);
        qSwap(m_position, other.m_position);
        qSwap(m_size, other.m_size);
    }

    inline void clear() { m_string.clear(); m_position = m_size = 0; }
    inline operator QStringRef() const { return QStringRef(&m_string, m_position, m_size); }
    inline const QString *string() const { return &m_string; }
    inline int position() const { return m_position; }
    inline int size() const { return m_size; }
};
Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6(XmlStreamStringRef)


class XmlStreamReaderPrivate;
class XmlStreamAttributes;
class XmlStreamAttribute {
    XmlStreamStringRef m_name, m_namespaceUri, m_qualifiedName, m_value;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    void *reserved;
#endif
    uint m_isDefault : 1;
    friend class XmlStreamReaderPrivate;
    friend class XmlStreamAttributes;
public:
    XmlStreamAttribute();
    XmlStreamAttribute(const QString &qualifiedName, const QString &value);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    XmlStreamAttribute(const QString &namespaceUri, const QString &name, const QString &value);
    XmlStreamAttribute(const XmlStreamAttribute &);
#ifdef Q_COMPILER_RVALUE_REFS
    XmlStreamAttribute(XmlStreamAttribute &&other) Q_DECL_NOTHROW // = default;
        : m_name(std::move(other.m_name)),
          m_namespaceUri(std::move(other.m_namespaceUri)),
          m_qualifiedName(std::move(other.m_qualifiedName)),
          m_value(std::move(other.m_value)),
          reserved(other.reserved),
          m_isDefault(other.m_isDefault)
    {
        other.reserved = Q_NULLPTR;
    }
    XmlStreamAttribute &operator=(XmlStreamAttribute &&other) Q_DECL_NOTHROW // = default;
    {
        m_name = std::move(other.m_name);
        m_namespaceUri = std::move(other.m_namespaceUri);
        m_qualifiedName = std::move(other.m_qualifiedName);
        m_value = std::move(other.m_value);
        qSwap(reserved, other.reserved);
        m_isDefault = other.m_isDefault;
        return *this;
    }
#endif
    XmlStreamAttribute& operator=(const XmlStreamAttribute &);
    ~XmlStreamAttribute();
#endif // < Qt 6

    inline QStringRef namespaceUri() const { return m_namespaceUri; }
    inline QStringRef name() const { return m_name; }
    inline QStringRef qualifiedName() const { return m_qualifiedName; }
    inline QStringRef prefix() const {
        return QStringRef(m_qualifiedName.string(),
                          m_qualifiedName.position(),
                          qMax(0, m_qualifiedName.size() - m_name.size() - 1));
    }
    inline QStringRef value() const { return m_value; }
    inline bool isDefault() const { return m_isDefault; }
    inline bool operator==(const XmlStreamAttribute &other) const {
        return (value() == other.value()
                && (namespaceUri().isNull() ? (qualifiedName() == other.qualifiedName())
                    : (namespaceUri() == other.namespaceUri() && name() == other.name())));
    }
    inline bool operator!=(const XmlStreamAttribute &other) const
        { return !operator==(other); }
};

Q_DECLARE_TYPEINFO(XmlStreamAttribute, Q_MOVABLE_TYPE);

class XmlStreamAttributes : public QVector<XmlStreamAttribute>
{
public:
    inline XmlStreamAttributes() {}
    QStringRef value(const QString &namespaceUri, const QString &name) const;
    QStringRef value(const QString &namespaceUri, QLatin1String name) const;
    QStringRef value(QLatin1String namespaceUri, QLatin1String name) const;
    QStringRef value(const QString &qualifiedName) const;
    QStringRef value(QLatin1String qualifiedName) const;
    void append(const QString &namespaceUri, const QString &name, const QString &value);
    void append(const QString &qualifiedName, const QString &value);

    inline bool hasAttribute(const QString &qualifiedName) const
    {
        return !value(qualifiedName).isNull();
    }

    inline bool hasAttribute(QLatin1String qualifiedName) const
    {
        return !value(qualifiedName).isNull();
    }

    inline bool hasAttribute(const QString &namespaceUri, const QString &name) const
    {
        return !value(namespaceUri, name).isNull();
    }

    using QVector<XmlStreamAttribute>::append;
};

class XmlStreamNamespaceDeclaration {
    XmlStreamStringRef m_prefix, m_namespaceUri;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    void *reserved;
#endif

    friend class XmlStreamReaderPrivate;
public:
    XmlStreamNamespaceDeclaration();
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    XmlStreamNamespaceDeclaration(const XmlStreamNamespaceDeclaration &);
    XmlStreamNamespaceDeclaration(XmlStreamNamespaceDeclaration &&other) Q_DECL_NOTHROW // = default
        : m_prefix(std::move(other.m_prefix)),
          m_namespaceUri(std::move(other.m_namespaceUri)),
          reserved(other.reserved)
    {
        other.reserved = nullptr;
    }
    XmlStreamNamespaceDeclaration &operator=(XmlStreamNamespaceDeclaration &&other) Q_DECL_NOTHROW // = default
    {
        m_prefix = std::move(other.m_prefix);
        m_namespaceUri = std::move(other.m_namespaceUri);
        qSwap(reserved, other.reserved);
        return *this;
    }
    XmlStreamNamespaceDeclaration(const QString &prefix, const QString &namespaceUri);
    ~XmlStreamNamespaceDeclaration();
    XmlStreamNamespaceDeclaration& operator=(const XmlStreamNamespaceDeclaration &);
#endif // < Qt 6

    inline QStringRef prefix() const { return m_prefix; }
    inline QStringRef namespaceUri() const { return m_namespaceUri; }
    inline bool operator==(const XmlStreamNamespaceDeclaration &other) const {
        return (prefix() == other.prefix() && namespaceUri() == other.namespaceUri());
    }
    inline bool operator!=(const XmlStreamNamespaceDeclaration &other) const
        { return !operator==(other); }
};

Q_DECLARE_TYPEINFO(XmlStreamNamespaceDeclaration, Q_MOVABLE_TYPE);
typedef QVector<XmlStreamNamespaceDeclaration> XmlStreamNamespaceDeclarations;

class XmlStreamNotationDeclaration {
    XmlStreamStringRef m_name, m_systemId, m_publicId;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    void *reserved;
#endif

    friend class XmlStreamReaderPrivate;
public:
    XmlStreamNotationDeclaration();
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    ~XmlStreamNotationDeclaration();
    XmlStreamNotationDeclaration(const XmlStreamNotationDeclaration &);
    XmlStreamNotationDeclaration(XmlStreamNotationDeclaration &&other) Q_DECL_NOTHROW // = default
        : m_name(std::move(other.m_name)),
          m_systemId(std::move(other.m_systemId)),
          m_publicId(std::move(other.m_publicId)),
          reserved(other.reserved)
    {
        other.reserved = nullptr;
    }
    XmlStreamNotationDeclaration& operator=(const XmlStreamNotationDeclaration &);
    XmlStreamNotationDeclaration &operator=(XmlStreamNotationDeclaration &&other) Q_DECL_NOTHROW // = default
    {
        m_name = std::move(other.m_name);
        m_systemId = std::move(other.m_systemId);
        m_publicId = std::move(other.m_publicId);
        qSwap(reserved, other.reserved);
        return *this;
    }
#endif // < Qt 6

    inline QStringRef name() const { return m_name; }
    inline QStringRef systemId() const { return m_systemId; }
    inline QStringRef publicId() const { return m_publicId; }
    inline bool operator==(const XmlStreamNotationDeclaration &other) const {
        return (name() == other.name() && systemId() == other.systemId()
                && publicId() == other.publicId());
    }
    inline bool operator!=(const XmlStreamNotationDeclaration &other) const
        { return !operator==(other); }
};

Q_DECLARE_TYPEINFO(XmlStreamNotationDeclaration, Q_MOVABLE_TYPE);
typedef QVector<XmlStreamNotationDeclaration> XmlStreamNotationDeclarations;

class XmlStreamEntityDeclaration {
    XmlStreamStringRef m_name, m_notationName, m_systemId, m_publicId, m_value;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    void *reserved;
#endif

    friend class XmlStreamReaderPrivate;
public:
    XmlStreamEntityDeclaration();
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    ~XmlStreamEntityDeclaration();
    XmlStreamEntityDeclaration(const XmlStreamEntityDeclaration &);
    XmlStreamEntityDeclaration(XmlStreamEntityDeclaration &&other) Q_DECL_NOTHROW // = default
        : m_name(std::move(other.m_name)),
          m_notationName(std::move(other.m_notationName)),
          m_systemId(std::move(other.m_systemId)),
          m_publicId(std::move(other.m_publicId)),
          m_value(std::move(other.m_value)),
          reserved(other.reserved)
    {
        other.reserved = nullptr;
    }
    XmlStreamEntityDeclaration& operator=(const XmlStreamEntityDeclaration &);
    XmlStreamEntityDeclaration &operator=(XmlStreamEntityDeclaration &&other) Q_DECL_NOTHROW // = default
    {
        m_name = std::move(other.m_name);
        m_notationName = std::move(other.m_notationName);
        m_systemId = std::move(other.m_systemId);
        m_publicId = std::move(other.m_publicId);
        m_value = std::move(other.m_value);
        qSwap(reserved, other.reserved);
        return *this;
    }
#endif // < Qt 6

    inline QStringRef name() const { return m_name; }
    inline QStringRef notationName() const { return m_notationName; }
    inline QStringRef systemId() const { return m_systemId; }
    inline QStringRef publicId() const { return m_publicId; }
    inline QStringRef value() const { return m_value; }
    inline bool operator==(const XmlStreamEntityDeclaration &other) const {
        return (name() == other.name()
                && notationName() == other.notationName()
                && systemId() == other.systemId()
                && publicId() == other.publicId()
                && value() == other.value());
    }
    inline bool operator!=(const XmlStreamEntityDeclaration &other) const
        { return !operator==(other); }
};

Q_DECLARE_TYPEINFO(XmlStreamEntityDeclaration, Q_MOVABLE_TYPE);
typedef QVector<XmlStreamEntityDeclaration> XmlStreamEntityDeclarations;


class XmlStreamEntityResolver
{
public:
    virtual ~XmlStreamEntityResolver();
    virtual QString resolveEntity(const QString& publicId, const QString& systemId);
    virtual QString resolveUndeclaredEntity(const QString &name);
};

#ifndef QT_NO_XMLSTREAMREADER
class XmlStreamReader {
    QDOC_PROPERTY(bool namespaceProcessing READ namespaceProcessing WRITE setNamespaceProcessing)
public:
    enum TokenType {
        NoToken = 0,
        Invalid,
        StartDocument,
        EndDocument,
        StartElement,
        EndElement,
        Characters,
        Comment,
        DTD,
        EntityReference,
        ProcessingInstruction
    };


    XmlStreamReader();
    explicit XmlStreamReader(QIODevice *device);
    explicit XmlStreamReader(const QByteArray &data);
    explicit XmlStreamReader(const QString &data);
    explicit XmlStreamReader(const char * data);
    ~XmlStreamReader();

    void setDevice(QIODevice *device);
    QIODevice *device() const;
    void addData(const QByteArray &data);
    void addData(const QString &data);
    void addData(const char *data);
    void clear();


    bool atEnd() const;
    TokenType readNext();

    bool readNextStartElement();
    void skipCurrentElement();

    TokenType tokenType() const;
    QString tokenString() const;

    void setNamespaceProcessing(bool);
    bool namespaceProcessing() const;

    inline bool isStartDocument() const { return tokenType() == StartDocument; }
    inline bool isEndDocument() const { return tokenType() == EndDocument; }
    inline bool isStartElement() const { return tokenType() == StartElement; }
    inline bool isEndElement() const { return tokenType() == EndElement; }
    inline bool isCharacters() const { return tokenType() == Characters; }
    bool isWhitespace() const;
    bool isCDATA() const;
    inline bool isComment() const { return tokenType() == Comment; }
    inline bool isDTD() const { return tokenType() == DTD; }
    inline bool isEntityReference() const { return tokenType() == EntityReference; }
    inline bool isProcessingInstruction() const { return tokenType() == ProcessingInstruction; }

    bool isStandaloneDocument() const;
    QStringRef documentVersion() const;
    QStringRef documentEncoding() const;

    qint64 lineNumber() const;
    qint64 columnNumber() const;
    qint64 characterOffset() const;

    XmlStreamAttributes attributes() const;

    enum ReadElementTextBehaviour {
        ErrorOnUnexpectedElement,
        IncludeChildElements,
        SkipChildElements
    };
    QString readElementText(ReadElementTextBehaviour behaviour = ErrorOnUnexpectedElement);

    QStringRef name() const;
    QStringRef namespaceUri() const;
    QStringRef qualifiedName() const;
    QStringRef prefix() const;

    QStringRef processingInstructionTarget() const;
    QStringRef processingInstructionData() const;

    QStringRef text() const;

    XmlStreamNamespaceDeclarations namespaceDeclarations() const;
    void addExtraNamespaceDeclaration(const XmlStreamNamespaceDeclaration &extraNamespaceDeclaraction);
    void addExtraNamespaceDeclarations(const XmlStreamNamespaceDeclarations &extraNamespaceDeclaractions);
    XmlStreamNotationDeclarations notationDeclarations() const;
    XmlStreamEntityDeclarations entityDeclarations() const;
    QStringRef dtdName() const;
    QStringRef dtdPublicId() const;
    QStringRef dtdSystemId() const;


    enum Error {
        NoError,
        UnexpectedElementError,
        CustomError,
        NotWellFormedError,
        PrematureEndOfDocumentError
    };
    void raiseError(const QString& message = QString());
    QString errorString() const;
    Error error() const;

    inline bool hasError() const
    {
        return error() != NoError;
    }

    void setEntityResolver(XmlStreamEntityResolver *resolver);
    XmlStreamEntityResolver *entityResolver() const;

private:
    Q_DISABLE_COPY(XmlStreamReader)
    Q_DECLARE_PRIVATE(XmlStreamReader)
    QScopedPointer<XmlStreamReaderPrivate> d_ptr;

};
#endif // QT_NO_XMLSTREAMREADER

#ifndef QT_NO_XMLSTREAMWRITER

class XmlStreamWriterPrivate;

class XmlStreamWriter
{
    QDOC_PROPERTY(bool autoFormatting READ autoFormatting WRITE setAutoFormatting)
    QDOC_PROPERTY(int autoFormattingIndent READ autoFormattingIndent WRITE setAutoFormattingIndent)
public:
    XmlStreamWriter();
    explicit XmlStreamWriter(QIODevice *device);
    explicit XmlStreamWriter(QByteArray *array);
    explicit XmlStreamWriter(QString *string);
    ~XmlStreamWriter();

    void setDevice(QIODevice *device);
    QIODevice *device() const;

#ifndef QT_NO_TEXTCODEC
    void setCodec(QTextCodec *codec);
    void setCodec(const char *codecName);
    QTextCodec *codec() const;
#endif

    void setAutoFormatting(bool);
    bool autoFormatting() const;

    void setAutoFormattingIndent(int spacesOrTabs);
    int autoFormattingIndent() const;

    void writeAttribute(const QString &qualifiedName, const QString &value);
    void writeAttribute(const QString &namespaceUri, const QString &name, const QString &value);
    void writeAttribute(const XmlStreamAttribute& attribute);
    void writeAttributes(const XmlStreamAttributes& attributes);

    void writeCDATA(const QString &text);
    void writeCharacters(const QString &text);
    void writeComment(const QString &text);

    void writeDTD(const QString &dtd);

    void writeEmptyElement(const QString &qualifiedName);
    void writeEmptyElement(const QString &namespaceUri, const QString &name);

    void writeTextElement(const QString &qualifiedName, const QString &text);
    void writeTextElement(const QString &namespaceUri, const QString &name, const QString &text);

    void writeEndDocument();
    void writeEndElement();

    void writeEntityReference(const QString &name);
    void writeNamespace(const QString &namespaceUri, const QString &prefix = QString());
    void writeDefaultNamespace(const QString &namespaceUri);
    void writeProcessingInstruction(const QString &target, const QString &data = QString());

    void writeStartDocument();
    void writeStartDocument(const QString &version);
    void writeStartDocument(const QString &version, bool standalone);
    void writeStartElement(const QString &qualifiedName);
    void writeStartElement(const QString &namespaceUri, const QString &name);

#ifndef QT_NO_XMLSTREAMREADER
    void writeCurrentToken(const XmlStreamReader &reader);
#endif

    bool hasError() const;

private:
    Q_DISABLE_COPY(XmlStreamWriter)
    Q_DECLARE_PRIVATE(XmlStreamWriter)
    QScopedPointer<XmlStreamWriterPrivate> d_ptr;
};
#endif // QT_NO_XMLSTREAMWRITER

QT_END_NAMESPACE

#endif // QT_NO_XMLSTREAM
