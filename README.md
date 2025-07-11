# 🧙‍♂️ Desafio RPG em C – **Jornada em Clandor**

**Para:** `Enzo Soares` &nbsp;&nbsp; **Idade:** 10 anos  
**Tema:** RPG (combate, evolução e loja)

---

## 🗺️ Enredo

O pacífico reino de **Clandor** foi invadido por criaturas das sombras.  
Como jovem herói, sua missão é:

1. Explorar regiões perigosas.  
2. Lutar contra monstros e ganhar **XP**.  
3. Comprar itens mágicos com **ouro**.  
4. Atingir **nível 5**.  
5. Derrotar o **Dragão das Trevas** 🐉 e salvar o castelo!

---

## 🎯 Objetivos de Programação

| Conceito de C | Como aparece no jogo |
|---------------|----------------------|
| `struct`      | Personagem e Monstro |
| `rand()`      | Monstros aleatórios  |
| `if / switch` | Menus e decisões     |
| `while / for` | Loops de jogo        |
| **Funções**   | `atacar()`, `loja()`, `subir_nivel()`… |
| `fopen` (extra) | Salvar / carregar progresso |

---

## ⚔️ Monstros Prontos

| Nome                 | Vida | Ataque | Defesa | XP |
|----------------------|------|--------|--------|----|
| Slime                | 10   | 2      | 1      | 5  |
| Lobo Sombrio         | 20   | 5      | 2      | 10 |
| Mago das Sombras     | 30   | 7      | 3      | 15 |
| **Dragão das Trevas**| 50   | 10     | 5      | 50 |

---

## 🗺️ Mapa do Mundo

1. **Floresta Escura** – Slimes & Lobos  
2. **Montanhas da Perdição** – Magos das Sombras  
3. **Castelo Sombrio** – Dragão das Trevas (nível 5+)

---

## 🏪 Loja

| Item                 | Efeito          | Custo |
|----------------------|-----------------|-------|
| Poção de Vida        | `+10` Vida      | 10 g  |
| Espada de Ferro      | `+2` Ataque     | 15 g  |
| Armadura de Couro    | `+2` Defesa     | 15 g  |
| Poção de XP          | `+10` XP        | 20 g  |

---

## 🎮 Menu Principal

- Criar personagem  
- Iniciar batalha  
- Visitar loja  
- Ver status  
- Salvar progresso  
- Sair  

---

## 💡 Dicas de Código

### 1. Structs

```c
typedef struct {
    char nome[50];
    int vida, ataque, defesa;
    int xp, nivel, ouro;
} Personagem;

typedef struct {
    char nome[50];
    int vida, ataque, defesa, xp;
} Monstro;
```

### 2. Batalha Principal

```c
int dano = heroi.ataque - (monstro.defesa / 2);
if (dano < 0) dano = 0;
monstro.vida -= dano;
printf("Você causou %d de dano!\n", dano);
```

### 3. Subir de Nível

```c
if (heroi.xp >= heroi.nivel * 20) {
    heroi.nivel++;
    heroi.vida += 10;
    heroi.ataque += 2;
    heroi.defesa += 1;
    heroi.xp = 0;
    printf("Parabéns! Nível %d alcançado!\n", heroi.nivel);
}
```

### 4. Número Aleatório

```c
#include <stdlib.h>
#include <time.h>

srand(time(NULL));          // Chamar uma vez
int r = rand() % 3;         // 0, 1 ou 2
```

### 5. Salvamento Extra

```c
FILE *f = fopen("save.txt", "w");
fprintf(f, "%s %d %d %d %d %d %d\n",
        heroi.nome, heroi.nivel, heroi.vida,
        heroi.ataque, heroi.defesa, heroi.xp, heroi.ouro);
fclose(f);
```

---

## 🏁 Como Vencer

1. **Chegar ao nível 5**
2. **Entrar no Castelo Sombrio**
3. **Vencer o Dragão das Trevas**

---

**Boa aventura, jovem herói! 🚀**
