#ifndef EXPLOSION_HPP_
#define EXPLOSION_HPP_

#include "abcg.hpp"


class Explosion {
 public:
  void initializeGL(GLuint program);
  void paintGL(GLuint program);
  void terminateGL();
  void update(glm::vec2 center);
  
  GLint positionAttribute;
  GLint colorAttribute;
  
  GLuint m_program;
  GLint m_translationLoc;
  GLint m_colorLoc;
  GLint m_scaleLoc;
  GLint m_rotationLoc;

  //Center
  std::array<glm::vec2, 9> Explosion_positions{
      //Inner circle
      glm::vec2{0.0f, 0.0f},

      glm::vec2{0.0f, 0.1f}, glm::vec2{0.0707f, 0.0707f},
      glm::vec2{0.1f, 0.0f}, glm::vec2{0.0707f,-0.0707f},
      glm::vec2{0.0f,-0.1f}, glm::vec2{-0.0707f,-0.0707f},
      glm::vec2{-0.1f, 0.0f}, glm::vec2{-0.0707f,0.0707f}
};

  std::array<glm::vec2, 9> Explosion_positions_offscreen{
      //Inner circle
      glm::vec2{-2.0f, -2.0f},

      glm::vec2{-2.0f, -1.9f}, glm::vec2{-1.9293f, -1.9293f},
      glm::vec2{-1.9f, -2.0f}, glm::vec2{-1.9293f,-2.0707f},
      glm::vec2{-2.0f,-2.1f}, glm::vec2{-2.0707f,-2.0707f},
      glm::vec2{-2.1f, -2.0f}, glm::vec2{-2.0707f,-1.9293f}
};
  
  // Explosion colors
  std::array<glm::vec3, 9> Explosion_colors{
    glm::vec3 {1.00f, 0.964f, 0.278f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f}
  };
  
  GLuint e_program;
  GLuint Explosion_vao;
  GLuint Explosion_vbo;
  GLuint Explosion_ebo;

  GLuint Explosion_vboPositions;
  GLuint Explosion_vboColors;

  
};

#endif