/*
 * editableselectedarea.h
 * Copyright 2018, Thorbjørn Lindeijer <bjorn@lindeijer.nl>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QObject>
#include <QRect>

class QUndoCommand;

namespace Tiled {
namespace Internal {

class MapDocument;

class EditableSelectedArea : public QObject
{
    Q_OBJECT

public:
    explicit EditableSelectedArea(MapDocument *mapDocument,
                                  QObject *parent = nullptr);

public slots:
    void set(const QRect &rect);
    void add(const QRect &rect);
    void subtract(const QRect &rect);
    void intersect(const QRect &rect);

private:
    void set(const QRegion &region);

    MapDocument * const mMapDocument;
};

} // namespace Internal
} // namespace Tiled
