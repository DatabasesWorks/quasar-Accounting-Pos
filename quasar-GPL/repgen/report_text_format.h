// $Id: report_text_format.h,v 1.2 2004/08/31 20:01:32 bpepers Exp $
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

#ifndef REPORT_TEXT_FORMAT_H
#define REPORT_TEXT_FORMAT_H

#include <qstring.h>

class ReportTextFormat {
public:
    ReportTextFormat();
    virtual ~ReportTextFormat();

    // Type name
    virtual QString type() const=0;

    // Create a clone
    virtual ReportTextFormat* clone() const=0;

    // Format a value for output
    virtual QString format(const QString& value)=0;

private:
    // No copy constructor allowed
    ReportTextFormat(const ReportTextFormat& e);
};

#endif // REPORT_TEXT_FORMAT_H
