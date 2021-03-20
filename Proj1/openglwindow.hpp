#ifndef OPENGLWINDOW_HPP_
#define OPENGLWINDOW_HPP_

#include <random>

#include "abcg.hpp"
#include "car.hpp"
#include "road.hpp"
#include "explosion.hpp"
#include "obstacles.hpp"



class OpenGLWindow : public abcg::OpenGLWindow {
 protected:
  void handleEvent(SDL_Event& event);
  void initializeGL() override;
  void paintGL() override;
  void paintUI() override;
  void resizeGL(int width, int height) override;
  void terminateGL() override;

 private:
  GLuint m_vao{};
  GLuint m_vboPositions;
  GLuint m_vboColors;
  GLuint m_program;
  GLuint m_ebo{};
  
  int Direction;
  int m_viewportWidth{};
  int m_viewportHeight{};

  Car m_car;
  Road m_road;
  Explosion m_explosion;
  Obstacles m_obstacle;

  std::default_random_engine m_randomEngine;

  void setupModel();
  void update();
};

#endif