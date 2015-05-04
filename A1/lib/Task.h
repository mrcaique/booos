/*
 * Task.h
 */

#ifndef TASK_H_
#define TASK_H_

#include "Queue.h"
#include <ucontext.h>

namespace BOOOS {

/*!
 * Classe Task (tarefa) que representa o Process Control
 * Block (PCB). Aqui, a principal função é representar
 * a troca de contexto entre processos em nível usuário.
 *
 * @see: Task::pass_to()
 */
class Task : public Queue::Element {
public:
	enum State {
		READY,
		WAITING,
		RUNNING,
		FINISHING
	};

	/*!
	 * Construtor
	 *
	 * @param (*entry_pont)(void) função genérica
	 * @param nargs número de argumentos para a função
	 * @param arg argumentos a ser adicionados à função
	 */
	Task(void (*entry_point)(void), int nargs, void * arg);

	Task(void (*entry_point)(void*), int nargs, void * arg);

	/*!
	 * Destrutor
	 */
	virtual ~Task();

	/*!
	 * Retorna o Task ID
	 */
	int tid() { return _tid; }

	/*!
	 * Retorna o estado do processo
	 */
	State state() { return _state; }

	/*!
	 * O método salva o contexto do objeto (this) e carrega o
	 * contexto da Task t. O estado em 's' é o novo estado do
	 * objeto que está deixando a CPU. A variável estática
	 * __running será atualizada
	 *
	 * @param t Tarefa que passará a assumir a CPU
	 * @param s O estado do processo que deixará a CPU
	 */
	void pass_to(Task * t, State s = READY);

	/*!
	 * Finaliza a Task (this) e configura o valor de resultado
	 * da task com o valor de code
	 *
	 * @param code O novo valor de resultado da Task
	 */
	void exit(int code);

	/*!
	 * Método de classe (static) que retorna a Task executando
	 * no momento
	 */
	static Task * self() { return (Task*) __running; }

	/*!
	 * Método a ser chamado para a incialização do sistema
	 */
	static void init();

private:
	Task();  //!< Construtor
	static volatile Task * __running;  //!< Task que esta sendo
					//!< executada no momento
	static Task * __main;  //!< Task principal
	State _state;  //!< estado da Task
	int _tid; //!< task ID
	static int _tid_counter;  //!< O número de tasks
	char* _stack;  //!< A pilha associada a cada Task
	static int STACK_SIZE;  //!< O tamanho máximo da pilha
	ucontext_t context;  //!< contexto da Task em questão
};

} /* namespace BOOOS */

#endif /* TASK_H_ */
