#include <stdio.h> 
#include <string.h> 

#define NUM_INSTRUCCIONES 5 
#define NUM_ETAPAS 5 

// Estructura para representar una instrucción 
typedef struct { 
    char nombre[20]; 
    int cicloInicio; 
} Instruccion; 

// Función para mostrar el estado del pipeline 
void mostrarPipeline(Instruccion pipeline[NUM_ETAPAS], int ciclo) { 
    printf("Ciclo %d:\n", ciclo); 
    for (int i = 0; i < NUM_ETAPAS; i++) { 
        if (pipeline[i].cicloInicio == ciclo) { 
            printf("Etapa %d: %s\n", i + 1, pipeline[i].nombre); 
        } else { 
            printf("Etapa %d: N/A\n", i + 1); 
        }
    }
    printf("\n");
}

// Función para simular el pipeline 
void simularPipeline(Instruccion instrucciones[NUM_INSTRUCCIONES]) { 
    Instruccion pipeline[NUM_ETAPAS] = {0}; 
    int ciclo; 
    
    for (ciclo = 0; ciclo < NUM_INSTRUCCIONES + NUM_ETAPAS - 1; ciclo++) { 
        // Actualizar el pipeline 
        for (int i = 0; i < NUM_ETAPAS; i++) { 
            if (ciclo - i >= 0 && ciclo - i < NUM_INSTRUCCIONES) { 
                // Verificar dependencia 
                if (i > 0 && strcmp(instrucciones[ciclo - i].nombre, "LOAD") == 0) { 
                    // Simulación de dependencia: LOAD no puede ser seguido inmediatamente por ADD
                    if ((ciclo - i + 1) < NUM_INSTRUCCIONES && strcmp(instrucciones[ciclo - i + 1].nombre, "ADD") == 0) {
                        pipeline[i] = (Instruccion){"N/A", ciclo}; // Espera 
                    } else { 
                        pipeline[i] = instrucciones[ciclo - i]; 
                    }
                } else { 
                    pipeline[i] = instrucciones[ciclo - i]; 
                }
            } else { 
                pipeline[i] = (Instruccion){"N/A", 0}; 
            }
        }
        mostrarPipeline(pipeline, ciclo + 1);
    }
}

int main() { 
    // Definición de instrucciones 
    Instruccion instrucciones[NUM_INSTRUCCIONES] = { 
        {"LOAD", 0}, 
        {"ADD", 0}, 
        {"SUB", 0}, 
        {"LOAD", 0}, 
        {"MUL", 0} 
    }; 

    // Simular el pipeline 
    simularPipeline(instrucciones); 

    return 0;  
}
