Proj 1 

Autores:
  Luisa Salles de Oliveira  RA 11201720136
  Gustavo Duarte de Souza   RA 11012515
  
  
Aplicação:
  O objetivo era criar um jogo Endless Runner, onde o jogador deve desviar de obstáculos infinitamente.
  Algumas funções, como animação de "explosão" e verificação de colisão não foram implantados.
  

Conteúdo:

  Roads:
    Define o plano de fundo, bordas e retãngulos centrais que representam divisão de faixa.
  
  Car:
    Define o carro, atualiza sua posição conforme comando do teclado e reseta caso o carro encoste na borda da tela.
  
  Obstacles:
    Define os obstáculos que se movem em direção ao carro, atualiza conforme uma velocidade fixa e retorna para o topo ao atingir Y < -1.
    Devido a atualização ser realizada vértice por vértice, é necessário levar o objeto para fora da tela (X > 1), atualizá-los para Y > 1, e retorná-los ao centro da imagem X ∈       [-1,1]
  
  Explosion:
    Define animação de colisão, porém, não foi implementada.
  
Apesar do projeto não ser um jogo completo, acreditamos que ele demonstre o conteúdo aprendido na disciplina até o momento, utilizando shaders, vértices, VBOs, EBOs, VAOs e outras funções da biblioteca ABCg. 

  
