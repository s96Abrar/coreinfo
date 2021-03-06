/*
CoreInfo give's a file's detail informations.

CoreInfo is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef COREINFO_H
#define COREINFO_H

#include <QWidget>
#include <QDir>
#include <QMimeData>
#include <QTextBrowser>
#include <QTreeWidget>

#include "Core.h"
#include "configtreetext.h"

#include <ZenLib/Ztring.h>
#include <ZenLib/ZtringListList.h>
#include <cprime/utilities.h>

using namespace ZenLib;

#define wstring2QString(_DATA) \
    QString::fromUtf8(Ztring(_DATA).To_UTF8().c_str())
#define QString2wstring(_DATA) \
    Ztring().From_UTF8(_DATA.toUtf8())

namespace Ui {
class coreinfo;
}

class coreinfo : public QWidget
{
    Q_OBJECT

public:
    explicit coreinfo(QWidget *parent = nullptr);
    ~coreinfo();

    void openFiles(QStringList fileNames);
    void refreshDisplay();
    QDir getCommonDir(Core *C);

private:
    Ui::coreinfo *ui;
    Core* C;
    QTreeWidget *showTreeView(bool completeDisplay);
    QString shortName(QDir d, QString name);
};

#endif // COREINFO_H
