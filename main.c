#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LETRAS 15
#define NOME_SEQUENCIA "Fibonacci"

int palavra_valida(const char *p) {
    int n = strlen(p);
    if (n < 1 || n > MAX_LETRAS) return 0;
    for (int i = 0; i < n; i++) {
        if (!((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z')))
            return 0;
    }
    return 1;
}

void gerar_sequencia(int n, int seq[]) {
    int a = 1, b = 1;
    for (int i = 0; i < n; i++) {
        seq[i] = a;
        int prox = a + b;
        a = b;
        b = prox;
    }
}

/* Camada 1: Cifra de Cesar com SHIFT fixo */
void camada1(const char *palavra, int shift, char *saida) {
    int n = strlen(palavra);
    shift = ((shift % 26) + 26) % 26;
    for (int i = 0; i < n; i++) {
        char base = isupper((unsigned char)palavra[i]) ? 'A' : 'a';
        saida[i] = (palavra[i] - base + shift) % 26 + base;
    }
    saida[n] = '\0';
}

/* Camada 2: deslocamento dinamico pela sequencia numerica */
void camada2(const char *texto, const int seq[], char *saida) {
    int n = strlen(texto);
    for (int i = 0; i < n; i++) {
        char base = isupper((unsigned char)texto[i]) ? 'A' : 'a';
        saida[i] = (texto[i] - base + seq[i] % 26) % 26 + base;
    }
    saida[n] = '\0';
}

int main(void) {
    char palavra[100], c1[MAX_LETRAS + 1], c2[MAX_LETRAS + 1];
    int seq[MAX_LETRAS];
    int shift, tipo, n;
    const char *nomes[] = {"", "PA", "PG", "Fibonacci", "Primos"};

    while (1) {
        printf("Palavra (ate 15 letras, sem acentos): ");
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';
        if (palavra_valida(palavra)) break;
        printf("Palavra invalida. Use so letras, ate 15.\n");
    }

    printf("SHIFT: ");
    scanf("%d", &shift);

    n = strlen(palavra);
    gerar_sequencia(n, seq);
    camada1(palavra, shift, c1);
    camada2(c1, seq, c2);

    printf("Palavra criptografada: %s\n", c2);
    printf("Tipo: %s | Letras: %d\n", NOME_SEQUENCIA, n);

    FILE *res = fopen("resultado_criptografia.txt", "w");
    if (res != NULL) {
        fprintf(res, "Palavra codificada: %s | SHIFT: %d | Tipo: %s | Letras: %d\n",
                c2, shift, NOME_SEQUENCIA, n);
        fclose(res);
    }

    FILE *arq_log = fopen("log_execucao.txt", "a");
    if (arq_log != NULL) {
        fprintf(arq_log, "Palavra original: %s\n", palavra);
        fprintf(arq_log, "Quantidade de letras: %d\n", n);
        fprintf(arq_log, "SHIFT: %d\n", shift);
        fprintf(arq_log, "Tipo de sequencia: %s\n", NOME_SEQUENCIA);
        fprintf(arq_log, "Termos usados: ");
        for (int i = 0; i < n; i++) fprintf(arq_log, "%d ", seq[i]);
        fprintf(arq_log, "\n");
        fprintf(arq_log, "Camada 1 (Cesar): %s\n", c1);
        fprintf(arq_log, "Camada 2 (sequencia): %s\n", c2);
        fprintf(arq_log, "----------\n");
        fclose(arq_log);
    }

    return 0;
}
