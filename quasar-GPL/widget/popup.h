// $Id: popup.h,v 1.12 2004/02/03 00:56:03 arandell Exp $
//
// Copyright (C) 1998-2004 Linux Canada Inc.  All rights reserved.
//
// This file is part of Quasar Accounting
//
// This file may be distributed and/or modified under the terms of the
// GNU General Public License version 2 as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL included in the
// packaging of this file.
//
// Licensees holding a valid Quasar Commercial License may use this file
// in accordance with the Quasar Commercial License Agreement provided
// with the Software in the LICENSE.COMMERCIAL file.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// See http://www.linuxcanada.com or email sales@linuxcanada.com for
// information about Quasar Accounting support and maintenance options.
//
// Contact sales@linuxcanada.com if any conditions of this licensing are
// not clear to you.

#ifndef POPUP_H
#define POPUP_H

#include <qwidget.h>
#include <qbutton.h>

class Popup: public QWidget {
    Q_OBJECT
public:
    Popup(QWidget* text, QButton* button, QWidget* parent=0,
	  const char* name=0);

    QWidget* textWidget() const { return _text; }
    QButton* buttonWidget() const { return _button; }

    QString text() const;
    void setText(const QString& string);

    QWidget* popupWidget() const;
    void setPopupWidget(QWidget* popup);

    void setFocus() { _text->setFocus(); }
    void setFocusPolicy(FocusPolicy p) { _text->setFocusPolicy(p); }
    void setLength(int length);

signals:
    void validData();

public slots:
    virtual void openPopup();
    virtual void closePopup();

protected:
    void moveEvent(QMoveEvent* e);
    void resizeEvent(QResizeEvent* e);
    bool eventFilter(QObject* o, QEvent* e);

    QWidget* _text;
    QButton* _button;
    QWidget* _popup;
};

#endif