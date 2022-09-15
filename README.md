# EP1_PCS3111

Foi pedido para implementar um emulador de uma versão simplificada de um microprocessador MIPS. Nesse emulador foi implementado 9 intruções, sendo elas:

- **ADD** (soma dois números)
- **SUB** (subtrai dois números)
- **MULT** (multiplica dois números)
- **DIV** (divide dois números)
- **J** (altera o PC \[program counter\] para um determinado valor)
- **BNE** (verifica se dois valores são iguais, se sim, altera o pc para um valor especificado)
- **BEQ** (verifica se dois valores são diferentes, se sim, altera o pc para um valor especificado)
- **LW** (carrega um valor da memoria e coloca em um registrador)
- **SW** (armazena na memoria o valor de um registrador)

também foi implementado uma interfase para explorar os registradores, memoria e rodar o programa (gravado no arquivo `main.cpp`) etapa por etapa.

## Testar

para testar o programa basta compilar todos os arquivos .cpp e executar.

```bash
# na pasta com os arquivos .cpp
g++ *.cpp -o main.exe
main.exe
```
