#ifndef VIEWGL_H
#define VIEWGL_H

#include "baseview.h"
#include "contextgl.h"

class ViewGL : public BaseView
{
    Q_OBJECT

    ContextGL m_context;

public:
    ViewGL(QWidget *parent = nullptr);
    ~ViewGL() = default;

    void resizeGL(int w, int h);
    void paintGL();
};

#endif // VIEWGL_H
