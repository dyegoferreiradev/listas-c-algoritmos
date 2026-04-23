char side = 'D'; // Variável para armazenar o lado atual do robô
void algorithm(){
    // Verifica se há um objeto muito próximo (menor que 15.5 cm) detectado pelo sensor ultrassônico
    if(ultrassonicRead() < 15.5){
        stop(); // Para o robô
        delay(600); // Aguarda 600 milissegundos
        turnRightMiddleRobot(55); // Faz o robô virar à direita com uma curva de 55 graus
        delay(800); // Aguarda 800 milissegundos (diagonal)

        stop(); // Para o robô
        delay(300); // Aguarda 300 milissegundos
        forward(55); // Move o robô para frente com uma velocidade de 55
        delay(700); // Aguarda 700 milissegundos

        stop(); // Para o robô
        delay(600); // Aguarda 600 milissegundos
        turnLeftMiddleRobot(55); // Faz o robô virar à esquerda com uma curva de 55 graus
        delay(750); // Aguarda 750 milissegundos (pra frente)

        stop(); // Para o robô
        delay(300); // Aguarda 300 milissegundos
        forward(55); // Move o robô para frente com uma velocidade de 55
        delay(1000); // Aguarda 1000 milissegundos

        stop(); // Para o robô
        delay(600); // Aguarda 600 milissegundos
        turnLeftMiddleRobot(55); // Faz o robô virar à esquerda com uma curva de 55 graus
        delay(800); // Aguarda 800 milissegundos (diagonal)

        stop(); // Para o robô
        delay(300); // Aguarda 300 milissegundos
        forward(55); // Move o robô para frente com uma velocidade de 55

        // Enquanto o robô não permanecer na linha preta
        while(!stayOnBlackLine()){}
        stop(); // Para o robô
        delay(200); // Aguarda 200 milissegundos
        side = 'D'; // Define o lado do robô como 'D' (direita)
        turnLeft(62); // Faz o robô virar à esquerda com uma curva de 62 graus
    }

    // Se o lado atual do robô for direita
    if(side == 'D'){
        turnRight(62); // Faz o robô virar à direita com uma curva de 62 graus
    }
    // Se o lado atual do robô for esquerda
    else if(side == 'E'){
        turnLeft(62); // Faz o robô virar à esquerda com uma curva de 62 graus
    }

    // Se o robô permanecer na linha preta
    if(stayOnBlackLine()){
        // Enquanto o robô permanecer na linha preta
        while(stayOnBlackLine()){}
            delay(100); // Aguarda 100 milissegundos
        // Se o lado atual do robô for direita
        if(side == 'D'){
            turnLeft(62); // Faz o robô virar à esquerda com uma curva de 62 graus
            side = 'E'; // Define o lado do robô como 'E' (esquerda)
        } 
        // Se o lado atual do robô for esquerda
        else if(side == 'E'){
            turnRight(62); // Faz o robô virar à direita com uma curva de 62 graus
            side = 'D'; // Define o lado do robô como 'D' (direita)
        }
    }
}
