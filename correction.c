#define JUGADORES 4
#define JUGADAS 15

int turno[JUGADORES];

void jugador(int* x){
  int i = *x;
	int next = (i + 1) % JUGADORES; //siguiente jugador
	int jugadas = JUGADAS; 
	
	while(jugadas --){
		receive(turno[i]); //bloqueante
		JUGADOR_JUEGA
		send(turno[next]); // no bloqueante
	}
	exit(0);
}

int main()
{
	int i;
	int p;
  int list[JUGADORES]
	
	// Inicia buzones
	for(i = 0; i < JUGADORES; i++){
		initmsj(&turno[i], 0);
	}
	
	send(turno[i]); // manda turno
	
	for(i = 0; i < JUGADORES; i++){
		p = fork();
    list[i] = i;
		if (p == 0){
      //agregamos esto por miedo de que dos jugdores obtuvieran el mismo turno
			jugador(&list[i]);
		}
}
	// espera a que todos terminen
	for(i = 0; i <JUGADORES; i++) {
		wait(NULL);
	}
	return 0;
}
