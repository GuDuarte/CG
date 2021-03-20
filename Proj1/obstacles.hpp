#ifndef OBSTACLES_HPP_ 
#define OBSTACLES_HPP_

#include <random>
#include <array>
#include "abcg.hpp"
#include "explosion.hpp"

class Obstacles {
 public:
  void initializeGL(GLuint Obs_program );
  void paintGL(GLuint Obs_program);
  void createObstacle();
  void terminateGL();
  void update();

 private:
  GLuint Obs_vao{};
  GLuint Obs_vboPositions{};
  GLuint Obs_vboColors{};
  GLuint Obs_program{}; 
  GLuint Obs_ebo{};

 //Center
  std::array<glm::vec2, 45> Obs_positions{
      //Center 1
      glm::vec2{0.0f, 1.2f},
      //Edges 1
      glm::vec2{0.0f, 1.3f}, glm::vec2{0.0707f, 1.2707f},
      glm::vec2{0.1f, 1.2f}, glm::vec2{0.0707f, 1.1293f},
      glm::vec2{0.0f, 1.1f}, glm::vec2{-0.0707f, 1.1293f},
      glm::vec2{-0.1f, 1.2f}, glm::vec2{-0.0707f, 1.2707f},

      //Center 2
      glm::vec2{0.66f, 1.2f},
      //Edges 2
      glm::vec2{0.66f, 1.3f}, glm::vec2{0.7307f, 1.2707f},
      glm::vec2{0.76f, 1.2f}, glm::vec2{0.7307f, 1.1293f},
      glm::vec2{0.66f, 1.1f}, glm::vec2{0.5893f, 1.1293f},
      glm::vec2{0.56f, 1.2f}, glm::vec2{0.5893f, 1.2707f},

      //Center 3
      glm::vec2{0.33f, 0.3f},
      //Edges 3
      glm::vec2{0.33f, 0.4f}, glm::vec2{0.4007f, 0.3707f},
      glm::vec2{0.43f, 0.3f}, glm::vec2{0.4007f, 0.2293f},
      glm::vec2{0.33f, 0.2f}, glm::vec2{0.2593f, 0.2293f},
      glm::vec2{0.23f, 0.3f}, glm::vec2{0.2593f, 0.3707f},

      //Center 4
      glm::vec2{-0.66f, 1.2f},
      //Edges 4
      glm::vec2{-0.66f, 1.3f}, glm::vec2{-0.7307f, 1.2707f},
      glm::vec2{-0.76f, 1.2f}, glm::vec2{-0.7307f, 1.1293f},
      glm::vec2{-0.66f, 1.1f}, glm::vec2{-0.5893f, 1.1293f},
      glm::vec2{-0.56f, 1.2f}, glm::vec2{-0.5893f, 1.2707f},

      //Center 5
      glm::vec2{-0.33f, 0.3f},
      //Edges 5
      glm::vec2{-0.33f, 0.4f}, glm::vec2{-0.4007f, 0.3707f},
      glm::vec2{-0.43f, 0.3f}, glm::vec2{-0.4007f, 0.2293f},
      glm::vec2{-0.33f, 0.2f}, glm::vec2{-0.2593f, 0.2293f},
      glm::vec2{-0.23f, 0.3f}, glm::vec2{-0.2593f, 0.3707f},
};

 // Set Car Colors
 std::array<glm::vec3, 45> Obs_colors{
    //Center 1
    glm::vec3 {1.00f, 0.964f, 0.278f},
    //Edges 1
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},

    //Center 2
    glm::vec3 {1.00f, 0.964f, 0.278f},
    //Edges 2
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},

    //Center 3
    glm::vec3 {1.00f, 0.964f, 0.278f},
    //Edges 3
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},

    //Center 4
    glm::vec3 {1.00f, 0.964f, 0.278f},
    //Edges 4
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},

    //Center 5
    glm::vec3 {1.00f, 0.964f, 0.278f},
    //Edges 5
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f},
    glm::vec3 {1.00f, 0.00f, 0.00f}
  };
   
 float speed = 0.10;

  abcg::ElapsedTimer Moving;
  
};

#endif