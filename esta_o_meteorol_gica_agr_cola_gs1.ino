// Carrega a Biblioteca LiquidCrystal
#include <LiquidCrystal.h>

// Define os pinos que serão utilizados para ligação ao display
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

// Define os pinos dos sensores
int sensorLuzPino = A0;
int sensorTempPino = A1;
int sensorUmidadePino = A2;
int sensorVento = A3;

// Variáveis globais para armazenar as somas e contadores
int somaVento = 0;
int somaLuz = 0;
float somaTemp = 0;
int somaUmidade = 0;
int contadorLeituras = 0;

void setup()
{
  // Inicializa o LCD com 16 colunas por 2 linhas
  LCD.begin(16, 2);

  // Limpa o conteúdo do LCD
  LCD.setCursor(0, 0);
  LCD.print("                ");
  LCD.setCursor(0, 1);
  LCD.print("                ");
}

void loop()
{
  // Realiza as leituras dos sensores
  int luz = analogRead(sensorLuzPino);
  float tempSemConversao = analogRead(sensorTempPino);
  int umidadeSemConversao = analogRead(sensorUmidadePino);
  int velocidadeVentoSemConversao = analogRead(sensorVento);
  
  // Realiza as conversões
  float tensaoTemp = (tempSemConversao / 1024.0) * 5;
  float temp = (tensaoTemp - 0.5) * 100;
  int umidade = map(umidadeSemConversao, 0, 1023, 0, 100);
  int velocidadeVento = map(velocidadeVentoSemConversao, 0, 1023, 0, 150);
  
  // Soma os valores lidos dos sensores
  somaLuz += luz;
  somaTemp += temp;
  somaUmidade += umidade;
  somaVento += velocidadeVento;

  contadorLeituras++;

  // Verifica se já foram realizadas as 5 leituras
  if (contadorLeituras == 5)
  {
    // Calcula as médias das leituras
    int mediaLuz = somaLuz / 5;
    float mediaTemp = somaTemp / 5;
    int mediaUmidade = somaUmidade / 5;
    int mediaVelocidadeVento = somaVento / 5;

    // Reseta as variáveis de soma e contador
    somaLuz = 0;
    somaTemp = 0;
    somaUmidade = 0;
    contadorLeituras = 0;

    // Exibe a média da temperatura no LCD
    LCD.setCursor(0, 0);
    LCD.print("Temperatura");
    LCD.setCursor(0, 1);
    LCD.print(mediaTemp);
    LCD.print(" C");
    
    // Aguarda 3 segundos
	  delay(3000);
    limpaLCD();
    
    // Exibe a média da umidade no LCD
    LCD.setCursor(0, 0);
    LCD.print("Umidade");
    LCD.setCursor(0, 1);
    LCD.print(mediaUmidade);
    LCD.print("%");
    
    delay(3000);
    limpaLCD();
    
    // Exibe a média da velocidade do vento no LCD
    LCD.setCursor(0, 0);
    LCD.print("Velocidade Vento");
    LCD.setCursor(0, 1);
    LCD.print(mediaVelocidadeVento);
    LCD.print(" Km/h");
    
    delay(3000);
    limpaLCD();
    
    // Exibe a média da radiação solar no LCD
    LCD.setCursor(0, 0);
    LCD.print("Radiacao solar");
    LCD.setCursor(0, 1);
    LCD.print(mediaLuz);
    LCD.print(" W/m2");
    
    delay(3000);
    limpaLCD();
    
    // Reseta as variáveis de soma e contador novamente
    somaLuz = 0;
    somaTemp = 0;
    somaUmidade = 0;
    somaVento = 0;
    contadorLeituras = 0;
    
    // Aguarda 5 segundos
    delay(5000);
  }
}

// Limpa o conteúdo do LCD
void limpaLCD(){
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("                ");
    LCD.setCursor(0, 1);
    LCD.print("                ");
}
