#ifndef ROAD_HPP_
#define ROAD_HPP_

#include "abcg.hpp"


class Road {
 public:
  void initializeGL(GLuint program);
  void paintGL(GLuint program);
  void terminateGL();

  GLuint m_program;
  GLint m_translationLoc;
  GLint m_colorLoc;
  GLint m_scaleLoc;
  GLint m_rotationLoc;

  GLuint Road_vao;
  GLuint Road_vbo;
  GLuint Road_ebo;

  GLuint Road_vboPositions;
  GLuint Road_vboColors;

  
};

#endif