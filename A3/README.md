##Barrier (synchronization) - semphores solution
This file aims to simulate the problem of the barrier, which consists of n workers and a coordinator. Given the coordinator's signal, n workers begin to work and conclude the service, waiting for the next task.

Upon completion of the task by the last worker, the coordinator will give a new start signal to workers who were waiting for a new service and, when all complete, the coordinator will give a new signal and so on.

The solution is based on the following algorithm:

    int nProcess = n; // Number of worker processess

    Worker(int pid) {
		while(i < iterations) {
			mutex.wait();
			// work
			mutex.signal();
		
			finish.signal();
			barrier.wait();
			// Wait next service
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

Notes:

***1)*** This simulation was performed with the aid of [Uppaal] (http://www.uppaal.org/) tool, version 4.0.14 (revision 5615) - may 2014.

***2)*** The implementation of Semaphore template as well as their local declarations are not of my own. The template it is authored by [Frits Vaandrager] (http://cs.ru.nl/~fvaan/PC/uppaal/semaphores.html) from Radboud University Nijmegen.
