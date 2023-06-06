# Projeto de Monitoramento de Condições Ambientais

Este projeto tem como objetivo monitorar e exibir informações sobre as condições ambientais, como temperatura, umidade, velocidade do vento e radiação solar. O monitoramento é realizado utilizando um Arduino e um display LCD.

## Componentes Utilizados

- Arduino
- Display LCD 16x2
- Sensor de Luz
- Sensor de Temperatura
- Sensor de Umidade
- Sensor de Velocidade do Vento

## Bibliotecas Utilizadas

- LiquidCrystal

## Pinagem

Os pinos utilizados para a ligação do display LCD são:

- RS (Register Select): 12
- E (Enable): 11
- D4: 5
- D5: 4
- D6: 3
- D7: 2

Os pinos dos sensores estão definidos da seguinte forma:

- Sensor de Luz: A0
- Sensor de Temperatura: A1
- Sensor de Umidade: A2
- Sensor de Velocidade do Vento: A3

## Variáveis Globais

- `somaVento`: Variável utilizada para armazenar a soma das leituras de velocidade do vento.
- `somaLuz`: Variável utilizada para armazenar a soma das leituras de radiação solar.
- `somaTemp`: Variável utilizada para armazenar a soma das leituras de temperatura.
- `somaUmidade`: Variável utilizada para armazenar a soma das leituras de umidade.
- `contadorLeituras`: Variável utilizada para contar o número de leituras realizadas.

## Configuração Inicial

No método `setup()`, é realizada a configuração inicial do projeto. O tamanho do display LCD é definido como 16 colunas por 2 linhas. As linhas do display são limpas, preenchendo-as com espaços em branco.

## Loop Principal

No método `loop()`, é realizado o loop principal do projeto. As leituras dos sensores são realizadas e convertidas para as unidades correspondentes. As leituras são somadas às variáveis globais e o contador de leituras é incrementado.

Quando o contador de leituras atinge o valor de 5, são calculadas as médias das leituras e os valores médios são exibidos no display LCD durante 3 segundos para cada informação: temperatura, umidade, velocidade do vento e radiação solar.

Após a exibição de todas as informações, as variáveis de soma e o contador de leituras são resetados. O processo se repete a cada 5 segundos.

## Função de Limpeza do Display

A função `limpaLCD()` é responsável por limpar o display LCD. Ela utiliza o método `clear()` para limpar o display e posiciona o cursor nas posições iniciais das linhas, preenchendo-as com espaços em branco.

