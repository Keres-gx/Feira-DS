#include <Servo.h>

Servo s1, s2, s3, s4;

// posições iniciais (ajuste se quiser)
int base = 90;
int altura = 90;
int mao = 90;
int garra = 90;

void setup() {
  Serial.begin(9600);
  
  s1.attach(3);  // Base
  s2.attach(4);  // Altura
  s3.attach(5);  // Mão
  s4.attach(6);  // Garra
  
  Serial.println("Controle de braço robótico iniciado!");
}

void loop() {
  if (Serial.available()) {
    char comando = Serial.read();

    switch (comando) {
      // Base (esquerda / direita)
      case 'L': base += 5; break;
      case 'R': base -= 5; break;

      // Altura (sobe / desce)
      case 'U': altura += 5; break;
      case 'D': altura -= 5; break;

      // Mão (ângulo do punho)
      case 'Q': mao += 5; break;
      case 'E': mao -= 5; break;

      // Garra (abrir / fechar)
      case 'Z': garra += 5; break;
      case 'X': garra -= 5; break;
    }

    // Limitar ângulos de 0 a 180
    base = constrain(base, 0, 180);
    altura = constrain(altura, 0, 180);
    mao = constrain(mao, 0, 180);
    garra = constrain(garra, 0, 180);

    // Atualiza servos
    s1.write(base);
    s2.write(altura);
    s3.write(mao);
    s4.write(garra);

    delay(12); // movimentação mais suave
  }
}
