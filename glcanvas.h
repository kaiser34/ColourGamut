#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <QGLWidget>
#include <QLinkedList>
#include <QMap>

typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;

  GLfloat r;
  GLfloat g;
  GLfloat b;
} Point;

typedef struct
{
  float index1;
  float index2;
} OptimalColor;

class GLCanvas : public QGLWidget
{
public:
  explicit GLCanvas(QWidget *parent = 0);

protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

  void keyPressEvent(QKeyEvent*);

private:
  enum LAMBDA_TYPE { MOUNTAIN, VALLEY };

  void computPoints (QLinkedList<OptimalColor> &colors, LAMBDA_TYPE type);

  void pointsCoordinatesFromIndexes(QLinkedList<OptimalColor>&,
                                    QLinkedList <Point> &, LAMBDA_TYPE type);

  QLinkedList <Point> _mountainPoints;
  QLinkedList <Point> _valleyPoints;

  float _K;
  int _N;
  const float _delta_Y;
  const float _Y;
  const float _delta_lambda;


  GLfloat *_points;

  float* _y_barSum;

  int _eyeX;
  int _eyeY;
//  int _eyeZ;

  float _xCoord;
  float _yCoord;
  float _zCoord;

};

#endif // GLCANVAS_H
