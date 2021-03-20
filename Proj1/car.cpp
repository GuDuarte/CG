#include "openglwindow.hpp"
#include <imgui.h>
#include <cppitertools/itertools.hpp>
#include "abcg.hpp"
#include "explosion.hpp"


void Car::initializeGL(GLuint m_program ) {
  terminateGL();
  
  Car_program = m_program;  

  std::array Car_indices{
    0, 1, 4,
    2, 3, 4
            
    };

  
  // Generate VBO of positions
  glGenBuffers(1, &Car_vboPositions);
  glBindBuffer(GL_ARRAY_BUFFER, Car_vboPositions);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Car_Positions) ,
               Car_Positions.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate VBO of colors
  glGenBuffers(1, &Car_vboColors);
  glBindBuffer(GL_ARRAY_BUFFER, Car_vboColors);
  glBufferData(GL_ARRAY_BUFFER, Car_Colors.size() * sizeof(glm::vec3),
               Car_Colors.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate EBO
  glGenBuffers(1, &Car_ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Car_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Car_indices), Car_indices.data(),
               GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Get location of attributes in the program
  GLint positionAttribute{glGetAttribLocation(Car_program, "inPosition")};
  GLint colorAttribute{glGetAttribLocation(Car_program, "inColor")};

  // Create VAO
  glGenVertexArrays(1, &Car_vao);

  // Bind vertex attributes to current VAO
  glBindVertexArray(Car_vao);

  glEnableVertexAttribArray(positionAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Car_vboPositions);
  glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glEnableVertexAttribArray(colorAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Car_vboColors);
  glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Car_ebo);

  // End of binding to current VAO
  glBindVertexArray(0);
}

void Car::paintGL(GLuint m_program , int Direction) {
  
  Car_program = m_program;
  //Update position vector  
  Car::update(Direction);

    //Remake buffers with new position
    glBindBuffer(GL_ARRAY_BUFFER, Car_vboPositions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Car_Positions) ,
               Car_Positions.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // Get location of attributes in the program
    GLint positionAttribute{glGetAttribLocation(Car_program, "inPosition")};
    glEnableVertexAttribArray(positionAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, Car_vboPositions);
    glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

  //printf("PaintGL:  %f", Car_Positions[0].x );
  glUseProgram(Car_program);
  glBindVertexArray(Car_vao);
  //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawElements(GL_TRIANGLES, 6 , GL_UNSIGNED_INT, nullptr);
  glBindVertexArray(0);
  glUseProgram(0);
  
}

void Car::terminateGL() {
  glDeleteProgram(Car_program);
  glDeleteBuffers(1, &Car_vboPositions);
  glDeleteBuffers(1, &Car_ebo);
  glDeleteBuffers(1, &Car_vboColors);
  glDeleteVertexArrays(1, &Car_vao);
}


void Car::update(int Direction ) {
    float speed = 0.05;
      if (Direction == 1 and Car_Positions[0].x < 1){
        Car_Positions[0].x += speed;
        Car_Positions[1].x += speed;
        Car_Positions[2].x += speed;
        Car_Positions[3].x += speed;
        Car_Positions[4].x += speed;
        //printf("Update:  %f", Car_Positions[0].x );
        
      }
      if (Direction == 2 and Car_Positions[0].x > -1){
        Car_Positions[0].x -= speed;
        Car_Positions[1].x -= speed;
        Car_Positions[2].x -= speed;
        Car_Positions[3].x -= speed;
        Car_Positions[4].x -= speed;
        
      }
      // Check if car hit the edge of the screen and resets to center
      if (Car_Positions[0].x < -0.95){
        m_explosion.update(Car_Positions[0]);
        Car_Positions = {
          glm::vec2{-0.12f, -0.57f}, glm::vec2{-0.12f,-0.87f},
          glm::vec2{0.12f, -0.87f}, glm::vec2{0.12f, -0.57f},
          glm::vec2{ 0.0f, -0.6f}
        };

      }
      // Check if car hit the edge of the screen and resets to center
      if (Car_Positions[2].x > 0.95){
        m_explosion.update(Car_Positions[2]);
        Car_Positions = {
          glm::vec2{-0.12f, -0.57f}, glm::vec2{-0.12f,-0.87f},
          glm::vec2{0.12f, -0.87f}, glm::vec2{0.12f, -0.57f},
          glm::vec2{ 0.0f, -0.6f}
        };
      }
      
}