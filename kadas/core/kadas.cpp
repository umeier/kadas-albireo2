/***************************************************************************
    kadas.cpp
    ---------
    copyright            : (C) 2019 by Sandro Mani
    email                : smani at sourcepole dot ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <QApplication>
#include <QDir>
#include <QStandardPaths>

#include "kadas.h"
#include "kadas_config.h"

const char* Kadas::KADAS_VERSION = _KADAS_VERSION_;
const int Kadas::KADAS_VERSION_INT = _KADAS_VERSION_INT_;
const char* Kadas::KADAS_RELEASE_NAME = _KADAS_NAME_;
const char* Kadas::KADAS_FULL_RELEASE_NAME = _KADAS_FULL_NAME_;
const char* Kadas::KADAS_DEV_VERSION = _KADAS_DEV_VERSION_;
const char* Kadas::KADAS_BUILD_DATE = __DATE__;

QString Kadas::configPath()
{
  QDir appDataDir = QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  return appDataDir.absoluteFilePath(Kadas::KADAS_RELEASE_NAME);
}

QString Kadas::pkgDataPath()
{
  return QDir(QString("%1/../%2").arg(QApplication::applicationDirPath(), KADAS_RELEASE_NAME)).absolutePath();
}

QString Kadas::projectTemplatesPath() {
  return QDir(pkgDataPath()).absoluteFilePath("project_templates");
}
