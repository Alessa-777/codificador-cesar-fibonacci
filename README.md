# Cifra de César com sequência de Fibonacci

Programa em C que criptografa uma palavra em duas camadas.

## Como funciona

1. **Camada 1 - Cifra de César:** cada letra é deslocada por um valor SHIFT fixo.
2. **Camada 2 - Sequência numérica:** cada letra é deslocada novamente pelo
   termo correspondente da sequência de Fibonacci (1, 1, 2, 3, 5, 8, 13...).

Deslocamento total da letra i = SHIFT + Fibonacci[i] (com volta no alfabeto).

## Regras de entrada

- Palavra secreta com até 15 letras, sem acentos nem caracteres especiais.
- SHIFT: número inteiro escolhido pelo usuário.

## Como compilar e executar

    gcc encriptador.c -o encriptador
    ./encriptador

## Exemplo de execução

    Palavra (ate 15 letras, sem acentos): coracao
    SHIFT: 3
    Palavra criptografada: gswgkle
    Tipo: Fibonacci | Letras: 7

Cálculo interno:

- Camada 1 (César, SHIFT 3): `frudfdr`
- Sequência usada: 1, 1, 2, 3, 5, 8, 13
- Camada 2 (Fibonacci): `gswgkle`

## Arquivos gerados

- `resultado_criptografia.txt`: palavra codificada, SHIFT, tipo da sequência e
  quantidade de letras.
- `log_execucao.txt`: log com a palavra original, SHIFT, sequência, termos
  usados e o resultado de cada camada.

## Integrantes

- Nome Alessa Araujo
- Nome Paulo Sergio
- Nome Matheus Ferreira
- Nome Otávio Teixeira
