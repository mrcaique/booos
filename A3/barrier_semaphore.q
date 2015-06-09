//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*
Guarantee mutual exclusion between Process(2) and Process(3)
*/
A[] not (Process(2).criticalRegion and Process(3).criticalRegion)

/*
Guarantee mutual exclusion between Process(1) and Process(3)
*/
A[] not (Process(1).criticalRegion and Process(3).criticalRegion)

/*
Guarantee mutual exclusion between Process(1) and Process(2)
*/
A[] not (Process(1).criticalRegion and Process(2).criticalRegion)

/*
Guarantee mutual exclusion between Process(0) and Process(3)
*/
A[] not (Process(0).criticalRegion and Process(3).criticalRegion)

/*
Guarantee mutual exclusion between Process(0) and Process(2)
*/
A[] not (Process(0).criticalRegion and Process(2).criticalRegion)

/*
Guarantee mutual exclusion between Process(0) and Process(1)
*/
A[] not (Process(0).criticalRegion and Process(1).criticalRegion)

/*

*/
A[] not deadlock
