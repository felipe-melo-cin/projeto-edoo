# ECOS DE ARAÑAMI: Versão CLI

Projeto da cadeira de estruturas de dados orientadas a objetos CIn UFPE 2025.2

Esse projeto é uma recriação do jogo **ECOS DE ARAÑAMI**, criado para a cadeira de introdução à programação CIn UFPE 2025.2

O código do jogo, escrito originalmente em Python, com a biblioteca Pygame, foi reimaginado para a interface de comando. O objetivo do projeto é demonstrar o conhecimento adquirido na cadeira sobre orientação a objetos, por meio da criação de código na linguagem de programação C++.

### Projeto Original: https://github.com/CauaEmano/Jogo_de_ip

---

# Compilação

Clone o projeto para seu ambiente de trabalho:

``git clone https://github.com/felipe-melo-cin/projeto-edoo``

---

### Windows: MinGW

No prompt de comando, compile o código:

``g++ -o ecos_de_aranami main.cpp src\*\*``

Se o comando acima não funcionar:

``g++ -o ecos_de_aranami main.cpp src\entidades\* src\mundo\* src\nucleo\* src\objetos\*``

Execute o programa:

``ecos_de_aranami.exe``

---

### Linux

No terminal, compile o código:

``g++ -o ecos_de_aranami main.cpp src/*/*``

Se o comando acima não funcionar:

``g++ -o ecos_de_aranami main.cpp src/entidades/* src/mundo/* src/nucleo/* src/objetos/*``

Execute o programa:

``./ecos_de_aranami``

---

# Instalação Direta

Se compilar não for sua praia, é possível adquirir o executável diretamente na aba **Releases**:

https://github.com/felipe-melo-cin/projeto-edoo/releases

---

# COMO JOGAR

O jogo vai requisitar ações do usuário com uma lista de comandos possíveis e o símbolo `>`.

Os comandos podem vir em duas formas:

---

```
[COMANDO 1]
[COMANDO 2]
[COMANDO 3]
...
[COMANDO N]
> SUA RESPOSTA VEM AQUI
```

Aqui, você responde com o nome do comando. Não precisa se preocupar com o uso de letras maiúsculas ou minúsculas, ambas funcionam.

---

```
[1] COMANDO 1
[2] COMANDO 2
[3] COMANDO 3
...
[N] COMANDO N
> SUA RESPOSTA VEM AQUI
```

Aqui, você responde com o número correspondente ao comando.

---

### O jogo acontece em 13 zonas. Seu objetivo é alcançar a última zona e matar o chefe. Boa sorte ^^
