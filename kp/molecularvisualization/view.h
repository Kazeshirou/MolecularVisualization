#ifndef VIEW_H
#define VIEW_H

#include "baseview.h"
#include "context.h"
#include "transformational.h"

#include <QVector2D>

class View : public BaseView
{
    Q_OBJECT

    Context m_context;
public:
    View(QWidget *parent = nullptr);
    ~View() = default;

    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
    QImage &getImage();

};

#endif // VIEW_H
