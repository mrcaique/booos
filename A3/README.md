Problema da Barreira - solução em semáforos

Este arquivo do Uppaal tem como objetivo simular o problema
da barreira com a solução em semáforos. O problema consiste em 
dados n processos e em um certo momento do código, os processos
que ali chegarem tem de esperar os outros tambem chegarem ao 
ponto, numa barreira, onde, após o último processo chegar neste
ponto, todos os processos podem continuar o percurso.

Esta simulação é baseada no seguinte algoritmo de solução do
problema da barreira:

int nProcess = n;  //!< Número de processos
int count = 0;

mutex.wait();
count = count + 1;  //!< Seção crítica

if (count == nProcess) {
	mutex.signal();
	barrier.signal(nProcess);
} else {
	mutex.signal();
	barrier.wait();
}

Nota: Esta simulação foi feita com o auxílio da ferramenta Uppaal 
(http://www.uppaal.com/), versão 4.0.14 (revisão 5615) - maio de 2014.