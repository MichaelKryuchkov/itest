/*******************************************************************
 This file is part of iTest
 Copyright (C) 2005-2014 Michal Tomlein

 iTest is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public Licence
 as published by the Free Software Foundation; either version 2
 of the Licence, or (at your option) any later version.

 iTest is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public Licence for more details.

 You should have received a copy of the GNU General Public Licence
 along with iTest; if not, write to the Free Software Foundation,
 Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 ********************************************************************/

#include "main.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_MAC
    QFont::insertSubstitution(".Lucida Grande UI", "Lucida Grande");
#endif

    MTApplication app(argc, argv);

    QSettings settings("Michal Tomlein", "iTest");
    QString lang = settings.value("lang").toString();
    if (lang.length() > 2)
        lang.clear();
    if (lang.isEmpty())
        lang = QLocale::system().name().split('_').first();
    if (lang != "en") {
        QTranslator * translator = new QTranslator;
        translator->load(QString("iTestClient-%1.qm").arg(lang), ":/i18n");
        app.installTranslator(translator);
    }

    MainWindow * itest_window = new MainWindow;
    app.setAppMainWindow(itest_window);
    itest_window->showFullScreen();
    return app.exec();
}

// ---------------------------- version changelog: -----------------------------
/* version 1.4.2 - a minor update with some new features
                 - added Ukrainian, Czech and Hungarian translations
*/
/* version 1.4.1 - a minor update with some new features
                 - added Latvian translation
                 - number of flags now unlimited
                 - added the ability to shuffle answers
                 - "Other settings" moved from iTestClient to iTestServer
                 - Mac OS X: double click or drag and drop database files onto
                   the iTest icon to open them
                 - upgraded from Qt 4.4.0 to Qt 4.5.0 (Windows and Mac OS X
                   binary packages; tarballs still build with Qt 4.4)
                 - numerous bug-fixes and more...
*/
/* version 1.4.0 - a major update
                 - added Italian translation
                 - added an advanced scoring system
                 - added multiple choice questions support
                 - added support for up to 9 answers
                 - code clean-up, code sharing with iTestServer
                 - upgraded from Qt 4.3.2 to Qt 4.4.0
                 - numerous bug-fixes
*/
/* version 1.3.0 - a major update
                 - added Spanish translation
                 - added SVG (scalable vector graphics) support
                 - added multiple correct answers support
                 - added the ability to hide correct answers at the end of tests
                 - made the ui more flexible
                 - fixed a bug where the status of the test progress bar was not
                   refreshed after starting a new test
                 - upgraded from Qt 4.3.1 to Qt 4.3.2
*/
/* version 1.2.0 - a major update
                 - renamed to iTestClient
                 - added Portuguese translation
                 - added the ability to start a new test
                 - more advanced test generation, support for groups added
                 - upgraded from Qt 4.3.0 to Qt 4.3.1
*/
/* version 1.1.1 - a bug-fix release with some new features
                 - added Turkish translation
                 - if available, translation to the system language loaded by
                   default
                 - NEW ENCODING: UTF-8 - adds support for more languages and
                   special characters
                   - iTest 1.1.1 can still open old CP 1250 databases from older
                     versions of iTest
                   - older versions of iTest cannot open the new UTF-8 databases
                     from iTest 1.1.1
                 - upgraded from Qt 4.2.2 to Qt 4.3.0
*/
/* version 1.1.0 - a major update
                 - added Russian translation
                 - added the ability to hide question names
*/
// version 1.0.3 - a bug-fix release
// version 1.0.2 - a bug-fix release
/* version 1.0.1 - a bug-fix release
                 - fixed segmentation fault when connecting
*/
// version 1.0.0 - the first release
