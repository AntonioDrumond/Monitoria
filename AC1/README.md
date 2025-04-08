# Arquitetura de Computadores 1

## Mapa de Karnaugh

### Montar o mapa

- Mapa de 3 variáveis
<img href="./img/Montar_Karnaugh1.png">

- Mapa de 4 variáveis
<img href="img/Montar_Karnaugh2.png">


## Universalidade das portas NAND e NOR

### Lei de DeMorgan

- `( a . b )' = ( a' + b' )`
- `( a + b . c' )' = a' . ( b' + c)`
  Para aplicar a Lei de DeMorgan, basta inverter os sinais de todas as variáveis e trocar ANDs por ORs, e vice versa.

### Aplicando às portas NAND e NOR

Primeiro, negamos duas vezes a porta que desejamos obter.

- `( a . b ) = ( a . b )''`

Depois, utilizamos a Lei de DeMorgan para aplicar uma das negações:

- `( a . b )'' = ( a' + b' )'`

Como temos `(X+Y)'`, podemos reconhecer a porta NOR (Pois há uma operação OR negada)

Logo, para obter a porta AND a partir de NORs, basta negar os inputs da NOR

**Deduções de todas as portas no arquivo [Portas_Com_NAND_e_NOR.circ](./Portas_Com_NAND_e_NOR.circ)**
