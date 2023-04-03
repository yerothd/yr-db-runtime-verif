/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a src/YRruntimeverification_adaptor yr.db-runtime.verif.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef YRRUNTIMEVERIFICATION_ADAPTOR_H
#define YRRUNTIMEVERIFICATION_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE class QByteArray;
template < class T > class QList;
template < class Key, class Value > class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE
/*
 * Adaptor class for interface com.yeroth.rd.IYRruntimeverification
 */
class IYRruntimeverificationAdaptor:public QDBusAbstractAdaptor
{
Q_OBJECT Q_CLASSINFO("D-Bus Interface", "com.yeroth.rd.IYRruntimeverification") Q_CLASSINFO("D-Bus Introspection", "" "  <interface name=\"com.yeroth.rd.IYRruntimeverification\">\n" "    <method name=\"YR_slot_refresh_INSERT_DB_MYSQL\">\n" "      <annotation value=\"QString\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n" "      <annotation value=\"uint\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n" "      <annotation value=\"bool\" name=\"org.qtproject.QtDBus.QtTypeName.In2\"/>\n" "      <arg direction=\"in\" type=\"QString\"/>\n" "      <arg direction=\"in\" type=\"uint\"/>\n" "      <arg direction=\"out\" type=\"bool\"/>\n" "    </method>\n" "    <method name=\"YR_slot_refresh_SELECT_DB_MYSQL\">\n" "      <annotation value=\"QString\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n" "      <annotation value=\"uint\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n" "      <annotation value=\"bool\" name=\"org.qtproject.QtDBus.QtTypeName.In2\"/>\n" "      <arg direction=\"in\" type=\"QString\"/>\n" "      <arg direction=\"in\" type=\"uint\"/>\n" "      <arg direction=\"out\" type=\"bool\"/>\n" "    </method>\n" "    <method name=\"YR_slot_refresh_UPDATE_DB_MYSQL\">\n" "      <annotation value=\"QString\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n" "      <annotation value=\"uint\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n" "      <annotation value=\"bool\" name=\"org.qtproject.QtDBus.QtTypeName.In2\"/>\n" "      <arg direction=\"in\" type=\"QString\"/>\n" "      <arg direction=\"in\" type=\"uint\"/>\n" "      <arg direction=\"out\" type=\"bool\"/>\n" "    </method>\n" "    <method name=\"YR_slot_refresh_DELETE_DB_MYSQL\">\n" "      <annotation value=\"QString\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n" "      <annotation value=\"uint\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n" "      <annotation value=\"bool\" name=\"org.qtproject.QtDBus.QtTypeName.In2\"/>\n" "      <arg direction=\"in\" type=\"QString\"/>\n" "      <arg direction=\"in\" type=\"uint\"/>\n" "      <arg direction=\"out\" type=\"bool\"/>\n" "    </method>\n" "  </interface>\n" "") public:
    IYRruntimeverificationAdaptor(QObject *
                                  parent);
    virtual ~ IYRruntimeverificationAdaptor();

public:			// PROPERTIES
public Q_SLOTS:		// METHODS
    bool YR_slot_refresh_DELETE_DB_MYSQL(const QString &in0, uint in1);
    bool YR_slot_refresh_INSERT_DB_MYSQL(const QString &in0, uint in1);
    bool YR_slot_refresh_SELECT_DB_MYSQL(const QString &in0, uint in1);
    bool YR_slot_refresh_UPDATE_DB_MYSQL(const QString &in0, uint in1);
Q_SIGNALS:			// SIGNALS
};

#endif
