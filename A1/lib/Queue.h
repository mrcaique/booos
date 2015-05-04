/*
 * BOOOS.h
 *
 */

#ifndef QUEUE_H_
#define QUEUE_H_

/*!
 * Queue é uma implementação de uma fila duplamente
 * encadeada circular. A fila tem um elemento sentinela,
 * chamado de head (cabeça) que aponta para o "primeiro"
 * (next) e "último" (previous) elemento da lista.
 */
namespace BOOOS {

        class Queue {
        public:
		/*!
		 * Construtor da fila
		 */
                Queue();
		/*!
		 * Destrutor da fila
		 */
                virtual ~Queue();

/*!
 * Um elemento (Element) de uma fila duplamente encadeada
 * circular são interligados de forma que pode ver tanto
 * o elemento posterior a este, quanto o anterior. Como é
 * circular, o "último" elemento tem como próximo elemento
 * o primeiro da fila, ou seja, o que é apontado como next
 * pelo head
 */
                class Element {
                public:
			/*!
			 * Construtor de elemento
			 */
                        Element() { _prev = 0; _next = 0; _rank = 0; }
			/*!
			 * Destrutor de elemento
			 */
                        virtual ~Element() {}

			/*!
			 * Retorna o próximo elemento da fila
			 */
                        Element * prev() { return _prev; }

			/*!
			 * Retorna o elemento anterior da fila
			 */
                        Element * next() { return _next; }
                        int rank() { return _rank; }

			/*!
			 * Seta o elemento anterior da fila com o valor
			 * especificado no parâmentro
			 *
			 * @param p Elemento anterior a ser adicionado
			 */
                        void prev(Element * p) { _prev = p; }

			/*!
			 * Seta o próximo elemento da fila com o valor
			 * especificado no parâmetro
			 *
			 * @param p Próximo elemento a ser adicionado
			 */
                        void next(Element * p) { _next = p; }
                        void rank(int r) { _rank = r; }

                private:
                        Element * _prev;  //!< Elemento anterior
                        Element * _next;  //!< Elemento posterior
                        int _rank;
                };

		/*!
		 * Retorna o elemento sentinela (head) da fila
		 */
                Element * head() { return &_head; }

		/*!
		 * Retorna o tamanho atual da fila
		 */
                int length() { return _length; }

		/*!
		 * Insere um novo elemento à fila, no "final",
		 * ou seja, onde head aponta como anterior (prev)
		 *
		 * @param elem Novo elemento a ser adicionado
		 */
                void insert(Element * elem);
                void insert_ordered(Element * elem);

		/*!
		 * Remove um elemento da fila, o "primeiro",
		 * isto é, onde head aponta como próximo (next)
		 */
                Element * remove();
                void remove(Element * e);

        private:
                Element * search(Element * elem);

                Element _head; // _head.next will point to head, _head.prev will point to tail
                int _length;  //!< Tamanho atual da fila (número de elementos)
        };

}

#endif /* QUEUE_H_ */
