//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*
Ensure of non-occurence of deadlock
*/
A[] not deadlock

/*
Ensure mutual exclusion
*/
A[] forall (i:int[0,nProcess-1]) forall (j:int[0,nProcess-1]) Worker(i).criticalRegion and Worker(j).criticalRegion imply i == j
