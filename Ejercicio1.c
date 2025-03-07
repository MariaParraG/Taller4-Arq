#include <stdio.h> 
#include <string.h> 

#define NUM_INSTRUCCIONES 10 
#define NUM_ETAPAS 5 

// Función para mostrar el estado del pipeline 
void mostrarPipeline(char pipeline[NUM_ETAPAS][20], int ciclo) { 
    printf("Ciclo %d:\n", ciclo); 
    for (int i = 0; i < NUM_ETAPAS; i++) { 
        printf("Etapa %d: %s\n", i + 1, pipeline[i]); 
    }
    printf("\n"); 
} 

int main() {
    char pipeline[NUM_ETAPAS][20] = {0}; 
    char instrucciones[NUM_INSTRUCCIONES][20]; 
    int numInstrucciones; 

    // Leer el número de instrucciones 
    printf("Ingrese el número de instrucciones (max %d): ", NUM_INSTRUCCIONES); 
    scanf("%d", &numInstrucciones); 

    if (numInstrucciones > NUM_INSTRUCCIONES || numInstrucciones <= 0) {
        printf("Número de instrucciones fuera de rango.\n");
        return 1; 
    }

    // Leer las instrucciones 
    for (int i = 0; i < numInstrucciones; i++) { 
        printf("Ingrese instrucción %d: ", i + 1); 
        scanf("%s", instrucciones[i]); 
    }

    // Simulación del pipeline 
    for (int ciclo = 0; ciclo < numInstrucciones + NUM_ETAPAS - 1; ciclo++) { 
        for (int i = 0; i < NUM_ETAPAS; i++) { 
            if (ciclo - i >= 0 && ciclo - i < numInstrucciones) { 
                strcpy(pipeline[i], instrucciones[ciclo - i]); 
            } else {
                strcpy(pipeline[i], "N/A"); 
            }
        }
        mostrarPipeline(pipeline, ciclo + 1); 
    }

    return 0; 
}
