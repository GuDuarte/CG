#include "openglwindow.hpp"
#include <imgui.h>
#include <cppitertools/itertools.hpp>
#include "abcg.hpp"
#include <chrono>
#include <thread>



void Obstacles::createObstacle(){
  
}


void Obstacles::initializeGL(GLuint m_program ) {
  terminateGL();
  
  Obs_program = m_program;  

  std::array Obs_indices{
    0, 1, 2,
    0, 2, 3,

    0, 3, 4,
    0, 4, 5,
    
    0, 5, 6,
    0, 6, 7,

    0, 7, 8,
    0, 1, 8,

    9,10,11,
    9,11,12,

    9,12,13,
    9,13,14,

    9,14,15,
    9,15,16,

    9,16,17,
    9,17,10,

    18,19,20,
    18,20,21,

    18,21,22,
    18,22,23,

    18,23,24,
    18,24,25,

    18,25,26,
    18,26,19,

    27,28,29,
    27,29,30,

    27,30,31,
    27,31,32,

    27,32,33,
    27,33,34,

    27,34,35,
    27,35,28,

    36,37,38,
    36,38,39,

    36,39,40,
    36,40,41,

    36,41,42,
    36,42,43,

    36,43,44,
    36,44,37
    };
  
  
  // Generate VBO of positions
  glGenBuffers(1, &Obs_vboPositions);
  glBindBuffer(GL_ARRAY_BUFFER, Obs_vboPositions);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Obs_positions) ,
               Obs_positions.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate VBO of colors
  glGenBuffers(1, &Obs_vboColors);
  glBindBuffer(GL_ARRAY_BUFFER, Obs_vboColors);
  glBufferData(GL_ARRAY_BUFFER, Obs_colors.size() * sizeof(glm::vec3),
               Obs_colors.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate EBO
  glGenBuffers(1, &Obs_ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Obs_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Obs_indices), Obs_indices.data(),
               GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Get location of attributes in the program
  GLint positionAttribute{glGetAttribLocation(Obs_program, "inPosition")};
  GLint colorAttribute{glGetAttribLocation(Obs_program, "inColor")};

  // Create VAO
  glGenVertexArrays(1, &Obs_vao);

  // Bind vertex attributes to current VAO
  glBindVertexArray(Obs_vao);

  glEnableVertexAttribArray(positionAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Obs_vboPositions);
  glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glEnableVertexAttribArray(colorAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Obs_vboColors);
  glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Obs_ebo);

  // End of binding to current VAO
  glBindVertexArray(0);
}

void Obstacles::paintGL(GLuint m_program) {
  
  if (Moving.elapsed() > 200.0 / 1000.0){
    Obstacles::update();
    Moving.restart();
  } 
  Obs_program = m_program;
  

    //Remake buffers with new position
    glBindBuffer(GL_ARRAY_BUFFER, Obs_vboPositions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Obs_positions) ,
               Obs_positions.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // Get location of attributes in the program
    GLint positionAttribute{glGetAttribLocation(Obs_program, "inPosition")};
    glEnableVertexAttribArray(positionAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, Obs_vboPositions);
    glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

  //printf("PaintGL:  %f", Car_Positions[0].x );
  glUseProgram(Obs_program);
  glBindVertexArray(Obs_vao);
  //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawElements(GL_TRIANGLES, 40*3 , GL_UNSIGNED_INT, nullptr);
  glBindVertexArray(0);
  glUseProgram(0);
  
}

void Obstacles::terminateGL() {
  glDeleteProgram(Obs_program);
  glDeleteBuffers(1, &Obs_vboPositions);
  glDeleteBuffers(1, &Obs_ebo);
}

// Enviar obstaculos pro topo da tela criava uma distorcao na imagem
//Obstaculos sao movidos para fora da area [-1,1] antes de serem enviados para o topo
void Obstacles::update() {  
  int count = sizeof(Obs_positions)/sizeof(Obs_positions[0]);
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  r = r/2.0;
  //printf("size of %d", count);
  
  for(int i = 0  ; i <= count ; i++){
    //Se o objeto esta no topo mas longe da area desenhada, e enviado para mais proximo da tela
    if( Obs_positions[i].y > 3.0f) {
      Obs_positions[i].x = Obs_positions[i].x - 4.0f;
      Obs_positions[i].y = Obs_positions[i].y - 4.0f;
    } 
    // Se objeto esta para fora a direita, e enviado para o topo
    if( Obs_positions[i].x > 3.0f) {
      Obs_positions[i].y = Obs_positions[i].y + 4.0f;
    } 
    // Se objeto chegou no canto inferior, enviado para fora a direita
    if( Obs_positions[i].y < -1.2f) {
      Obs_positions[i].x = Obs_positions[i].x + 4.0f;
      
    }
    Obs_positions[i].y -= speed;
  } 

  //printf("Update:  %f", Car_Positions[0].x );
}  
      
