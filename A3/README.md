#Barreira (sincronização) - solução em semáforos
Este arquivo tem como objetivo simular o problema da barreira, que consiste em n trabalhadores (worker) e um coordenador (coordinator). Dado o sinal do coordenador, n trabalhadores começam a trabalhar e concluem o serviço, esperando a próxima tarefa. 

Após a conclusão da tarefa pelo último trabalhador, o coordenador dará um novo sinal de início de trabalho aos trabalhadores que estavam esperando por um novo serviço e, quando todos concluírem, o coordenador dará um novo sinal e assim sucessivamente.

A solução do problema da barreira é baseada no seguinte algoritmo:
    
    int nProcess = n; // Número de processos trabalhadores

    Worker(int pid) {
		while(i < iterations) {
			mutex.wait();
			// Trabalho
			mutex.signal();
		
			finish.signal();
			barrier.wait();
			// Espera próximo serviço
		}
    }

    Coordinator() {
		while(i < iterations) {
			for (int i = 0; i < nProcess; i++) { 
				finish.wait(); 
			}
			for (int i = 0; i < nProcess; i++) { 
				barrier.signal(); 
			}
		}
    }

Notas: 
1) Esta simulação foi feita com o auxílio da ferramenta Uppaal (http://www.uppaal.com/), versão 4.0.14 (revisão 5615) - maio de 2014.

2) A implementação do template Semaphore assim como as suas declaraçoes locais não são de minha autoria. O template é de autoria de Frits Vaandrager da Radboud University Nijmegen (http://cs.ru.nl/~fvaan/PC/uppaal/semaphores.html).
