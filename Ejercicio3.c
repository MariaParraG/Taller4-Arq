#include <stdio.h> 

// Prototipo de la función
int dividir(int a, int b);

int dividir(int a, int b) { 
    if (b == 0) { 
        printf("Error: División por cero.\n"); 
        return -1; // Indica error 
    }
    return a / b; 
}

int main() { 
    int num1, num2; 
    
    printf("Ingrese el numerador: "); 
    scanf("%d", &num1);
    
    printf("Ingrese el denominador: "); 
    scanf("%d", &num2); 
    
    int resultado = dividir(num1, num2); 
    
    if (resultado != -1) { 
        printf("Resultado: %d\n", resultado); 
    }
    
    return 0; 
}
