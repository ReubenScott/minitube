/* $BEGIN_LICENSE

This file is part of Minitube.
Copyright 2009, Flavio Tordini <flavio.tordini@gmail.com>

Minitube is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minitube is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minitube.  If not, see <http://www.gnu.org/licenses/>.

$END_LICENSE */

#include "fontutils.h"

namespace {
static const int MIN_PIXEL_SIZE = 11;

QFont createFont(bool isBold, double sizeScale) {
    QFont font;
    font.setPointSize(font.pointSize() * sizeScale);
    font.setBold(isBold);
    return font;
}

QFont createFontWithMinSize(bool isBold, double sizeScale) {
    QFont font = createFont(isBold, sizeScale);
    if (font.pixelSize() < MIN_PIXEL_SIZE)
        font.setPixelSize(MIN_PIXEL_SIZE);
    return font;
}
}

const QFont FontUtils::small() {
    static QFont font = createFontWithMinSize(false, .85);
    return font;
}

const QFont FontUtils::smallBold() {
    static QFont font = createFontWithMinSize(true, .85);
    return font;
}

const QFont FontUtils::medium() {
    static QFont font = createFont(false, 1.1);
    return font;
}

const QFont FontUtils::mediumBold() {
    static QFont font = createFont(true, 0.9);
    return font;
}

const QFont FontUtils::big() {
    static QFont font = createFont(false, 1.5);
    return font;
}

const QFont FontUtils::bigBold() {
    static QFont font = createFont(true, 1.5);
    return font;
}
