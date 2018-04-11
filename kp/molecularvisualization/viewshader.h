#ifndef VIEWSHADER_H
#define VIEWSHADER_H


#include "baseview.h"
#include "contextshader.h"

class ViewShader : public BaseView
{
    Q_OBJECT

    ContextShader m_context;

public:
    ViewShader(QWidget *parent = nullptr);
    ~ViewShader() = default;

    void resizeGL(int w, int h);
    void paintGL();
};

#endif // VIEWSHADER_H
