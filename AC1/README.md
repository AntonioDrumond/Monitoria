# Arquitetura de Computadores 1

## Boas fontes para estudar
- [Repositório de Arquitetura 1 - Raquel Motta](https://github.com/raksmotta/ARQ-COMP-1) -> Resumos e provas antigas do professor Cláudio

## Sumário
- [Mapa de Karnaugh](#Mapa-de-Karnaugh)
- [Universalidade das portas NAND e NOR](#Universalidade-das-portas-NAND-e-NOR)

## Mapa de Karnaugh

### 1) Montar o mapa

- Mapa de 3 variáveis
<img src="./img/Montar_Karnaugh1.png">

- Mapa de 4 variáveis
<img src="img/Montar_Karnaugh2.png">

### 2) Montar grupos

- Queremos priorizar, nessa ordem: 
	- Menor número de grupos possível
	- Grupos grandes
	- Minimizar redundâncias (Sobreposição de grupos)
- Lembrar que grupos devem ser:
	- Retangulares (Sem formatos estranhos ou curvas)
	- Conter como número de elementos uma potência de 2 (1, 2, 4, 8...)

<img src="./img/Karnaugh_Grupos1.png">

### 3) Montar a expressão a partir dos grupos
- Note que houve uma sobreposição entre os grupos. Isso não é um problema. Se fosse possível formar uma dupla com o mintermo 2 sem sobrepor a quadra, isso seria ideal.
- Agora, extraímos sub-expressões a partir dos grupos. Identificamos as variáveis que fazem parte da sub-expressão identificando as variáveis que são *relevantes* ao grupo
	- Uma variável é relevante quando ela "não muda" no grupo.
	- Por exemplo, na quadra da imagem, as variáveis X e Y não são relevantes à quadra.
- Agora que sabemos as variáveis relevantes, anotaremos elas como "normais" ou "negadas".
	- Se estivermos simplificando por Mintermos, variáveis de valor 1 serão "normais" e as de valor 0 serão "negadas". Se estivermos simplificando por Maxtermos, fazemos o oposto.
	- Se estivermos simplificando por Mintermos, organizaremos as sub-expressões como uma soma de produtos. Se estivermos simplificando por Maxtermos, organizaremos como um produto de somas.
- Da quadra roxa, podemos extrair a sub-expressão: `Z`
- Da dupla laranja, podemos extrair a sub-expressão: `X'.Y`
- Logo, a expressão final é `Z + (X' . Y)`

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
