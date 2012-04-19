/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSystems module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qservicerequest_p.h"

// Default constructor - required by meta-type system - note that we could just
// fall back on the one automatically created by the compiler but let's be
// explicit so no mistakes are made - eg, does m_reply get set to zero?
QServiceRequest::QServiceRequest()
    : m_reply(0), m_type(DefaultInterfaceRequest)
{
    // nothing to do here
}

QServiceRequest::QServiceRequest(const QString &interfaceName)
    : m_interfaceName(interfaceName),
      m_reply(0),
      m_type(DefaultInterfaceRequest)
{
    // nothing to do here
}

QServiceRequest::QServiceRequest(const QServiceInterfaceDescriptor &descriptor)
    : m_descriptor(descriptor),
      m_reply(0),
      m_type(DescriptorRequest)
{
    // nothing to do here
}

// copy constructor - required by meta-type system - again let's be explicit
QServiceRequest::QServiceRequest(const QServiceRequest &other)
{
    m_interfaceName = other.m_interfaceName;
    m_descriptor = other.m_descriptor;
    m_reply = other.m_reply;
    m_type = other.m_type;
}

// public destructor - required by meta-type system
QServiceRequest::~QServiceRequest()
{
    // nothing to do here
}

// assignment operator - not needed by meta-type but handy anyway
QServiceRequest & QServiceRequest::operator=(const QServiceRequest &rhs)
{
    m_interfaceName = rhs.m_interfaceName;
    m_descriptor = rhs.m_descriptor;
    m_reply = rhs.m_reply;
    m_type = rhs.m_type;
    return *this;
}

QServiceInterfaceDescriptor QServiceRequest::descriptor() const
{
    return m_descriptor;
}

void QServiceRequest::setDescriptor(const QServiceInterfaceDescriptor &descriptor)
{
    m_type = DescriptorRequest;
    m_descriptor = descriptor;
}

void QServiceRequest::setInterfaceName(const QString &interfaceName)
{
    m_type = DefaultInterfaceRequest;
    m_interfaceName = interfaceName;
}

QString QServiceRequest::interfaceName() const
{
    return m_interfaceName;
}

QServiceReply *QServiceRequest::reply() const
{
    return m_reply;
}

void QServiceRequest::setReply(QServiceReply *reply)
{
    m_reply = reply;
}

QService::Scope QServiceRequest::scope() const
{
    return m_scope;
}

void QServiceRequest::setScope(QService::Scope scope)
{
    m_scope = scope;
}

QServiceRequest::Request QServiceRequest::requestType() const
{
    return m_type;
}
