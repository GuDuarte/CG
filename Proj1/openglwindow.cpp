#include "openglwindow.hpp"
#include <imgui.h>
#include <cppitertools/itertools.hpp>
#include "abcg.hpp"


void OpenGLWindow::handleEvent(SDL_Event &event) {
  // Keyboard events
  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
      Direction = 2;
    if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
      Direction = 1;
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
      Direction = 3;
  }
  if (event.type == SDL_KEYUP) {
    if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
      Direction = 2;
    if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
      Direction = 1;
  }
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
      Direction = 3;
}

void OpenGLWindow::initializeGL() {


  const auto *vertexShader{R"gl(
    #version 410

    layout(location = 0) in vec2 inPosition;
    layout(location = 1) in vec4 inColor;
       

    uniform vec2 translation;
    uniform float scale;

    out vec4 fragColor;

    void main() {
      
      gl_Position = vec4(inPosition, 0, 1);
      fragColor = inColor;
    }
  )gl"};

  const auto *fragmentShader{R"gl(
    #version 410

    in vec4 fragColor;

    out vec4 outColor;

    void main() { outColor = fragColor; }
  )gl"};
    
  // Create shader program
  m_program = createProgramFromString(vertexShader, fragmentShader);
  glClearColor(0.419f, 0.419f, 0.419f, 1);
  m_road.initializeGL(m_program);
  m_car.initializeGL(m_program);
  m_explosion.initializeGL(m_program);
  m_obstacle.initializeGL(m_program);
  
}

void OpenGLWindow::paintGL() {  
  
  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, m_viewportWidth, m_viewportHeight);
  update();
  Direction = 0;
  m_road.paintGL(m_program);
  m_explosion.paintGL(m_program  );
  m_car.paintGL(m_program, Direction);
  m_obstacle.paintGL(m_program);
  
}

void OpenGLWindow::paintUI() {
 {
    auto size{ImVec2(300, 85)};
    auto position{ImVec2((m_viewportWidth - size.x) / 2.0f,
                         (m_viewportHeight - size.y) / 2.0f)};
    ImGui::SetNextWindowPos(position);
    ImGui::SetNextWindowSize(size);
    //ImGuiWindowFlags flags{ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs};
  }
}

void OpenGLWindow::resizeGL(int width, int height) {
  m_viewportWidth = width;
  m_viewportHeight = height;

  glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWindow::update() {  
  m_car.update(Direction);
  m_explosion.update(glm::vec2{-2.0f,-2.0f});
  
}
void OpenGLWindow::terminateGL() {
  m_car.terminateGL();
  m_road.terminateGL();
  m_explosion.terminateGL();
  m_obstacle.terminateGL();
}
