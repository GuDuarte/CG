#ifndef CAR_HPP_ 
#define CAR_HPP_

#include <random>
#include <array>
#include "abcg.hpp"
#include "explosion.hpp"

class Car {
 public:
  void initializeGL(GLuint Car_program );
  void paintGL(GLuint Car_program , int Direction);
  void terminateGL();
  void update(int Direction);

 private:
  GLuint Car_vao{};
  GLuint Car_vboPositions{};
  GLuint Car_vboColors{};
  GLuint Car_program{};
  GLuint Car_ebo{};

 std::array<glm::vec2, 5> Car_Positions{
  glm::vec2{-0.12f, -0.57f}, glm::vec2{-0.12f,-0.87f},
  glm::vec2{0.12f, -0.87f}, glm::vec2{0.12f, -0.57f},
  glm::vec2{ 0.0f, -0.6f}
  };

 // Set Car Colors
 std::array<glm::vec3, 5> Car_Colors{
  glm::vec3 {0.00f, 0.00f, 1.00f},
  glm::vec3 {0.00f, 0.00f, 1.00f},
  glm::vec3 {0.00f, 0.00f, 1.00f},
  glm::vec3 {0.00f, 0.00f, 1.00f},
  glm::vec3 {0.00f, 0.00f, 1.00f}
  }; 
 
  Explosion m_explosion;
    
  int Car_viewportWidth{};
  int Car_viewportHeight{};
  
};

#endif