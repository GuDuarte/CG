#include "road.hpp"

#include <glm/gtx/fast_trigonometry.hpp>
#include <glm/gtx/rotate_vector.hpp>

void Road::initializeGL(GLuint program) {
  
  std::array<glm::vec2, 100> Road_positions{
      // Roadline Bottom Right0123
      glm::vec2{0.33f, -0.25f}, glm::vec2{0.43f,-0.25f},
      glm::vec2{0.33f, -0.45f}, glm::vec2{0.43f,-0.45f},

      // Roadline Top Right4567
      glm::vec2{0.33f, 0.25f}, glm::vec2{0.43f,0.25f},
      glm::vec2{0.33f, 0.45f}, glm::vec2{0.43f,0.45f},

      // Roadline Bottom Left891011
      glm::vec2{-0.33f, -0.25f}, glm::vec2{-0.43f,-0.25f},
      glm::vec2{-0.33f, -0.45f}, glm::vec2{-0.43f,-0.45f},

      //Roadline Top Left12131415
      glm::vec2{-0.33f, 0.25f}, glm::vec2{-0.43f,0.25f},
      glm::vec2{-0.33f, 0.45f}, glm::vec2{-0.43f,0.45f},

      //Guardrail left16171819 disabled!!
      glm::vec2{-0.99f, 3.00f}, glm::vec2{-0.99f, 3.00f},
      glm::vec2{-0.99f, 3.00f}, glm::vec2{-0.99f, 3.00f},

      //Guardrail Right20212223
      glm::vec2{1.0f, 1.00f}, glm::vec2{0.95f, 1.00f},
      glm::vec2{0.95f, 0.8f}, glm::vec2{1.0f, 0.8f},

      //Guardrail right24252627
      glm::vec2{0.95f, 0.8f}, glm::vec2{1.0f, 0.8f},
      glm::vec2{0.95f, 0.6f}, glm::vec2{1.0f, 0.6f},

      //Guardrail right28293031
      glm::vec2{0.95f, 0.6f}, glm::vec2{1.0f, 0.6f},
      glm::vec2{0.95f, 0.4f}, glm::vec2{1.0f, 0.4f},

      //Guardrail right32333435
      glm::vec2{0.95f, 0.4f}, glm::vec2{1.0f, 0.4f},
      glm::vec2{0.95f, 0.2f}, glm::vec2{1.0f, 0.2f},

      //Guardrail right36373839
      glm::vec2{0.95f, 0.2f}, glm::vec2{1.0f, 0.2f},
      glm::vec2{0.95f, 0.0f}, glm::vec2{1.0f, 0.0f},

      //Guardrail right40414243
      glm::vec2{0.95f, 0.0f}, glm::vec2{1.0f, 0.0f},
      glm::vec2{0.95f, -0.2f}, glm::vec2{1.0f, -0.2f},

      //Guardrail right44454647
      glm::vec2{0.95f, -0.2f}, glm::vec2{1.0f, -0.2f},
      glm::vec2{0.95f, -0.4f}, glm::vec2{1.0f, -0.4f},

      //Guardrail right48495051
      glm::vec2{0.95f, -0.4f}, glm::vec2{1.0f, -0.4f},
      glm::vec2{0.95f, -0.6f}, glm::vec2{1.0f, -0.6f},

      //Guardrail right52535455
      glm::vec2{0.95f, -0.6f}, glm::vec2{1.0f, -0.6f},
      glm::vec2{0.95f, -0.8f}, glm::vec2{1.0f, -0.8f},

      //Guardrail right56575859
      glm::vec2{0.95f, -0.8f}, glm::vec2{1.0f, -0.8f},
      glm::vec2{0.95f, -1.0f}, glm::vec2{1.0f, -1.0f},

      //################## LEFT

      //Guardrail Left 60616263
      glm::vec2{-1.0f, 1.00f}, glm::vec2{-0.95f, 1.00f},
      glm::vec2{-0.95f, 0.8f}, glm::vec2{-1.0f, 0.8f},

      //Guardrail Left 64656667
      glm::vec2{-0.95f, 0.8f}, glm::vec2{-1.0f, 0.8f},
      glm::vec2{-0.95f, 0.6f}, glm::vec2{-1.0f, 0.6f},

      //Guardrail Left 68697071
      glm::vec2{-0.95f, 0.6f}, glm::vec2{-1.0f, 0.6f},
      glm::vec2{-0.95f, 0.4f}, glm::vec2{-1.0f, 0.4f},

      //Guardrail Left 72737475
      glm::vec2{-0.95f, 0.4f}, glm::vec2{-1.0f, 0.4f},
      glm::vec2{-0.95f, 0.2f}, glm::vec2{-1.0f, 0.2f},

      //Guardrail Left 76 77 78 79
      glm::vec2{-0.95f, 0.2f}, glm::vec2{-1.0f, 0.2f},
      glm::vec2{-0.95f, 0.0f}, glm::vec2{-1.0f, 0.0f},

      //Guardrail Left 80 81 82 83
      glm::vec2{-0.95f, 0.00f}, glm::vec2{-1.0f, 0.00f},
      glm::vec2{-0.95f, -0.2f}, glm::vec2{-1.0f, -0.2f},

      //Guardrail Left 84 85 86 87
      glm::vec2{-0.95f, -0.2f}, glm::vec2{-1.0f, -0.2f},
      glm::vec2{-0.95f, -0.4f}, glm::vec2{-1.0f, -0.4f},

      //Guardrail Left 88 89 90 91
      glm::vec2{-0.95f, -0.4f}, glm::vec2{-1.0f, -0.4f},
      glm::vec2{-0.95f, -0.6f}, glm::vec2{-1.0f, -0.6f},

      //Guardrail Left 92 93 94 95
      glm::vec2{-0.95f, -0.6f}, glm::vec2{-1.0f, -0.6f},
      glm::vec2{-0.95f, -0.8f}, glm::vec2{-1.0f, -0.8f},

      //Guardrail Left 96 97 98 99
      glm::vec2{-0.95f, -0.8f}, glm::vec2{-1.0f, -0.8f},
      glm::vec2{-0.95f, -1.0f}, glm::vec2{-1.0f, -1.0f}
};


std::array Road_indices{0, 1, 2,
                   1, 2, 3,

                  4, 5, 6,
                  5, 6, 7,

                  8, 9, 10,
                  9, 10, 11,

                  12, 13, 14,                 
                  13, 14, 15,

                  16, 17, 18,
                  17, 18, 19,

                  20, 21, 22,
                  20, 22, 23,

                  24, 25, 26,
                  25, 26, 27,

                  28,29,30,
                  29,30,31,

                  32,33,34,
                  33,34,35,

                  36,37,38,
                  37,38,39,

                  40,41,42,
                  41,42,43,

                  44,45,46,
                  45,46,47,

                  48,49,50,
                  49,50,51,

                  52,53,54,
                  53,54,55,

                  56,57,58,
                  57,58,59,
                  //LEFT
                  60,61,62,
                  60,62,63,

                  64,65,66,
                  65,66,67,

                  68,69,70,
                  69,70,71,

                  72,73,74,
                  73,74,75,

                  76,77,78,
                  77,78,79,

                  80,81,82,
                  81,82,83,

                  84,85,86,
                  85,86,87,

                  88,89,90,
                  89,90,91,

                  92,93,94,
                  93,94,95,

                  96,97,98,
                  97,98,99
                };
  
  // Release previous resources, if any
  glDeleteBuffers(1, &Road_vboPositions);
  glDeleteBuffers(1, &Road_vboColors);
  glDeleteBuffers(1, &Road_ebo);
  glDeleteVertexArrays(1, &Road_vao);
  
  // Road colors
  std::array<glm::vec3, 100> Road_colors{
    
    //04
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    //58
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    //912
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    //1316
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    glm::vec3 {1.00f, 1.00f, 0.00f},
    //1720
    glm::vec3 {0.258f, 0.258f, 0.258f},
    glm::vec3 {0.258f, 0.258f, 0.258f},
    glm::vec3 {0.258f, 0.258f, 0.258f},
    glm::vec3 {0.258f, 0.258f, 0.258f},
    //2124
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //2528
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //2932
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //3336
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //3740
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //4144
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //4548
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //4952
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //5356
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //5760
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},

    //6164
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //6568
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //6972
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //7376
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //7780
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //8184
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //8588
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //8992
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    //9396
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    glm::vec3 {1.0f, 0.0f, 0.0f},
    //97100
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f},
    glm::vec3 {1.00f, 1.00f, 1.00f}
    
    
    };
  
  // Generate VBO of positions
  glGenBuffers(1, &Road_vboPositions);
  glBindBuffer(GL_ARRAY_BUFFER, Road_vboPositions);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Road_positions) ,
               Road_positions.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate VBO of colors
  glGenBuffers(1, &Road_vboColors);
  glBindBuffer(GL_ARRAY_BUFFER, Road_vboColors);
  glBufferData(GL_ARRAY_BUFFER, Road_colors.size() * sizeof(glm::vec3),
               Road_colors.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Generate EBO
  glGenBuffers(1, &Road_ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Road_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Road_indices), Road_indices.data(),
               GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Get location of attributes in the program
  GLint positionAttribute{glGetAttribLocation(program, "inPosition")};
  GLint colorAttribute{glGetAttribLocation(program, "inColor")};

  // Create VAO
  glGenVertexArrays(1, &Road_vao);

  // Bind vertex attributes to current VAO
  glBindVertexArray(Road_vao);

  glEnableVertexAttribArray(positionAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Road_vboPositions);
  glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glEnableVertexAttribArray(colorAttribute);
  glBindBuffer(GL_ARRAY_BUFFER, Road_vboColors);
  glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Road_ebo);

  // End of binding to current VAO
  glBindVertexArray(0);

}

void Road::paintGL(GLuint program) {  
  m_program = program;
  glUseProgram(m_program);
  glBindVertexArray(Road_vao);
  //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDrawElements(GL_TRIANGLES, 50*3, GL_UNSIGNED_INT, nullptr);
  glBindVertexArray(0);
  glUseProgram(0);
}



void Road::terminateGL() {
  glDeleteBuffers(1, &Road_vboPositions);
  glDeleteBuffers(1, &Road_ebo);
  glDeleteBuffers(1, &Road_vboColors);
  glDeleteVertexArrays(1, &Road_vao);
}
