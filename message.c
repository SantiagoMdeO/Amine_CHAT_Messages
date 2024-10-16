#define JUGADORES 4
#define JUGADAS 15

int turno[JUGADORES];

void jugador(int i){
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
	
	// Inicia buzones
	for(i = 0; i < JUGADORES; i++){
		initmsj(&turno[i], 0);
	}
	
	send(turno[i]); // manda turno
	
	for(i = 0; i < JUGADORES; i++){
		p = fork();
		if (p == 0){
			jugador(i);
		}
}
	// espera a que todos terminen
	for(i = 0; i <JUGADORES; i++) {
		wait(NULL);
	}
	return 0;
}
