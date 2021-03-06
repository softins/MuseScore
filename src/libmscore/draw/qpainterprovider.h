//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2021 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#ifndef MU_DRAW_QPAINTERPROVIDER_H
#define MU_DRAW_QPAINTERPROVIDER_H

#include "ipaintprovider.h"

class QPainter;
class QImage;

namespace mu::draw {
class QPainterProvider : public IPaintProvider
{
public:
    QPainterProvider(QPainter* painter, bool overship = false);
    ~QPainterProvider();

    static IPaintProviderPtr make(QPaintDevice* dp);
    static IPaintProviderPtr make(QPainter* qp, bool overship = false);

    QPaintDevice* device() const override;
    QPainter* qpainter() const override;

    bool end() override;
    bool isActive() const override;

    void setAntialiasing(bool arg) override;
    void setCompositionMode(CompositionMode mode) override;

    void setFont(const QFont& f) override;
    const QFont& font() const override;

    void setPen(const QColor& color) override;
    void setPen(const QPen& pen) override;
    void setNoPen() override;
    const QPen& pen() const override;

    void setBrush(const QBrush& brush) override;
    const QBrush& brush() const override;

    void save() override;
    void restore() override;

    void setWorldTransform(const QTransform& matrix, bool combine = false) override;
    const QTransform& worldTransform() const override;

    void setTransform(const QTransform& transform, bool combine = false) override;
    const QTransform& transform() const override;

    void setMatrix(const QMatrix& matrix, bool combine = false) override;

    void scale(qreal sx, qreal sy) override;
    void rotate(qreal a) override;

    void translate(const QPointF& offset) override;

    QRect window() const override;
    void setWindow(const QRect& window) override;
    QRect viewport() const override;
    void setViewport(const QRect& viewport) override;

    // drawing functions
    void fillPath(const QPainterPath& path, const QBrush& brush) override;
    void drawPath(const QPainterPath& path) override;

    void drawLines(const QLineF* lines, int lineCount) override;
    void drawLines(const QPointF* pointPairs, int lineCount) override;

    void drawRects(const QRectF* rects, int rectCount) override;
    void drawRoundedRect(const QRectF& rect, qreal xRadius, qreal yRadius, Qt::SizeMode mode = Qt::AbsoluteSize) override;

    void drawEllipse(const QRectF& r) override;

    void drawPolyline(const QPointF* points, int pointCount) override;

    void drawPolygon(const QPointF* points, int pointCount, Qt::FillRule fillRule = Qt::OddEvenFill) override;
    void drawConvexPolygon(const QPointF* points, int pointCount) override;

    void drawArc(const QRectF& rect, int a, int alen) override;

    void drawText(const QPointF& p, const QString& s) override;
    void drawText(const QRectF& r, int flags, const QString& text, QRectF* br = nullptr) override;

    void drawGlyphRun(const QPointF& position, const QGlyphRun& glyphRun) override;

    void fillRect(const QRectF& r, const QColor& color) override;

    void drawPixmap(const QPointF& p, const QPixmap& pm) override;
    void drawTiledPixmap(const QRectF& rect, const QPixmap& pm, const QPointF& offset = QPointF()) override;

private:
    QPainter* m_painter = nullptr;
    bool m_overship = false;
};
}

#endif // MU_DRAW_QPAINTERPROVIDER_H
