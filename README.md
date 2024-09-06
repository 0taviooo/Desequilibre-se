# (Des)Equilibre-se!

**Disciplina:** Química IV.

**Docente:** Dr. Rufino.

**Equipe:** Emily Farias da Silva, Francisco Arthur Rodrigues Cordeiro, Inacio Meneses Teixeira Freitas, Otávio Pereira Magalhães Moura, Vitor Martins Rocha Carvalho.


**Conteúdo abordado**: Deslocamento de equilíbrio químico.


**Funcionamento do jogo:**

O jogo é programado em C++ e C, utilizando raylib. (Des)Equilibre-se tem a dinâmica de perguntas e respostas baseado em tempo, sendo o tempo diferente por dificuldade.

Será mostrado na tela uma equação química reversível (Ex.: **HCl(aq) + H₂O(l) ⇌ H₃O⁺(aq) + Cl⁻(aq)**), com um enunciado abaixo, anunciando uma alteração em fatores estequiométricos (**concentração** , **pressão** e **temperatura**) e então o jogador deve indicar apertando um botão na tela para qual lado a equação ficará favorável, reagentes ou produtos (Esquerda ou Direita).

**Há 3 dificuldades jogáveis:**

* **Fácil.**

  O tempo para responder cada pergunta é 15 segundos.

* **Médio.**

  O tempo para responder cada pergunta é 10 segundos.

* **Difícil.**

  O tempo para responder cada pergunta é 5 segundos.

Para cada pergunta corretamente respondida o jogador receberá 20 pontos, existindo um High Score (recorde) para cada dificuldade. O jogo seguirá indefinidamente até que o jogador erre alguma pergunta.
