#include "explosion.hpp"
#include <chrono>
#include <thread>
#include <glm/gtx/fast_trigonometry.hpp>
#include <glm/gtx/rotate_vector.hpp>

//Expected: display an explosion when the car touches ANYTHING
//
void Explosion::initializeGL(GLuint program ) {

// Release previous resources, if any
Explosion::terminateGL();

std::array Explosion_indices{
  0, 1, 2,
  0, 2, 3,

  0, 3, 4,
  0, 4, 5,
  
  0, 5, 6,
  0, 6, 7,

  0, 7, 8,
  0, 1, 8
  };
  
  
  // Generate VBO of positions
  glGenBuffers(1, &Explosion_vboPositions);
  glBindBuffer(GL_ARRAY_BUFFER, Explosion_vboPositions);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Explosion_positions) ,
               Explosion_positions.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate VBO of colors
  glGenBuffers(1, &Explosion_vboColors);
  glBindBuffer(GL_ARRAY_BUFFER, Explosion_vboColors);
  glBufferData(GL_ARRAY_BUFFER, Explosion_colors.size() * sizeof(glm::vec3),
               Explosion_colors.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate EBO
  glGenBuffers(1, &Explosion_ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Explosion_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Explosion_indices), Explosion_indices.data(),
               GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Get location of attributes in the program
  positionAttribute = {glGetAttribLocation(program, "inPosition")};
  colorAttribute = {glGetAttribLocation(program, "inColor")};

  // Create VAO
  glGenVertexArrays(1, &Explosion_vao);

  // Bind vertex attributes to current VAO
  glBindVertexArray(Explosion_vao);

  glEnableVertexAttribArray(positionAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Explosion_vboPositions);
  glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glEnableVertexAttribArray(colorAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Explosion_vboColors);
  glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Explosion_ebo);

  // End of binding to current VAO
  glBindVertexArray(0);

}

void Explosion::paintGL(GLuint m_program ) { 

  //std::this_thread::sleep_for(std::chrono::milliseconds(10));

    //Remake buffers with new position
    glBindBuffer(GL_ARRAY_BUFFER, Explosion_vboPositions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Explosion_positions) ,
               Explosion_positions.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // Get location of attributes in the program
    GLint positionAttribute{glGetAttribLocation(m_program, "inPosition")};
    glEnableVertexAttribArray(positionAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, Explosion_vboPositions);
    glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

  //printf("PaintGL:  %f", Car_Positions[0].x );
  
  glUseProgram(m_program);
  glBindVertexArray(Explosion_vao);
  //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawElements(GL_TRIANGLES, 8*3 , GL_UNSIGNED_INT, nullptr);
  glBindVertexArray(0);
  glUseProgram(0); 
}

void Explosion::terminateGL() {
  glDeleteBuffers(1, &Explosion_vboPositions);
  glDeleteBuffers(1, &Explosion_vboColors);
  glDeleteBuffers(1, &Explosion_ebo);
  glDeleteVertexArrays(1, &Explosion_vao);
}

void Explosion::update(glm::vec2 center){

  if (center.x == -2.0f){
      Explosion_positions = Explosion_positions_offscreen;
  } else {
    for (int i = 0 ; i < 10 ; i++){
      Explosion_positions[i].x = Explosion_positions[i].x + 2.0f + center.x;
      Explosion_positions[i].y = Explosion_positions[i].y + 2.0f + center.y;
    }
  }
}
